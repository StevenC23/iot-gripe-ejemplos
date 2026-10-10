void paginaFormulario() {
  String html =
      "<!doctype html><html><head><meta name='viewport' content='width=device-width'></head>"
      "<body style='font-family:sans-serif;max-width:420px;margin:40px auto;padding:0 16px'>"
      "<h2>Configurar Wi-Fi</h2>"
      "<form method='POST' action='/guardar'>"
      "<label>Red</label><br><input name='ssid' required style='width:100%'><br><br>"
      "<label>Contraseña</label><br><input name='pass' type='password' style='width:100%'><br><br>"
      "<button type='submit'>Guardar</button>"
      "</form></body></html>";
  servidor.send(200, "text/html", html);
}
