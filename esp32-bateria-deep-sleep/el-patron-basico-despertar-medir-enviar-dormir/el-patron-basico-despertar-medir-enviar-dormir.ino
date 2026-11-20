#include <WiFi.h>

const uint64_t DORMIR_SEGUNDOS = 10 * 60;  // 10 minutos

RTC_DATA_ATTR int ciclos = 0;  // sobrevive al sueño profundo (no a un corte de energía)

void setup() {
  Serial.begin(115200);
  ciclos++;
  Serial.printf("Ciclo %d\n", ciclos);

  // 1. Medir el sensor
  // 2. Conectar el Wi-Fi, enviar el dato y desconectar, lo más rápido posible

  esp_sleep_enable_timer_wakeup(DORMIR_SEGUNDOS * 1000000ULL);  // en microsegundos
  Serial.println("A dormir");
  Serial.flush();
  esp_deep_sleep_start();  // a partir de aquí no se ejecuta nada más
}

void loop() {
  // No se llega nunca: el chip vuelve a arrancar desde setup() al despertar
}
