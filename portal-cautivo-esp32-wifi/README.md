# Portal cautivo en ESP32: configurar el Wi-Fi sin reprogramar

Código del artículo **[Portal cautivo en ESP32: configurar el Wi-Fi sin reprogramar](https://iot.gripe/blog/portal-cautivo-esp32-wifi)**, publicado en [iot.gripe](https://iot.gripe).

Cómo hacer que un ESP32 sin configurar levante su propia red con un formulario web, abra la página sola con un servidor DNS, guarde el Wi-Fi en NVS y vuelva al portal si no puede conectarse.

| Archivo | Sección del artículo |
| --- | --- |
| [`el-firmware-dos-modos-en-un-solo-binario/el-firmware-dos-modos-en-un-solo-binario.ino`](el-firmware-dos-modos-en-un-solo-binario/el-firmware-dos-modos-en-un-solo-binario.ino) | El firmware: dos modos en un solo binario |
| [`intentar-conectar-con-un-limite-de-tiempo.cpp`](intentar-conectar-con-un-limite-de-tiempo.cpp) | Intentar conectar con un límite de tiempo |
| [`levantar-la-red-y-el-portal.cpp`](levantar-la-red-y-el-portal.cpp) | Levantar la red y el portal |
| [`el-formulario.cpp`](el-formulario.cpp) | El formulario |
| [`validar-guardar-y-reiniciar.cpp`](validar-guardar-y-reiniciar.cpp) | Validar, guardar y reiniciar |

Algunos archivos son fragmentos que se entienden junto con el artículo: ahí está la explicación paso a paso.
