#include <ModbusRTU.h>

#define DE_RE 4
ModbusRTU mb;

void setup() {
  Serial2.begin(9600, SERIAL_8N1, 16, 17);
  mb.begin(&Serial2, DE_RE);     // segundo parámetro: pin DE/RE
  mb.slave(1);                   // dirección del esclavo
  mb.addHreg(0, 0, 4);           // 4 holding registers desde la dirección 0
}

void loop() {
  mb.Hreg(0, (uint16_t)(analogRead(34)));   // publica una lectura en el registro 0
  mb.task();                                // atiende las peticiones
  delay(10);
}
