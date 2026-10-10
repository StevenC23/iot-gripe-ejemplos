String ssid, pass, cert, llave;
bool configurado = false;

void guardarConfig(const String& s, const String& p, const String& c, const String& k) {
  prefs.begin("config", false);
  prefs.putString("ssid", s);
  prefs.putString("pass", p);
  prefs.putString("cert", c);
  prefs.putString("key", k);
  prefs.end();
}

void cargarConfig() {
  prefs.begin("config", true);
  ssid  = prefs.getString("ssid", "");
  pass  = prefs.getString("pass", "");
  cert  = prefs.getString("cert", "");
  llave = prefs.getString("key", "");
  prefs.end();

  configurado = ssid.length() > 0 && cert.length() > 0 && llave.length() > 0;
}
