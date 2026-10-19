# ESP-NOW con más de 20 dispositivos: por qué falla esp_now_add_peer y qué hacer

Código del artículo **[ESP-NOW con más de 20 dispositivos: por qué falla esp_now_add_peer y qué hacer](https://iot.gripe/blog/esp-now-limite-20-dispositivos)**, publicado en [iot.gripe](https://iot.gripe).

ESP-NOW admite como máximo 20 peers (7 por defecto si están cifrados). Qué error da, cómo comprobarlo y tres formas de manejar más nodos: broadcast, peers rotativos y varios coordinadores.

| Archivo | Sección del artículo |
| --- | --- |
| [`el-error.cpp`](el-error.cpp) | El error |
| [`solucion-1-broadcast-y-filtrar-por-destino.cpp`](solucion-1-broadcast-y-filtrar-por-destino.cpp) | Solución 1: broadcast y filtrar por destino |
| [`solucion-1-broadcast-y-filtrar-por-destino-2.cpp`](solucion-1-broadcast-y-filtrar-por-destino-2.cpp) | Solución 1: broadcast y filtrar por destino |
| [`solucion-2-registrar-el-peer-solo-para-enviar.cpp`](solucion-2-registrar-el-peer-solo-para-enviar.cpp) | Solución 2: registrar el peer solo para enviar |

Algunos archivos son fragmentos que se entienden junto con el artículo: ahí está la explicación paso a paso.
