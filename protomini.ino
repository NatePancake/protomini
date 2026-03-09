#include <Adafruit_ILI9341.h>
#include <XPT2046_Touchscreen.h>
#include <Adafruit_GFX.h>
#include <WiFi.h>
#include <WebServer.h>
#include <LittleFS.h>
#include <DNSServer.h>

#include "companionmode/idle1.h"
#include "companionmode/idleblink.h"
#include "companionmode/idleafteblink.h"
#include "companionmode/tap.h"

// esp32 c3 mini config
#define trst 0
#define tcs 7
#define tmiso 5
#define tmosi 6
#define tdc 1 
#define tsck 4
#define bl 2
#define ttcs 10
#define ttirq 3

DNSServer dnsServer;
WebServer server(80);

bool pirq() {
  return digitalRead(ttirq) == LOW;
}

String sbarmaintxt = "";
int uiid = 100;
int uiradius = 10;
int refappstimer = 100;
String textfield;

// mapped touch pos
int otx;
int oty;

// colors
#define oblack 0x0000
#define odarkgrey 0x5aeb
#define olightgrey 0xc638
#define owhite 0xffff

// #define oblurple 0xa4b8
#define oblurple 0x8a7d
#define ohotpink 0xea75
#define oteal 0x4f52

int oaccentcol = oblurple;
int pmbgcol = oblack;

// void qtprint();
// void qtbprint();
// void qtrbprint();
// void qtb();
// void qtrb();

void statusbar();
void navbar();
void menua();
void menub();
void pmwifitools();
void pmwebserver();

// Adafruit_ILI9341 tft = Adafruit_ILI9341(tcs, tdc, tmosi, tsck, trst, tmiso);
Adafruit_ILI9341 tft = Adafruit_ILI9341(tcs, tdc, trst);

XPT2046_Touchscreen ts(ttcs, ttirq);

void pwmbl() {
  ledcWrite(bl, 63);
}

void setup() {
  Serial.begin(115200);
  SPI.begin(tsck, tmiso, tmosi);

  ledcAttach(bl, 20000, 8);

  tft.begin();
  ts.begin();
  
  // tft.setSwapBytes(true); 

  tft.setRotation(3);
  ts.setRotation(4);
  pmclearentire();
}

int pmdebugloops = 0;

void loop() {
  pwmbl();
  // pmdebug();
  if (pirq()) {
    mapTouch();
  } 
  else {otx = oty = -1;}
  if (refappstimer <= 0) {refapps(); refappstimer = 100;}
  else {refappstimer--;}
  delay(1);
}

void pmdebug() {
  Serial.print((String)"refappstimer: " + refappstimer);
  Serial.print((String)"pmdebugloops: " + pmdebugloops);
  pmdebugloops++;
}

void mapTouch() {
  TS_Point p = ts.getPoint();
  otx = map(p.x, 300, 3800, 0, tft.width());
  oty = map(p.y, 250, 3800, 0, tft.height());
  Serial.println((String)otx + ", " + oty);
}

void refapps() {
  Serial.println(textfield);
  // pmonscreenkeyboard();
  statusbar();
  navbar();

  if (uiid == 100) {menua(); sbarmaintxt = "protomini one [ page 1 ]";}
  else if (uiid == 101) {menub(); sbarmaintxt = "protomini one [ page 2 ]";}

  else if (uiid == 200) {pmoptions(); sbarmaintxt = "> options";}
  else if (uiid == 201) {pmoptionsaccentcol(); sbarmaintxt = "> options > accent color";}

  else if (uiid == 10) {pmwifitools(); sbarmaintxt = "> wifi";}
  // else if (uiid == 20) {companionmode(); sbarmaintxt = ":D";}
  // else if (uiid == 1001) {pmwebserver(); sbarmaintxt = "> wifi > webserver";}

}