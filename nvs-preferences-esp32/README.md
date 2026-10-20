# NVS y Preferences en ESP32: guardar configuración que sobrevive cortes

Código del artículo **[NVS y Preferences en ESP32: guardar configuración que sobrevive cortes](https://iot.gripe/blog/nvs-preferences-esp32)**, publicado en [iot.gripe](https://iot.gripe).

Cómo guardar Wi-Fi, certificados y estructuras en la memoria NVS del ESP32 con Preferences: ejemplos, límites, un firmware único para varios dispositivos y cómo no desgastar la flash.

| Archivo | Sección del artículo |
| --- | --- |
| [`lo-basico-abrir-escribir-leer-cerrar/lo-basico-abrir-escribir-leer-cerrar.ino`](lo-basico-abrir-escribir-leer-cerrar/lo-basico-abrir-escribir-leer-cerrar.ino) | Lo básico: abrir, escribir, leer, cerrar |
| [`ejemplo-1-un-firmware-que-decide-segun-lo-que-encu.cpp`](ejemplo-1-un-firmware-que-decide-segun-lo-que-encu.cpp) | Ejemplo 1: un firmware que decide según lo que encuentra |
| [`ejemplo-2-un-arreglo-de-estructuras-con-putbytes.cpp`](ejemplo-2-un-arreglo-de-estructuras-con-putbytes.cpp) | Ejemplo 2: un arreglo de estructuras con putBytes |
| [`no-desgastes-la-flash.cpp`](no-desgastes-la-flash.cpp) | No desgastes la flash |
| [`como-borrar-la-configuracion.cpp`](como-borrar-la-configuracion.cpp) | Cómo borrar la configuración |

**Pruébalo sin placa:** [`wokwi/contador-arranques`](wokwi/contador-arranques) tiene `sketch.ino` y `diagram.json` para el simulador [Wokwi](https://wokwi.com). Crea un proyecto ESP32 nuevo y pega ambos archivos.

Algunos archivos son fragmentos que se entienden junto con el artículo: ahí está la explicación paso a paso.
