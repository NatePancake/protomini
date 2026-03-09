void qtprint(int curx, int cury, int fontsize, int fontcolor, String text) {
  tft.setCursor(curx, cury);
  tft.setTextSize(fontsize);
  tft.setTextColor(fontcolor);
  tft.print(text);
}

void qtbprint(int curx, int cury, int rectsizex, int rectsizey, int rectcol, int fontsize, int fontcolor, String text) {
  tft.fillRect(curx, cury, rectsizex, rectsizey, rectcol);
  tft.setCursor(curx, cury);
  tft.setTextSize(fontsize);
  tft.setTextColor(fontcolor);
  tft.print(text);
}


void qtrbprint(int curx, int cury, int rectsizex, int rectsizey, int rectcol, int fontsize, int fontcolor, String text) {
  tft.fillRoundRect(curx, cury, rectsizex, rectsizey, uiradius, rectcol);
  tft.setCursor(curx, cury);
  tft.setTextSize(fontsize);
  tft.setTextColor(fontcolor);
  tft.print(text);
}

void qtb(int curx, int cury, int rectsizex, int rectsizey, int rectcol) {
  tft.fillRect(curx, cury, rectsizex, rectsizey, rectcol);
}

void qtrb(int curx, int cury, int rectsizex, int rectsizey, int rectcol) {
  tft.fillRoundRect(curx, cury, rectsizex, rectsizey, uiradius, rectcol);
}