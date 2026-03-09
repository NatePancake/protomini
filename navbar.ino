void navbar() {
  qtb(0, 240-30, 320, 30, odarkgrey);
  qtbprint(0, 240-30, 50, 30, odarkgrey, 2, owhite, "menu");
  qtbprint(320-50, 240-30, 50, 30, odarkgrey, 2, owhite, "opts");

  if (pirq()) {
    if (otx >= 0 && otx <= 50 && oty >= 30*7 && oty <= 30*8) {
      qtbprint(0, 240-30, 60, 30, oaccentcol, 2, owhite, "menu");
      pmclearexclusive();
      uiid = 100;
    }
    else if (otx >= 320-50 && otx <= 320 && oty >= 30*7 && oty <= 30*8) {
      tft.fillRect(320-60, 240-30, 10, 30, oaccentcol);
      // ts ui thing is bugging me so shartt
      qtbprint(320-50, 240-30, 60, 30, oaccentcol, 2, owhite, "opts");
      pmclearexclusive();
      uiid = 200;
    }
  }
}