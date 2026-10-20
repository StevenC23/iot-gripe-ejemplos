# Bombillo inteligente DIY con ESP32-C3 e interruptor de pared que funciona sin internet

Código del artículo **[Bombillo inteligente DIY con ESP32-C3 e interruptor de pared que funciona sin internet](https://iot.gripe/blog/bombillo-inteligente-esp32-c3-interruptor)**, publicado en [iot.gripe](https://iot.gripe).

Cómo agregar un interruptor físico a un nodo ESP32-C3 de domótica: lógica de alternar, cableado sin resistencias, sincronización con la app y el Device Shadow, y seguridad al usar un relé.

| Archivo | Sección del artículo |
| --- | --- |
| [`el-codigo-del-nodo/el-codigo-del-nodo.ino`](el-codigo-del-nodo/el-codigo-del-nodo.ino) | El código del nodo |
| [`avisar-al-hub.cpp`](avisar-al-hub.cpp) | Avisar al hub |
| [`que-la-nube-no-deshaga-el-cambio.cpp`](que-la-nube-no-deshaga-el-cambio.cpp) | Que la nube no deshaga el cambio |

**Pruébalo sin placa:** [`wokwi/interruptor-antirrebote`](wokwi/interruptor-antirrebote) tiene `sketch.ino` y `diagram.json` para el simulador [Wokwi](https://wokwi.com). Crea un proyecto ESP32 nuevo y pega ambos archivos.

Algunos archivos son fragmentos que se entienden junto con el artículo: ahí está la explicación paso a paso.
