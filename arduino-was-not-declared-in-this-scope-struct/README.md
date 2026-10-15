# Error \"was not declared in this scope\" con un struct en Arduino: la causa y 4 soluciones

Código del artículo **[Error \"was not declared in this scope\" con un struct en Arduino: la causa y 4 soluciones](https://iot.gripe/blog/arduino-was-not-declared-in-this-scope-struct)**, publicado en [iot.gripe](https://iot.gripe).

Por qué el IDE de Arduino dice que tu struct no está declarado aunque lo esté: los prototipos automáticos de los .ino y cómo evitar el error en ESP32 y Arduino.

| Archivo | Sección del artículo |
| --- | --- |
| [`inicio.txt`](inicio.txt) | inicio |
| [`la-causa-los-prototipos-automaticos/la-causa-los-prototipos-automaticos.ino`](la-causa-los-prototipos-automaticos/la-causa-los-prototipos-automaticos.ino) | La causa: los prototipos automáticos |
| [`el-caso-dificil-una-macro-que-es-una-funcion.cpp`](el-caso-dificil-una-macro-que-es-una-funcion.cpp) | El caso difícil: una macro que es una función |
| [`solucion-1-los-tipos-en-un-archivo-h.cpp`](solucion-1-los-tipos-en-un-archivo-h.cpp) | Solución 1: los tipos en un archivo .h |
| [`solucion-1-los-tipos-en-un-archivo-h-2.cpp`](solucion-1-los-tipos-en-un-archivo-h-2.cpp) | Solución 1: los tipos en un archivo .h |
| [`solucion-3-las-macros-que-son-funciones-despues-de.cpp`](solucion-3-las-macros-que-son-funciones-despues-de.cpp) | Solución 3: las macros que son funciones, después de los #include |
| [`solucion-4-escribe-tu-el-prototipo.cpp`](solucion-4-escribe-tu-el-prototipo.cpp) | Solución 4: escribe tú el prototipo |

Algunos archivos son fragmentos que se entienden junto con el artículo: ahí está la explicación paso a paso.
