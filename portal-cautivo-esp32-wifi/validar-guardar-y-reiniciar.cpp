void guardar() {
  String ssid = servidor.arg("ssid");
  String pass = servidor.arg("pass");
  ssid.trim();

  if (ssid.isEmpty() || ssid.length() > 32 || pass.length() > 63) {
    servidor.send(400, "text/plain", "Datos inválidos");
    return;
  }

  prefs.begin("wifi", false);
  prefs.putString("ssid", ssid);
  prefs.putString("pass", pass);
  prefs.end();

  servidor.send(200, "text/html", "<p>Guardado. El dispositivo se reinicia y se conecta a tu red.</p>");
  delay(500);  // deja que la respuesta llegue al celular
  ESP.restart();
}
