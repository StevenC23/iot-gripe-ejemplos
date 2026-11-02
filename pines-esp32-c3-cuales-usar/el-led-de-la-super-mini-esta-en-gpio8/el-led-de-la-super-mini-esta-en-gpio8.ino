const int LED = 8;   // Super Mini: nivel bajo = encendido

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, LOW);    // enciende
  delay(500);
  digitalWrite(LED, HIGH);   // apaga
  delay(500);
}
