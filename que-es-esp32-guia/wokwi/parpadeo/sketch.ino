#define LED_PIN 2  // cambia al pin del LED de tu placa

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED encendido");
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
