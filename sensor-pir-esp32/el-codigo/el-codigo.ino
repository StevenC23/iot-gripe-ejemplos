#define PIR_PIN 4
#define LUZ_PIN 8                  // LED del ESP32-C3 Super Mini (activo en bajo)
#define LUZ_ACTIVA_EN_BAJO true
const unsigned long TIEMPO_ENCENDIDA_MS = 60000;  // 1 minuto

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
  delay(60000);
  Serial.println("Listo");
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
