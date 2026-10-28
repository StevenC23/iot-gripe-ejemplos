#include <ModbusMaster.h>

#define RX2 16
#define TX2 17
#define DE_RE 4

ModbusMaster nodo;

void preTransmision()  { digitalWrite(DE_RE, HIGH); }
void postTransmision() { digitalWrite(DE_RE, LOW);  }

void setup() {
  Serial.begin(115200);
  pinMode(DE_RE, OUTPUT);
  digitalWrite(DE_RE, LOW);

  Serial2.begin(9600, SERIAL_8N1, RX2, TX2);
  nodo.begin(1, Serial2);                 // dirección del esclavo
  nodo.preTransmission(preTransmision);
  nodo.postTransmission(postTransmision);
}

void loop() {
  uint8_t r = nodo.readHoldingRegisters(0, 2);   // desde el registro 0, 2 registros
  if (r == nodo.ku8MBSuccess) {
    Serial.printf("R0=%u  R1=%u\n", nodo.getResponseBuffer(0), nodo.getResponseBuffer(1));
  } else {
    Serial.printf("Error Modbus: 0x%02X\n", r);
  }
  delay(2000);
}
