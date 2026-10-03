// Hub ESP-NOW: envía órdenes a un nodo y espera su confirmación.
#include <WiFi.h>
#include <esp_now.h>

#define WIFI_SSID      "tu-red-wifi"
#define WIFI_PASSWORD  "tu-clave-wifi"
#define TIMEOUT_MS     2000

typedef struct __attribute__((packed)) {
  uint8_t tipo, salida, valor;
  uint16_t id;
} Mensaje;

uint8_t macNodo[6] = { 0x24, 0x0A, 0xC4, 0x00, 0x00, 0x01 };  // la imprime el nodo al arrancar

uint16_t siguienteId = 1;
uint16_t idPendiente = 0;        // 0 = no hay orden esperando confirmación
unsigned long enviadoEn = 0;

void enviarOrden(uint8_t valor) {
  Mensaje m = { 1, 1, valor, siguienteId++ };
  esp_now_send(macNodo, (uint8_t*)&m, sizeof(m));
  idPendiente = m.id;
  enviadoEn = millis();
  Serial.printf("-> orden #%u: salida 1 = %u\n", m.id, valor);
}

void alRecibir(const esp_now_recv_info_t* info, const uint8_t* data, int len) {
  if (len != sizeof(Mensaje) || memcmp(info->src_addr, macNodo, 6) != 0) return;  // solo nodos conocidos
  Mensaje m;
  memcpy(&m, data, sizeof(m));
  if (m.tipo == 2 && m.id == idPendiente) {
    Serial.printf("<- confirmación #%u: salida %u = %u (%lu ms)\n", m.id, m.salida, m.valor, millis() - enviadoEn);
    idPendiente = 0;
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) delay(300);
  Serial.printf("Wi-Fi en el canal %d. MAC del hub: %s\n", WiFi.channel(), WiFi.macAddress().c_str());

  if (esp_now_init() != ESP_OK) { Serial.println("Error iniciando ESP-NOW"); return; }
  esp_now_register_recv_cb(alRecibir);

  esp_now_peer_info_t peer = {};
  memcpy(peer.peer_addr, macNodo, 6);
  peer.channel = 0;      // 0 = el canal actual del Wi-Fi
  peer.encrypt = false;
  esp_now_add_peer(&peer);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == '0' || c == '1') enviarOrden(c - '0');
  }
  if (idPendiente && millis() - enviadoEn > TIMEOUT_MS) {
    Serial.printf("!  sin confirmación de la orden #%u\n", idPendiente);
    idPendiente = 0;  // no se asume que el cambio se aplicó
  }
}
