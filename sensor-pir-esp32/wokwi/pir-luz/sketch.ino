// Sensor PIR que enciende una luz y la apaga tras un tiempo sin movimiento.
// En Wokwi el sensor no necesita estabilizarse y los tiempos se acortan para probar rápido:
// en la placa real usa delay(60000) en setup() y TIEMPO_ENCENDIDA_MS = 60000.
#define PIR_PIN 4
#define LUZ_PIN 8                  // LED del ESP32-C3 Super Mini (activo en bajo)
#define LUZ_ACTIVA_EN_BAJO true
const unsigned long TIEMPO_ENCENDIDA_MS = 10000;  // 10 s en el simulador

unsigned long ultimoMovimiento = 0;
bool luzEncendida = false;

void aplicarLuz(bool encendida) {
  bool nivel = LUZ_ACTIVA_EN_BAJO ? !encendida : encendida;
  digitalWrite(LUZ_PIN, nivel ? HIGH : LOW);
  luzEncendida = encendida;
}

void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
  pinMode(LUZ_PIN, OUTPUT);
  aplicarLuz(false);
  Serial.println("Esperando a que el sensor se estabilice...");
  delay(1000);
  Serial.println("Listo: pulsa el sensor PIR para simular movimiento");
}

void loop() {
  if (digitalRead(PIR_PIN) == HIGH) {
    if (!luzEncendida) Serial.println("Movimiento: luz encendida");
    ultimoMovimiento = millis();  // cada detección reinicia el tiempo
    aplicarLuz(true);
  }

  if (luzEncendida && millis() - ultimoMovimiento > TIEMPO_ENCENDIDA_MS) {
    Serial.println("Sin movimiento: luz apagada");
    aplicarLuz(false);
  }

  delay(50);
}
