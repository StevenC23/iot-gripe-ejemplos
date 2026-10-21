const int BOTON = 34;     // solo entrada: necesita resistencia externa

void setup() {
  Serial.begin(115200);
  pinMode(BOTON, INPUT);  // INPUT_PULLUP no funciona en este pin
}

void loop() {
  Serial.println(digitalRead(BOTON));
  delay(200);
}
