#define STATUS_LED_PIN 8

// Activo en bajo: LOW enciende, HIGH apaga
void setStatusLed(bool on) {
  digitalWrite(STATUS_LED_PIN, on ? LOW : HIGH);
}
