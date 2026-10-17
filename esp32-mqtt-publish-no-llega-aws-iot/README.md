# ESP32 publica en MQTT pero no llega a AWS IoT: causas y solución

Código del artículo **[ESP32 publica en MQTT pero no llega a AWS IoT: causas y solución](https://iot.gripe/blog/esp32-mqtt-publish-no-llega-aws-iot)**, publicado en [iot.gripe](https://iot.gripe).

publish() devuelve true y AWS IoT no recibe nada. Revisión ordenada: QoS, búfer, política, client ID, loop() y el cambio de PubSubClient a la librería MQTT de 256dpi.

| Archivo | Sección del artículo |
| --- | --- |
| [`2-el-tamano-del-bufer.cpp`](2-el-tamano-del-bufer.cpp) | 2. El tamaño del búfer |
| [`5-no-estas-llamando-a-loop.cpp`](5-no-estas-llamando-a-loop.cpp) | 5. No estás llamando a loop() |
| [`6-la-libreria.sh`](6-la-libreria.sh) | 6. La librería |
| [`el-mismo-envio-con-la-libreria-mqtt/el-mismo-envio-con-la-libreria-mqtt.ino`](el-mismo-envio-con-la-libreria-mqtt/el-mismo-envio-con-la-libreria-mqtt.ino) | El mismo envío con la librería MQTT |

Algunos archivos son fragmentos que se entienden junto con el artículo: ahí está la explicación paso a paso.
