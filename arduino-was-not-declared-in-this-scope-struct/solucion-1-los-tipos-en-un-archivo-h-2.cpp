// sketch.ino
#include "tipos.h"

void leerSensor(Sensor &s) {
  s.valor = analogRead(s.pin);
}
