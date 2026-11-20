esp_sleep_wakeup_cause_t causa = esp_sleep_get_wakeup_cause();
if (causa == ESP_SLEEP_WAKEUP_TIMER) {
  // despertó por tiempo
}
