void publicarTelemetria(float temperatura, float humedad) {
  JsonDocument doc;
  doc["temperatura"] = temperatura;
  doc["humedad"] = humedad;
  char buffer[128];
  size_t n = serializeJson(doc, buffer);
  String topico = String("casa-demo/") + THING_NAME + "/telemetria";
  client.publish(topico.c_str(), buffer, n);
}
