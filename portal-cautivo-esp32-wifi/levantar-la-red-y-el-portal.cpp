void iniciarPortal() {
  modoPortal = true;
  WiFi.mode(WIFI_AP);
  delay(100);  // en algunos chips la MAC del AP no está lista al instante

  String mac = WiFi.softAPmacAddress();  // en modo AP, macAddress() puede devolver ceros
  mac.replace(":", "");
  String nombre = "Casa-Setup-" + mac.substring(mac.length() - 4);
  WiFi.softAP(nombre.c_str());

  // DNS: cualquier dominio apunta al propio ESP32
  dns.start(53, "*", WiFi.softAPIP());

  servidor.on("/", HTTP_GET, paginaFormulario);
  servidor.on("/guardar", HTTP_POST, guardar);
  servidor.onNotFound(paginaFormulario);  // cualquier URL muestra el formulario
  servidor.begin();

  Serial.printf("Portal activo: conéctate a '%s'\n", nombre.c_str());
}
