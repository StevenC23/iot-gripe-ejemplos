#include <esp_system.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  esp_reset_reason_t motivo = esp_reset_reason();
  if (motivo == ESP_RST_BROWNOUT) {
    Serial.println("Se reinició por caída de tensión: revisa la fuente y el cable");
  } else {
    Serial.printf("Motivo del último reinicio: %d\n", motivo);
  }
}

void loop() {}
