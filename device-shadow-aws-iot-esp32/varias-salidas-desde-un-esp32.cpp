struct Salida {
  const char* nombre;  // clave en el Shadow
  uint8_t pin;
};

Salida salidas[] = {
  { "sala",   4 },
  { "cocina", 5 },
};

void aplicarYReportar(JsonObject cambios) {
  JsonDocument reporte;
  JsonObject reported = reporte["state"]["reported"].to<JsonObject>();

  for (JsonPair kv : cambios) {
    for (Salida& s : salidas) {
      if (strcmp(kv.key().c_str(), s.nombre) != 0) continue;
      bool encender = strcmp(kv.value() | "", "on") == 0;
      digitalWrite(s.pin, encender ? HIGH : LOW);
      reported[s.nombre] = encender ? "on" : "off";  // solo lo que se aplicó
    }
  }
  if (reported.size() == 0) return;  // nada que reportar

  char buffer[512];
  size_t n = serializeJson(reporte, buffer);
  client.publish(topicUpdate.c_str(), buffer, n);
}

void onMessage(String& topic, String& payload) {
  JsonDocument doc;
  if (deserializeJson(doc, payload)) return;

  if (topic == topicDelta) {
    aplicarYReportar(doc["state"].as<JsonObject>());
  } else if (topic == topicGetAccepted) {
    aplicarYReportar(doc["state"]["desired"].as<JsonObject>());
  }
}
