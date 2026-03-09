void apptemp() {
  qtbprint(0, 30*1, 320, 30, olightgrey, 2, oblack, "btn one");

  if(pirq()) {
    if (otx >= 0 && otx <= 320 && oty >= 30*1 && oty <= 30*2) {
      qtbprint(0, 30*1, 320, 30, oaccentcol, 2, owhite, "btn one pressed");
    }
  }
}