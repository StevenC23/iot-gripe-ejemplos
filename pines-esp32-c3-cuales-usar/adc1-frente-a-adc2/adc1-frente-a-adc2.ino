const int PIN_SENSOR = 3;   // ADC1_3: seguro con Wi-Fi activo

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);      // 0 a 4095
}

void loop() {
  int mv = analogReadMilliVolts(PIN_SENSOR);   // aplica la calibración de fábrica
  Serial.println(mv);
  delay(500);
}
