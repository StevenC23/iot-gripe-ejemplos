void loop() {
  static uint32_t ultimo = 0;
  if (millis() - ultimo > 5000) {
    ultimo = millis();
    // Mínimo de pila libre que ha tenido esta tarea desde que arrancó (en bytes)
    Serial.printf("Pila libre mínima: %u bytes\n", uxTaskGetStackHighWaterMark(NULL));
    Serial.printf("Heap libre: %u bytes\n", ESP.getFreeHeap());
  }
  // ... tu código
}
