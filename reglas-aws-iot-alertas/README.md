# Reglas de AWS IoT: guardar datos y enviar alertas sin servidores

Código del artículo **[Reglas de AWS IoT: guardar datos y enviar alertas sin servidores](https://iot.gripe/blog/reglas-aws-iot-alertas)**, publicado en [iot.gripe](https://iot.gripe).

Cómo usar el motor de reglas de AWS IoT Core: SQL sobre mensajes MQTT, guardar lecturas de un ESP32 en DynamoDB, enviar alertas por correo con SNS, acciones de error, permisos y costos.

| Archivo | Sección del artículo |
| --- | --- |
| [`como-funciona-una-regla.sql`](como-funciona-una-regla.sql) | Cómo funciona una regla |
| [`el-dispositivo-publicar-la-telemetria.cpp`](el-dispositivo-publicar-la-telemetria.cpp) | El dispositivo: publicar la telemetría |
| [`regla-1-guardar-las-lecturas-en-dynamodb.sql`](regla-1-guardar-las-lecturas-en-dynamodb.sql) | Regla 1: guardar las lecturas en DynamoDB |
| [`regla-1-guardar-las-lecturas-en-dynamodb.json`](regla-1-guardar-las-lecturas-en-dynamodb.json) | Regla 1: guardar las lecturas en DynamoDB |
| [`regla-1-guardar-las-lecturas-en-dynamodb.sh`](regla-1-guardar-las-lecturas-en-dynamodb.sh) | Regla 1: guardar las lecturas en DynamoDB |
| [`regla-2-una-alerta-por-correo-con-sns.sh`](regla-2-una-alerta-por-correo-con-sns.sh) | Regla 2: una alerta por correo con SNS |
| [`regla-2-una-alerta-por-correo-con-sns.sql`](regla-2-una-alerta-por-correo-con-sns.sql) | Regla 2: una alerta por correo con SNS |
| [`probar-sin-el-esp32.json`](probar-sin-el-esp32.json) | Probar sin el ESP32 |

Algunos archivos son fragmentos que se entienden junto con el artículo: ahí está la explicación paso a paso.
