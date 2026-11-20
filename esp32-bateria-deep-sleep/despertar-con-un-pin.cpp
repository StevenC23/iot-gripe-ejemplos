// ESP32 clásico: despertar cuando el GPIO 33 pase a nivel alto
esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, 1);
esp_deep_sleep_start();
