void alRecibir(const esp_now_recv_info_t *info, const uint8_t *datos, int len) {
  if (len != sizeof(Mensaje)) return;
  const Mensaje *m = (const Mensaje *)datos;
  if (memcmp(m->destino, miMac, 6) != 0) return;   // no es para mí
  aplicar(m->comando);
}
