int kbdmode = 0;
void pmonscreenkeyboard() {
  // row 1
  qtbprint(0, 240-60, 32, 25, ohotpink, 2, oblack, "ex");
  qtbprint(32, 240-60, 128, 25, owhite, 2, oblack, "space");
  qtbprint(160, 240-60, 80, 25, olightgrey, 2, oblack, "shift");
  qtbprint(240, 240-60, 80, 25, oaccentcol, 2, owhite, "enter");
  if (kbdmode == 0) {
    // row 2
    qtbprint(32*0, 240-85, 32, 25, olightgrey, 2, oblack, "z");
    qtbprint(32*1, 240-85, 32, 25, olightgrey, 2, oblack, "x");
    qtbprint(32*2, 240-85, 32, 25, olightgrey, 2, oblack, "c");
    qtbprint(32*3, 240-85, 32, 25, olightgrey, 2, oblack, "v");
    qtbprint(32*4, 240-85, 32, 25, olightgrey, 2, oblack, "b");
    qtbprint(32*5, 240-85, 32, 25, olightgrey, 2, oblack, "n");
    qtbprint(32*6, 240-85, 32, 25, olightgrey, 2, oblack, "m");
    
    qtbprint(32*6, 240-85, 32, 25, olightgrey, 2, oblack, ",");
    qtbprint(32*7, 240-85, 32, 25, olightgrey, 2, oblack, ".");
    qtbprint(32*8, 240-85, 32, 25, olightgrey, 2, oblack, "/");
    qtbprint(32*8, 240-85, 32, 25, olightgrey, 2, oblack, ";");
    qtbprint(32*9, 240-85, 32, 25, ohotpink, 2, oblack, "<");
    // row 3
    qtbprint(32*0, 240-110, 32, 25, olightgrey, 2, oblack, "a");
    qtbprint(32*1, 240-110, 32, 25, olightgrey, 2, oblack, "s");
    qtbprint(32*2, 240-110, 32, 25, olightgrey, 2, oblack, "d");
    qtbprint(32*3, 240-110, 32, 25, olightgrey, 2, oblack, "f");
    qtbprint(32*4, 240-110, 32, 25, olightgrey, 2, oblack, "g");
    qtbprint(32*5, 240-110, 32, 25, olightgrey, 2, oblack, "h");
    qtbprint(32*6, 240-110, 32, 25, olightgrey, 2, oblack, "j");
    qtbprint(32*6, 240-110, 32, 25, olightgrey, 2, oblack, "k");
    qtbprint(32*7, 240-110, 32, 25, olightgrey, 2, oblack, "l");
    qtbprint(32*8, 240-110, 32, 25, olightgrey, 2, oblack, "'");
    qtbprint(32*9, 240-110, 32, 25, owhite, 2, oblack, "md");
    // row 4
    qtbprint(32*0, 240-135, 32, 25, olightgrey, 2, oblack, "q");
    qtbprint(32*1, 240-135, 32, 25, olightgrey, 2, oblack, "w");
    qtbprint(32*2, 240-135, 32, 25, olightgrey, 2, oblack, "e");
    qtbprint(32*3, 240-135, 32, 25, olightgrey, 2, oblack, "r");
    qtbprint(32*4, 240-135, 32, 25, olightgrey, 2, oblack, "t");
    qtbprint(32*5, 240-135, 32, 25, olightgrey, 2, oblack, "y");
    qtbprint(32*6, 240-135, 32, 25, olightgrey, 2, oblack, "u");
    qtbprint(32*7, 240-135, 32, 25, olightgrey, 2, oblack, "i");
    qtbprint(32*8, 240-135, 32, 25, olightgrey, 2, oblack, "o");
    qtbprint(32*9, 240-135, 32, 25, olightgrey, 2, oblack, "p");
  }
  else if (kbdmode == 1) {
    // row 2
    qtbprint(32*7, 240-85, 32, 25, olightgrey, 2, oblack, "7");
    qtbprint(32*8, 240-85, 32, 25, olightgrey, 2, oblack, "8");
    qtbprint(32*8, 240-85, 32, 25, olightgrey, 2, oblack, "9");
    qtbprint(32*9, 240-85, 32, 25, olightgrey, 2, oblack, "0");
    // row 3
    qtbprint(32*6, 240-110, 32, 25, olightgrey, 2, oblack, "4");
    qtbprint(32*7, 240-110, 32, 25, olightgrey, 2, oblack, "5");
    qtbprint(32*8, 240-110, 32, 25, olightgrey, 2, oblack, "6");
    qtbprint(32*9, 240-110, 32, 25, owhite, 2, oblack, "md");
    // row 4
    qtbprint(32*6, 240-135, 32, 25, olightgrey, 2, oblack, "1");
    qtbprint(32*7, 240-135, 32, 25, olightgrey, 2, oblack, "2");
    qtbprint(32*8, 240-135, 32, 25, olightgrey, 2, oblack, "3");
    qtbprint(32*9, 240-135, 32, 25, ohotpink, 2, oblack, "<");
  }
  if(ts.touched()) {
    if (otx >= 0 && otx <= 32 && oty >= 240-60 && oty <= 240-30) {
      qtbprint(0, 240-60, 32, 25, owhite, 2, ohotpink, "ex");
      return;
    }
    
    if (kbdmode == 0) {
      if (otx >= 32*0 && otx <= 32*1 && oty >= 240-30-30-25-25-25 && oty <= 240-30-30-25-25) {
        qtbprint(32*0, 240-135, 32, 25, ohotpink, 2, owhite, "q");
        textfield.concat("q");
      }
      if (otx >= 32*1 && otx <= 32*2 && oty >= 240-30-30-25-25-25 && oty <= 240-30-30-25-25) {
        qtbprint(32*1, 240-135, 32, 25, ohotpink, 2, owhite, "w");
        textfield.concat("w");
      }
      if (otx >= 32*2 && otx <= 32*3 && oty >= 240-30-30-25-25-25 && oty <= 240-30-30-25-25) {
        qtbprint(32*9, 240-135, 32, 25, ohotpink, 2, owhite, "e");
        textfield.concat("e");
      }
      if (otx >= 32*3 && otx <= 32*4 && oty >= 240-30-30-25-25-25 && oty <= 240-30-30-25-25) {
        qtbprint(32*3, 240-135, 32, 25, ohotpink, 2, owhite, "r");
        textfield.concat("r");
      }
      if (otx >= 32*4 && otx <= 32*5 && oty >= 240-30-30-25-25-25 && oty <= 240-30-30-25-25) {
        qtbprint(32*4, 240-135, 32, 25, ohotpink, 2, owhite, "t");
        textfield.concat("t");
      }
      if (otx >= 32*5 && otx <= 32*6 && oty >= 240-30-30-25-25-25 && oty <= 240-30-30-25-25) {
        qtbprint(32*5, 240-135, 32, 25, ohotpink, 2, owhite, "y");
        textfield.concat("y");
      }
      if (otx >= 32*6 && otx <= 32*7 && oty >= 240-30-30-25-25-25 && oty <= 240-30-30-25-25) {
        qtbprint(32*6, 240-135, 32, 25, ohotpink, 2, owhite, "u");
        textfield.concat("u");
      }
      if (otx >= 32*7 && otx <= 32*8 && oty >= 240-30-30-25-25-25 && oty <= 240-30-30-25-25) {
        qtbprint(32*7, 240-135, 32, 25, ohotpink, 2, owhite, "i");
        textfield.concat("u");
      }
      if (otx >= 32*8 && otx <= 32*9 && oty >= 240-30-30-25-25-25 && oty <= 240-30-30-25-25) {
        qtbprint(32*8, 240-135, 32, 25, ohotpink, 2, owhite, "o");
        textfield.concat("u");
      }
      if (otx >= 32*9 && otx <= 32*10 && oty >= 240-30-30-25-25-25 && oty <= 240-30-30-25-25) {
        qtbprint(32*9, 240-135, 32, 25, ohotpink, 2, owhite, "p");
        textfield.concat("u");
      }

      if (otx >= 320-32 && otx <= 320 && oty >= 30*3 && oty <= 30*4) {
        qtbprint(32*10, 240-135, 32, 25, ohotpink, 2, owhite, "<");
        textfield.remove(textfield.length(), 1);
      }
    }
  }
}