int statusbarmode = 0;

void statusbar() {
  qtb(0, -30, 320, 60, odarkgrey);
  if (statusbarmode == 0) {
    qtprint(0, 0, 2, owhite, (String)sbarmaintxt);
    qtprint(80*0, 20, 1, owhite, (String)"mls: " + millis());
    qtprint(80*1, 20, 1, owhite, (String)"heap: " + ESP.getFreeHeap());
    qtprint(80*2, 20, 1, owhite, (String)"model: " + ESP.getChipModel()); 
  }
  else if (statusbarmode == 1) {
    qtprint(80*2, 0, 1, owhite, (String)"heap: " + ESP.getFreeHeap() + "/" + ESP.getHeapSize()); 
    qtprint(80*2, 10, 1, owhite, (String)"flash: " + ESP.getFlashChipSize());
    qtprint(80*2, 20, 1, owhite, (String)"psram: " + ESP.getFreePsram() + "/" + ESP.getPsramSize()); // ADD MODEL NAME

    qtprint(80*0, 0, 1, owhite, (String)"ssid: " + pmapssid); 
    qtprint(80*0, 10, 1, owhite, (String)"pass: " + pmappass);
    qtprint(80*0, 20, 1, owhite, (String)"ip: " + WiFi.softAPIP().toString());
  }

  if (pirq()) {
    if (otx >= 0 && otx <= 320 && oty >= 0 && oty <= 30) {
      if (statusbarmode == 0) {statusbarmode = 1;}
      else {statusbarmode = 0;}
      // note for me when i wake up tmr, try using a ternary operator and see if it works

      qtb(0, 0, 320, 30, owhite);
    }
  }
}