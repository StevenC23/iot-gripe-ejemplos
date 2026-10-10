void reportarCambioLocal(const char* salida, bool on) {
  JsonDocument doc;
  doc["state"]["desired"][salida]  = on ? "on" : "off";
  doc["state"]["reported"][salida] = on ? "on" : "off";
  char buffer[192];
  size_t n = serializeJson(doc, buffer);
  client.publish(topicUpdate.c_str(), buffer, n);
}
