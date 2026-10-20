const int PIN_SENSOR = 4;   // ADC1_3: seguro con Wi-Fi activo

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);      // 0 a 4095
}

void loop() {
  int lectura = analogRead(PIN_SENSOR);
  Serial.println(lectura);
  delay(500);
}
