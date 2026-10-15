#include <WiFi.h>
SET_LOOP_TASK_STACK_SIZE(16 * 1024);   // MAL: se expande a una función
#include "tipos.h"                      // define struct Nodo

void procesar(Nodo &n) { /* ... */ }    // error: 'Nodo' was not declared
