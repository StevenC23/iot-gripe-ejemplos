#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include <Preferences.h>

WebServer servidor(80);
DNSServer dns;
Preferences prefs;
bool modoPortal = false;

void setup() {
  Serial.begin(115200);

  prefs.begin("wifi", true);
  String ssid = prefs.getString("ssid", "");
  String pass = prefs.getString("pass", "");
  prefs.end();

  if (ssid.isEmpty() || !conectarWiFi(ssid, pass)) {
    iniciarPortal();
    return;
  }
  Serial.printf("Conectado a %s con IP %s\n", ssid.c_str(), WiFi.localIP().toString().c_str());
  // modo normal: nube, sensores, etc.
}

void loop() {
  if (modoPortal) {
    dns.processNextRequest();
    servidor.handleClient();
    return;
  }
  // modo normal
}
