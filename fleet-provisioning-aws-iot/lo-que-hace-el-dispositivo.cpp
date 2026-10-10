void onMessage(String& topic, String& payload) {
  JsonDocument doc;
  if (deserializeJson(doc, payload)) return;

  if (topic.endsWith("create/json/accepted")) {
    // Guardar en memoria (aún no en NVS) el certificado y la llave
    certNuevo  = doc["certificatePem"].as<String>();
    llaveNueva = doc["privateKey"].as<String>();
    String token = doc["certificateOwnershipToken"].as<String>();

    JsonDocument registro;
    registro["certificateOwnershipToken"] = token;
    registro["parameters"]["NumeroSerie"] = numeroSerie();
    String cuerpo;
    serializeJson(registro, cuerpo);
    client.publish("$aws/provisioning-templates/casa-demo/provision/json", cuerpo);

  } else if (topic.endsWith("provision/json/accepted")) {
    guardarIdentidad(doc["thingName"].as<String>(), certNuevo, llaveNueva);  // ahora sí, a NVS
    ESP.restart();  // vuelve a conectar con su identidad propia

  } else if (topic.endsWith("rejected")) {
    Serial.printf("Rechazado: %s\n", payload.c_str());
  }
}

void aprovisionar() {
  client.subscribe("$aws/certificates/create/json/accepted");
  client.subscribe("$aws/certificates/create/json/rejected");
  client.subscribe("$aws/provisioning-templates/casa-demo/provision/json/accepted");
  client.subscribe("$aws/provisioning-templates/casa-demo/provision/json/rejected");
  client.publish("$aws/certificates/create/json", "{}");
}
