#define RELE_PIN 5
#define RELE_ACTIVO_EN_BAJO true  // cámbialo según tu módulo

void aplicarEstado(bool encendido) {
  bool nivel = RELE_ACTIVO_EN_BAJO ? !encendido : encendido;
  digitalWrite(RELE_PIN, nivel ? HIGH : LOW);
}

void setup() {
  pinMode(RELE_PIN, OUTPUT);
  aplicarEstado(false);  // el estado seguro, lo antes posible
}
