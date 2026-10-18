# ESP32-C3 se desconecta de AWS IoT con CLIENT_ERROR: falta de stack en loop()

Código del artículo **[ESP32-C3 se desconecta de AWS IoT con CLIENT_ERROR: falta de stack en loop()](https://iot.gripe/blog/esp32-c3-stack-loop-client-error)**, publicado en [iot.gripe](https://iot.gripe).

Un ESP32-C3 conecta a AWS IoT y se desconecta al segundo con CLIENT_ERROR. La causa es la pila de loop(); cómo medirla y ampliarla con SET_LOOP_TASK_STACK_SIZE.

| Archivo | Sección del artículo |
| --- | --- |
| [`como-medir-la-pila-que-te-queda.cpp`](como-medir-la-pila-que-te-queda.cpp) | Cómo medir la pila que te queda |
| [`la-solucion-mas-pila-para-loop/la-solucion-mas-pila-para-loop.ino`](la-solucion-mas-pila-para-loop/la-solucion-mas-pila-para-loop.ino) | La solución: más pila para loop() |

Algunos archivos son fragmentos que se entienden junto con el artículo: ahí está la explicación paso a paso.
