void setup() {}

void loop() {
  neopixelWrite(RGB_BUILTIN, 0, 20, 0);   // verde tenue
  delay(500);
  neopixelWrite(RGB_BUILTIN, 0, 0, 0);    // apagado
  delay(500);
}
