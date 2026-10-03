#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <MQTTClient.h>   // Librería "MQTT" de 256dpi (Joël Gähwiler)
#include <ArduinoJson.h>  // v7
#include "secrets.h"

#define LED_PIN 2  // ajusta al pin de tu placa

WiFiClientSecure net;
MQTTClient client(2048);  // buffer amplio: el documento del Shadow no cabe en el tamaño por defecto

String topicUpdate, topicDelta, topicRejected, topicGet, topicGetAccepted;

void buildTopics() {
  String base = String("$aws/things/") + THING_NAME + "/shadow";
  topicUpdate      = base + "/update";
  topicDelta       = base + "/update/delta";
  topicRejected    = base + "/update/rejected";
  topicGet         = base + "/get";
  topicGetAccepted = base + "/get/accepted";
}

void reportLed(const char* state) {
  JsonDocument doc;
  doc["state"]["reported"]["led"] = state;
  char buffer[128];
  size_t n = serializeJson(doc, buffer);
  client.publish(topicUpdate.c_str(), buffer, n);
}

void applyLed(const char* state) {
  digitalWrite(LED_PIN, strcmp(state, "on") == 0 ? HIGH : LOW);
  reportLed(state);  // confirma a la nube lo que realmente hizo el dispositivo
}

void onMessage(String &topic, String &payload) {
  Serial.printf("[%s] %s\n", topic.c_str(), payload.c_str());
  if (topic == topicRejected) return;  // solo para depurar: AWS explica aquí por qué rechazó un reporte

  JsonDocument doc;
  if (deserializeJson(doc, payload)) return;

  // get/accepted trae el documento completo bajo state.desired;
  // update/delta trae solo la diferencia, directo bajo state
  JsonVariant state = (topic == topicGetAccepted)
                          ? doc["state"]["desired"].as<JsonVariant>()
                          : doc["state"].as<JsonVariant>();

  const char* led = state["led"];
  if (led != nullptr) applyLed(led);
}

void connectWiFi() {
  if (WiFi.status() == WL_CONNECTED) return;
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Conectando a Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" listo");
}

void connectAWS() {
  while (!client.connected()) {
    connectWiFi();
    Serial.print("Conectando a AWS IoT Core... ");
    if (!client.connect(THING_NAME)) {
      Serial.printf("falló (lastError=%d), reintento en 5 s\n", client.lastError());
      delay(5000);
      continue;
    }
    Serial.println("conectado");
    delay(300);  // deja asentar la sesión TLS antes de suscribirse

    client.subscribe(topicDelta.c_str());
    client.subscribe(topicRejected.c_str());
    client.subscribe(topicGetAccepted.c_str());

    // Pide el estado actual en vez de esperar a que llegue un delta
    delay(200);
    client.publish(topicGet.c_str(), "");
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  buildTopics();
  connectWiFi();

  net.setCACert(AWS_CERT_CA);
  net.setCertificate(AWS_CERT_CRT);
  net.setPrivateKey(AWS_CERT_PRIVATE);

  client.begin(AWS_IOT_ENDPOINT, 8883, net);
  client.onMessage(onMessage);
  connectAWS();
}

void loop() {
  client.loop();
  delay(10);
  if (!client.connected()) connectAWS();
}
