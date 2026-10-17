#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <MQTT.h>
#include "secrets.h"   // certificados y endpoint, fuera del repositorio

WiFiClientSecure red;
MQTTClient mqtt(1024);   // búfer de 1 KB

void conectarAWS() {
  red.setCACert(AWS_CERT_CA);
  red.setCertificate(AWS_CERT_CRT);
  red.setPrivateKey(AWS_CERT_PRIVATE);

  mqtt.begin(AWS_IOT_ENDPOINT, 8883, red);
  mqtt.setKeepAlive(60);

  while (!mqtt.connect(THING_NAME)) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nConectado a AWS IoT");
}

void setup() {
  Serial.begin(115200);
  // ... conectar Wi-Fi
  conectarAWS();
}

void loop() {
  mqtt.loop();
  if (!mqtt.connected()) conectarAWS();

  static uint32_t ultimo = 0;
  if (millis() - ultimo > 10000) {
    ultimo = millis();
    // QoS 1: publish() espera la confirmación (PUBACK) del broker
    bool ok = mqtt.publish("casa/sala/estado", "{\"temp\":22.5}", false, 1);
    Serial.println(ok ? "Confirmado por AWS" : "Sin confirmación");
  }
}
