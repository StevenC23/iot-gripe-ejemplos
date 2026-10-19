bool enviarUnicast(const uint8_t *mac, const uint8_t *datos, size_t len) {
  esp_now_peer_info_t peer = {};
  memcpy(peer.peer_addr, mac, 6);
  peer.channel = 0;      // canal actual
  peer.encrypt = false;

  bool registrado = esp_now_is_peer_exist(mac);
  if (!registrado && esp_now_add_peer(&peer) != ESP_OK) return false;

  esp_err_t r = esp_now_send(mac, datos, len);

  if (!registrado) esp_now_del_peer(mac);
  return r == ESP_OK;
}
