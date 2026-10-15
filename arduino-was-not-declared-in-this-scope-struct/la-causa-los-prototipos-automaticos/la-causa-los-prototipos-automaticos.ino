#include <Arduino.h>

void setup() {        // primera función: aquí se insertan los prototipos
  Serial.begin(115200);
}

struct Sensor {       // el tipo aparece después
  uint8_t pin;
  float valor;
};

void leerSensor(Sensor &s) {   // su prototipo quedó arriba, antes de Sensor
  s.valor = analogRead(s.pin);
}

void loop() {}
