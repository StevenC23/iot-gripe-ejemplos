#include <Preferences.h>

Preferences prefs;

void setup() {
  Serial.begin(115200);

  // Lectura: el segundo parámetro en true abre en modo solo lectura
  prefs.begin("config", true);
  unsigned int arranques = prefs.getUInt("boots", 0);  // 0 si la clave no existe
  prefs.end();

  arranques++;

  // Escritura
  prefs.begin("config", false);
  prefs.putUInt("boots", arranques);
  prefs.end();

  Serial.printf("Este ESP32 ha arrancado %u veces\n", arranques);
}

// Solo en el simulador: reinicia cada 3 s para ver que el contador sobrevive al reinicio
void loop() {
  delay(3000);
  ESP.restart();
}
