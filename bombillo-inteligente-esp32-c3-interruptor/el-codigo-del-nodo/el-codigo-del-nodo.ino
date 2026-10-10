#define PIN_INTERRUPTOR 10
#define PIN_SALIDA      8    // LED del C3 Super Mini; en la versión final, el pin del relé
#define ANTIRREBOTE_MS  50

bool encendido = false;
int ultimaLectura = HIGH;
int lecturaEstable = HIGH;
unsigned long cambioEn = 0;

void aplicar(bool on) {
  encendido = on;
  digitalWrite(PIN_SALIDA, on ? LOW : HIGH);  // el LED del C3 Super Mini es activo en bajo
}

void setup() {
  Serial.begin(115200);
  pinMode(PIN_SALIDA, OUTPUT);
  aplicar(false);
  pinMode(PIN_INTERRUPTOR, INPUT_PULLUP);
  ultimaLectura = lecturaEstable = digitalRead(PIN_INTERRUPTOR);  // la posición inicial no cuenta
  // ... ESP-NOW como en la parte 4
}

void revisarInterruptor() {
  int lectura = digitalRead(PIN_INTERRUPTOR);
  if (lectura != ultimaLectura) {   // el contacto se movió (o rebota)
    ultimaLectura = lectura;
    cambioEn = millis();
  }
  if (millis() - cambioEn < ANTIRREBOTE_MS || lectura == lecturaEstable) return;

  lecturaEstable = lectura;          // cambio real y estable
  aplicar(!encendido);               // primero la luz, sin esperar a nadie
  Serial.printf("Interruptor: salida %s\n", encendido ? "encendida" : "apagada");
  avisarAlHub(encendido);            // después avisar, si hay alguien escuchando
}

void loop() {
  revisarInterruptor();
}
