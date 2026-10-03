# Conectar un ESP32 a AWS IoT Core paso a paso

Código del artículo **[Conectar un ESP32 a AWS IoT Core paso a paso](https://iot.gripe/blog/conectar-esp32-aws-iot-core)**, publicado en [iot.gripe](https://iot.gripe).

Guía práctica para conectar un ESP32 a AWS IoT Core con MQTT, certificados X.509 y Device Shadow: política mínima, código Arduino y errores comunes.

| Archivo | Sección del artículo |
| --- | --- |
| [`paso-1-crear-el-thing-y-su-certificado.sh`](paso-1-crear-el-thing-y-su-certificado.sh) | Paso 1: Crear el Thing y su certificado |
| [`paso-2-una-politica-con-el-minimo-de-permisos.json`](paso-2-una-politica-con-el-minimo-de-permisos.json) | Paso 2: Una política con el mínimo de permisos |
| [`paso-2-una-politica-con-el-minimo-de-permisos.sh`](paso-2-una-politica-con-el-minimo-de-permisos.sh) | Paso 2: Una política con el mínimo de permisos |
| [`paso-3-obtener-el-endpoint-de-tu-cuenta.sh`](paso-3-obtener-el-endpoint-de-tu-cuenta.sh) | Paso 3: Obtener el endpoint de tu cuenta |
| [`secrets.h.example`](secrets.h.example) | Paso 4: Guardar las credenciales en secrets.h |
| [`paso-5-el-codigo-del-esp32/paso-5-el-codigo-del-esp32.ino`](paso-5-el-codigo-del-esp32/paso-5-el-codigo-del-esp32.ino) | Paso 5: El código del ESP32 |
| [`paso-6-probarlo-desde-la-nube.json`](paso-6-probarlo-desde-la-nube.json) | Paso 6: Probarlo desde la nube |
| [`paso-6-probarlo-desde-la-nube.sh`](paso-6-probarlo-desde-la-nube.sh) | Paso 6: Probarlo desde la nube |
| [`errores-comunes.cpp`](errores-comunes.cpp) | Errores comunes |

**Credenciales:** copia `secrets.h.example` como `secrets.h` dentro de la carpeta del sketch y completa tus datos. `secrets.h` está en el `.gitignore`: nunca lo subas a un repositorio.

Algunos archivos son fragmentos que se entienden junto con el artículo: ahí está la explicación paso a paso.
