#include <WiFi.h>
#include <HTTPClient.h>

void enviarTemperatura(float t) {
  HTTPClient http;
  // En producción, usa HTTPS: http.begin(clienteSeguro, url) con un WiFiClientSecure y su CA
  http.begin("http://tu-servidor.local/api/lecturas");
  http.addHeader("Content-Type", "application/json");
  int codigo = http.POST(String("{\"temperatura\":") + t + "}");
  Serial.printf("Respuesta: %d\n", codigo);
  http.end();
}
