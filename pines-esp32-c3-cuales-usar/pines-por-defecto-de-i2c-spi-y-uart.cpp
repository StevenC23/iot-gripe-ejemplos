#include <Wire.h>

void setup() {
  Wire.begin(8, 9);   // SDA, SCL explícitos
}
