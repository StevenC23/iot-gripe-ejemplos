uint8_t BROADCAST[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

struct Mensaje {
  uint8_t destino[6];   // MAC del nodo que debe actuar
  uint8_t comando;
};

void enviarA(const uint8_t *mac, uint8_t comando) {
  Mensaje m;
  memcpy(m.destino, mac, 6);
  m.comando = comando;
  esp_now_send(BROADCAST, (uint8_t *)&m, sizeof(m));
}
