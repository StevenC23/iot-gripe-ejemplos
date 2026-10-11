# Saber si un ESP32 está conectado: eventos de ciclo de vida en AWS IoT

Código del artículo **[Saber si un ESP32 está conectado: eventos de ciclo de vida en AWS IoT](https://iot.gripe/blog/detectar-dispositivo-desconectado-aws-iot)**, publicado en [iot.gripe](https://iot.gripe).

Cómo mostrar en la app si un dispositivo está en línea con AWS IoT Core: eventos de conexión y desconexión, el motivo de cada desconexión, guardarlo en el Shadow con una regla, Last Will, keepalive y nodos detrás de un hub.

| Archivo | Sección del artículo |
| --- | --- |
| [`los-eventos-de-conexion.json`](los-eventos-de-conexion.json) | Los eventos de conexión |
| [`cuanto-tarda-en-detectarse-una-desconexion.cpp`](cuanto-tarda-en-detectarse-una-desconexion.cpp) | Cuánto tarda en detectarse una desconexión |
| [`guardar-el-estado-de-conexion-en-el-shadow.sql`](guardar-el-estado-de-conexion-en-el-shadow.sql) | Guardar el estado de conexión en el Shadow |
| [`last-will-el-aviso-del-propio-dispositivo.cpp`](last-will-el-aviso-del-propio-dispositivo.cpp) | Last Will: el aviso del propio dispositivo |
| [`consultar-la-conexion-sin-guardar-nada.sh`](consultar-la-conexion-sin-guardar-nada.sh) | Consultar la conexión sin guardar nada |

Algunos archivos son fragmentos que se entienden junto con el artículo: ahí está la explicación paso a paso.
