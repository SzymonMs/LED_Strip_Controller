#include <Adafruit_NeoPixel.h>

int sizeStrip = 8;
#define DIN A0
Adafruit_NeoPixel strip = Adafruit_NeoPixel(sizeStrip, DIN, NEO_GRB + NEO_KHZ800);

// TODO: Bluetooth Transmition
char comand = 'E';

short colorR = 85;
short colorG = 147;
short colorB = 47;

short colorR2 = 139;
short colorG2 = 0;
short colorB2 = 0;

short time_B1 = 250;
short time_B2 = 250;
short time_C = 100;

void SetAllColors(short r, short g, short b, short start, short end_) {
  int i = 0;
  for (i = start; i < end_; i++)
  {
    strip.setPixelColor(i, strip.Color(r, g, b));
  }
}

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  //Świecenie ciągłe
  if ( comand == 'A') {
    SetAllColors(colorR, colorG, colorB, 0, sizeStrip);
    strip.show();
  }
  //Miganie
  if ( comand == 'B') {
    SetAllColors(colorR, colorG, colorB, 0, sizeStrip);
    strip.show();
    delay(time_B1);
    SetAllColors(colorR2, colorG2, colorB2, 0, sizeStrip);
    strip.show();
    delay(time_B2);
  }
  //Pływanie LED góra- dół
  if ( comand == 'C') {
    int i = 0;
    for (i = 0; i < sizeStrip; i++) {
      strip.setPixelColor(i, strip.Color(colorR, colorG, colorB));
      strip.show();
      delay(time_C);
    }
    for (i = sizeStrip - 1 ; i >= 0; i--) {
      strip.setPixelColor(i, strip.Color(colorR2, colorG2, colorB2));
      strip.show();
      delay(time_C);
    }
    for (i = 0 ; i < sizeStrip; i++) {
      strip.setPixelColor(i, strip.Color(colorR, colorG, colorB));
      strip.show();
      delay(time_C);
    }
    for (i = sizeStrip - 1 ; i >= 0; i--) {
      strip.setPixelColor(i, strip.Color(colorR2, colorG2, colorB2));
      strip.show();
      delay(time_C);
    }
  }
  // Ruch Led
  if ( comand == 'D') {
    int num = sizeStrip - 1;
    int i;
    for (i = 0; i < num ; i++) {
      strip.setPixelColor(i, strip.Color(colorR, colorG, colorB));
      strip.show();
      delay(100);
      strip.setPixelColor(i, strip.Color(0, 0, 0));
      strip.setPixelColor(i + 1, strip.Color(colorR, colorG, colorB));
      strip.show();
      delay(100);
      strip.setPixelColor(num, strip.Color(0, 0, 0));
    }
  }
  // LED change color two-two
  if ( comand == 'E') {
    SetAllColors(colorR, colorG, colorB, 0, sizeStrip / 4);
    SetAllColors(colorR2, colorG2, colorB2, sizeStrip / 4, sizeStrip / 2);
    SetAllColors(colorR, colorG, colorB, sizeStrip / 2, sizeStrip - sizeStrip / 4);
    SetAllColors(colorR2, colorG2, colorB2, sizeStrip - sizeStrip / 4, sizeStrip);
    strip.show();
    delay(50);
    SetAllColors(colorR, colorG, colorB, sizeStrip / 4, sizeStrip / 2);
    SetAllColors(colorR2, colorG2, colorB2, sizeStrip / 2, sizeStrip - sizeStrip / 4);
    SetAllColors(colorR, colorG, colorB, sizeStrip - sizeStrip / 4, sizeStrip);
    SetAllColors(colorR2, colorG2, colorB2, 0, sizeStrip / 4);
    strip.show();
    delay(50);
  }
}
