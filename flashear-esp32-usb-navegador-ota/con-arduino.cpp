#include <WiFiClientSecure.h>
#include <HTTPUpdate.h>

void actualizar(const char* url) {
  WiFiClientSecure cliente;
  cliente.setCACert(CA_DEL_SERVIDOR);  // verifica el servidor de descarga
  t_httpUpdate_return r = httpUpdate.update(cliente, url);
  if (r == HTTP_UPDATE_FAILED) {
    Serial.printf("Falló la actualización: %s\n", httpUpdate.getLastErrorString().c_str());
  }
  // Si sale bien, el ESP32 se reinicia solo con la versión nueva
}
