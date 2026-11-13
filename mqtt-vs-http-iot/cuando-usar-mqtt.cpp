#include <WiFi.h>
#include <MQTTClient.h>  // librería MQTT de 256dpi

WiFiClient red;          // WiFiClientSecure en producción, con TLS
MQTTClient cliente(512);

void alRecibir(String &topico, String &mensaje) {
  if (topico == "casa/sala/luz") {
    digitalWrite(LED_PIN, mensaje == "on" ? HIGH : LOW);
  }
}

void conectar() {
  cliente.begin("broker.ejemplo", 1883, red);
  cliente.onMessage(alRecibir);
  while (!cliente.connect("esp32-sala")) delay(1000);
  cliente.subscribe("casa/sala/luz");
}

void loop() {
  cliente.loop();  // mantiene la conexión y entrega los mensajes
  if (!cliente.connected()) conectar();
}
