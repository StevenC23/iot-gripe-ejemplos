const int SENSOR = 34;   // ADC1_6: válido con Wi-Fi

void loop() {
  int lectura = analogRead(SENSOR);   // 0 a 4095
  Serial.println(lectura);
  delay(500);
}
