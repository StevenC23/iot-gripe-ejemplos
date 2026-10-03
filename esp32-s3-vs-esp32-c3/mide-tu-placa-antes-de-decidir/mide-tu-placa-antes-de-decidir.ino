// Muestra qué chip tienes y cuánta memoria le queda libre.
// Compila igual para ESP32-S3 y ESP32-C3.

#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(2000);  // da tiempo a abrir el Monitor Serie (USB nativo)

  Serial.printf("Chip: %s (revisión %d)\n", ESP.getChipModel(), ESP.getChipRevision());
  Serial.printf("Núcleos: %d a %lu MHz\n", ESP.getChipCores(), ESP.getCpuFreqMHz());
  Serial.printf("Flash: %lu KB\n", ESP.getFlashChipSize() / 1024);
  Serial.printf("RAM libre: %lu KB (bloque más grande: %lu KB)\n",
                ESP.getFreeHeap() / 1024, ESP.getMaxAllocHeap() / 1024);
  Serial.printf("PSRAM: %s\n", psramFound() ? "sí" : "no");
  WiFi.mode(WIFI_STA);  // la MAC de modo estación es la que usa ESP-NOW
  Serial.printf("MAC: %s\n", WiFi.macAddress().c_str());
}

void loop() {
  // Útil después de conectar Wi-Fi, TLS y MQTT: si este número baja
  // sin parar, tienes una fuga de memoria.
  Serial.printf("RAM libre: %lu KB\n", ESP.getFreeHeap() / 1024);
  delay(10000);
}
