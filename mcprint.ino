void mcPrint(String message) {
  tft.fillRect(0, 240-30-30, 320, 30, oaccentcol);
  tft.setCursor(0, 240-30-30);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(1);
  tft.print("\n"); tft.print(message);
}

void mcPrintbadnews(String message) {
  tft.fillRect(0, 240-30-30, 320, 30, ohotpink);
  tft.setCursor(0, 240-30-30);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(1);
  tft.print("\n"); tft.print(message);
}