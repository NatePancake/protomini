void menua() {
  qtbprint(0, 30*1, 320, 30, olightgrey, 2, oblack, "wifi");
  qtbprint(0, 30*2, 320, 30, olightgrey, 2, oblack, "companion mode");

  // handle touch
  if(pirq()) {
    if (otx >= 0 && otx <= 320 && oty >= 30*1 && oty <= 30*2) {
      qtbprint(0, 30*1, 320, 30, oaccentcol, 2, owhite, "wifi");
      pmclearexclusive();
      uiid = 10;
    }
    if (otx >= 0 && otx <= 320 && oty >= 30*2 && oty <= 30*3) {
      qtbprint(0, 30*2, 320, 30, oaccentcol, 2, owhite, "companion mode");
      pmclearexclusive();
      uiid = 20;
    }
  }
}