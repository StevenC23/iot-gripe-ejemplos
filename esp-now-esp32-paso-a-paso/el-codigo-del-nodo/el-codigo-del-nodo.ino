// Nodo ESP-NOW: aplica la orden y responde con una confirmación.
#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

#define CANAL    6   // el mismo canal fijo del router
#define LED_PIN  8   // LED del ESP32-C3 Super Mini (activo en bajo); aquí iría el relé

typedef struct __attribute__((packed)) {
  uint8_t tipo, salida, valor;
  uint16_t id;
} Mensaje;

uint8_t macHub[6] = { 0x24, 0x0A, 0xC4, 0x00, 0x00, 0x10 };  // la imprime el hub al arrancar

void alRecibir(const esp_now_recv_info_t* info, const uint8_t* data, int len) {
  if (len != sizeof(Mensaje) || memcmp(info->src_addr, macHub, 6) != 0) return;
  Mensaje m;
  memcpy(&m, data, sizeof(m));
  if (m.tipo != 1) return;

  digitalWrite(LED_PIN, m.valor ? LOW : HIGH);

  m.tipo = 2;  // misma orden, ahora como confirmación de lo que se aplicó
  esp_now_send(macHub, (uint8_t*)&m, sizeof(m));
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);  // apagado al arrancar

  WiFi.mode(WIFI_STA);
  esp_wifi_set_channel(CANAL, WIFI_SECOND_CHAN_NONE);
  Serial.printf("Canal %d. MAC del nodo: %s\n", CANAL, WiFi.macAddress().c_str());

  if (esp_now_init() != ESP_OK) { Serial.println("Error iniciando ESP-NOW"); return; }
  esp_now_register_recv_cb(alRecibir);

  esp_now_peer_info_t peer = {};
  memcpy(peer.peer_addr, macHub, 6);
  peer.channel = 0;
  peer.encrypt = false;
  esp_now_add_peer(&peer);
}

void loop() {
  delay(50);
}
