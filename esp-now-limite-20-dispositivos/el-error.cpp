esp_err_t r = esp_now_add_peer(&peer);
if (r != ESP_OK) {
  Serial.printf("add_peer: %s\n", esp_err_to_name(r));
}
