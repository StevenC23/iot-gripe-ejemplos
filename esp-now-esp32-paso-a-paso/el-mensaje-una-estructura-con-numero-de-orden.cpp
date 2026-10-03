// Mismo archivo en el hub y en los nodos
typedef struct __attribute__((packed)) {
  uint8_t  tipo;    // 1 = orden, 2 = confirmación
  uint8_t  salida;  // qué relé o luz del nodo
  uint8_t  valor;   // 0 = apagado, 1 = encendido
  uint16_t id;      // número de la orden, para emparejar la confirmación
} Mensaje;
