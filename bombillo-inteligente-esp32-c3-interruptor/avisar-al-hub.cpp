void avisarAlHub(bool on) {
  Mensaje m = { 3, 1, (uint8_t)on, 0 };  // tipo 3 = cambio local, salida 1
  esp_now_send(macHub, (uint8_t*)&m, sizeof(m));
}
