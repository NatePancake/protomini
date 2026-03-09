String pmwifistatestr;
int pmwifistate;
bool pmsoftapenabled = 0;
bool pmserveron = 0;

String pmapssid = "iPhone 13 Pro";
String pmappass = "borbon123";

void pmwifitools() {
  if (pmwifistate == 0) {
    pmwifistatestr = "off";
    qtbprint(0, 30*1, 320, 30, ohotpink, 2, oblack, (String)"mode: " + pmwifistatestr);
  }
  else if (pmwifistate == 1) {
    pmwifistatestr = "station";
    qtbprint(0, 30*1, 320, 30, oblurple, 2, owhite, (String)"mode: " + pmwifistatestr);
  }
  else if (pmwifistate == 2) {
    pmwifistatestr = "softap";
    qtbprint(0, 30*1, 320, 30, oblurple, 2, owhite, (String)"mode: " + pmwifistatestr);
    qtprint(0, 50, 1, owhite, (String)"Connected devices: " + WiFi.softAPgetStationNum());
  }
  else if (pmwifistate == 3) {
    pmwifistatestr = "softap + station";
    qtbprint(0, 30*1, 320, 30, oteal, 2, oblack, (String)"mode: " + pmwifistatestr);
  }
  
  if (pmsoftapenabled) {qtbprint(0, 30*2, 320, 30, oteal, 2, oblack, "softap: on");}
  else {qtbprint(0, 30*2, 320, 30, olightgrey, 2, oblack, "softap: off");}

  if (pmserveron) {qtbprint(0, 30*3, 320, 30, oteal, 2, oblack, "local server: on");}
  else {qtbprint(0, 30*3, 320, 30, olightgrey, 2, oblack, "local server: off");}

  if(pirq()) {
    if (otx >= 0 && otx <= 320 && oty >= 30*1 && oty <= 30*2) {
      if (pmwifistate == 0) {
        qtbprint(0, 30*1, 320, 30, owhite, 2, oblack, "mode: switching");
        pmwifistate = 1;
        WiFi.mode(WIFI_STA);
      }
      else if (pmwifistate == 1) {
        qtbprint(0, 30*1, 320, 30, owhite, 2, oblack, "mode: switching");
        pmwifistate = 2;
        WiFi.mode(WIFI_AP);
      }
      else if (pmwifistate == 2) {
        qtbprint(0, 30*1, 320, 30, owhite, 2, oblack, "mode: switching");
        WiFi.mode(WIFI_AP_STA);
        pmwifistate = 3;
      }
      else if (pmwifistate == 3) {
        qtbprint(0, 30*1, 320, 30, owhite, 2, oblack, "mode: turning off");
        WiFi.mode(WIFI_MODE_NULL);
        pmwifistate = 0;
      }
    }

    if (otx >= 0 && otx <= 320 && oty >= 30*2 && oty <= 30*3) {
      if (pmsoftapenabled) {WiFi.softAPdisconnect(true); pmsoftapenabled = 0;}
      else {WiFi.softAP(pmapssid, pmappass); pmsoftapenabled = 1;}
      qtbprint(0, 30*2, 320, 30, owhite, 2, oblack, "softap: switching");
    }
    if (otx >= 0 && otx <= 320 && oty >= 30*3 && oty <= 30*4) {
      if (pmserveron) {server.stop(); pmserveron = 0;}
      else {
        if (!LittleFS.begin(true)) {
          Serial.println("LittleFS Mount Failed");
          mcPrintbadnews("LittleFS Mount Failed!");
          return;
        }

        // Serve index
        server.on("/", HTTP_GET, []() {
          File file = LittleFS.open("/webserver/index.html", "r");
          if (!file) {
            server.send(404, "text/plain", "File Not Found");
            return;
          }
          server.streamFile(file, "text/html");
          file.close();
        });

        // Serve CSS
        server.on("/style.css", HTTP_GET, []() {
          File file = LittleFS.open("/webserver/style.css", "r");
          if (!file) {
            server.send(404, "text/plain", "File Not Found");
            return;
          }
          server.streamFile(file, "text/css");
          file.close();
        });

        server.on("/Inconsolata_SemiExpanded-Regular.woff2", HTTP_GET, []() {
          File file = LittleFS.open("/webserver/Inconsolata_SemiExpanded-Regular.woff2", "r");
          if (!file) {
            server.send(404, "text/plain", "File Not Found");
            return;
          }
          server.streamFile(file, "text/woff2");
          file.close();
        });

        server.on("/Inconsolata_ExtraExpanded-Bold.woff2", HTTP_GET, []() {
          File file = LittleFS.open("/webserver/Inconsolata_ExtraExpanded-Bold.woff2", "r");
          if (!file) {
            server.send(404, "text/plain", "File Not Found");
            return;
          }
          server.streamFile(file, "text/woff2");
          file.close();
        });

        server.on("/rollme.gif", HTTP_GET, []() {
          File file = LittleFS.open("/webserver/rollme.gif", "r");
          if (!file) {
            server.send(404, "text/plain", "File Not Found");
            return;
          }
          server.streamFile(file, "image/gif");
          file.close();
        });

        server.serveStatic("/", LittleFS, "/");

        server.onNotFound([]() {
          server.sendHeader("Location", "/", true); // Redirect
          server.send(302, "text/plain", "");
        });

        server.begin();
        dnsServer.start(53, "*", WiFi.softAPIP());
        pmserveron = 1;
      }
      qtbprint(0, 30*3, 320, 30, owhite, 2, oblack, "softap: switching");
    }
  }

  // loop idk
  if (pmserveron) {server.handleClient(); dnsServer.processNextRequest();}

}

void pmwebserver();