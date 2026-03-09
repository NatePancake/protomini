void pmoptions() {
  qtbprint(0, 30*1, 320, 30, olightgrey, 2, oblack, "accent color");

  if(pirq()) {
    if (otx >= 0 && otx <= 320 && oty >= 30*1 && oty <= 30*2) {
      qtbprint(0, 30*1, 320, 30, oaccentcol, 2, owhite, "accent color");
      uiid = 201;
    }
  }
}

void pmoptionsaccentcol() {

  qtbprint(0, 30*1, 320, 30, pmbgcol, 2, owhite, "current accent color: ");
  tft.fillRect(250, 30*1, 70, 30, oaccentcol);

  qtbprint(0, 30*3, 320, 30, ohotpink, 2, oblack, "hot pink");
  qtbprint(0, 30*4, 320, 30, oteal, 2, oblack, "teal");
  qtbprint(0, 30*5, 320, 30, oblurple, 2, oblack, "blurple");

  if(ts.touched()) {
    if (otx >= 0 && otx <= 320 && oty >= 30*3 && oty <= 30*4) {
      qtbprint(0, 30*3, 320, 30, owhite, 2, oblack, "selecting"); oaccentcol = ohotpink;
    }
    if (otx >= 0 && otx <= 320 && oty >= 30*4 && oty <= 30*5) {
      qtbprint(0, 30*4, 320, 30, owhite, 2, oblack, "selecting"); oaccentcol = oteal;
    }
    if (otx >= 0 && otx <= 320 && oty >= 30*5 && oty <= 30*6) {
      qtbprint(0, 30*5, 320, 30, owhite, 2, oblack, "selecting"); oaccentcol = oblurple;
    }
  }
}