void mostrarTemperatura(float t) {
  const int x = 10, y = 20, w = 140, h = 40;
  display.setPartialWindow(x, y, w, h);
  display.firstPage();
  do {
    display.fillRect(x, y, w, h, GxEPD_WHITE);
    display.setCursor(x, y + 28);
    display.print(t, 1);
    display.print(" C");
  } while (display.nextPage());
}
