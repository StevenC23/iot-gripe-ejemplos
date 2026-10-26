void setup() {
  SPI.begin(18, -1, 23, 5);        // SCK, MISO (no se usa), MOSI, SS
  display.init(115200);            // velocidad para mensajes de depuración
  display.setRotation(1);          // horizontal
  display.setFont(&FreeMonoBold12pt7b);
  display.setTextColor(GxEPD_BLACK);

  display.setFullWindow();
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(10, 40);
    display.print("Hola ESP32");
  } while (display.nextPage());

  display.hibernate();             // apaga el controlador de la pantalla
}

void loop() {}
