#include <Adafruit_NeoPixel.h>

int stripSize = 12; // 12
#define DIN A0
Adafruit_NeoPixel strip = Adafruit_NeoPixel(stripSize, DIN, NEO_GRB + NEO_KHZ800);

// TODO: Bluetooth Transmition
int comand = 'J';

unsigned short colorR = 255;
unsigned short colorG = 255;
unsigned short colorB = 0;

unsigned short colorR2 = 255;
unsigned short colorG2 = 0;
unsigned short colorB2 = 0;

unsigned short time_B1 = 250;
unsigned short time_B2 = 250;
unsigned short time_C = 100;

void SetAllColors(unsigned short r, unsigned short g, unsigned short b, unsigned short start, unsigned short end_)
{
  int i = 0;
  for (i = start; i < end_; i++)
  {
    strip.setPixelColor(i, strip.Color(r, g, b));
  }
}

void setup()
{
  strip.begin();
  strip.show();
}

void loop()
{
  //Świecenie ciągłe
  if (comand == 'A')
  {
    SetAllColors(colorR, colorG, colorB, 0, stripSize);
    strip.show();
  }
  // Miganie
  if (comand == 'B')
  {
    SetAllColors(colorR, colorG, colorB, 0, stripSize);
    strip.show();
    delay(time_B1);
    SetAllColors(colorR2, colorG2, colorB2, 0, stripSize);
    strip.show();
    delay(time_B2);
  }
  // Pływanie LED góra- dół
  if (comand == 'C')
  {
    int i = 0;
    for (i = 0; i < stripSize; i++)
    {
      strip.setPixelColor(i, strip.Color(colorR, colorG, colorB));
      strip.show();
      delay(time_C);
    }
    for (i = stripSize - 1; i >= 0; i--)
    {
      strip.setPixelColor(i, strip.Color(colorR2, colorG2, colorB2));
      strip.show();
      delay(time_C);
    }
    for (i = 0; i < stripSize; i++)
    {
      strip.setPixelColor(i, strip.Color(colorR, colorG, colorB));
      strip.show();
      delay(time_C);
    }
    for (i = stripSize - 1; i >= 0; i--)
    {
      strip.setPixelColor(i, strip.Color(colorR2, colorG2, colorB2));
      strip.show();
      delay(time_C);
    }
  }
  // Ruch Led
  if (comand == 'D')
  {
    int num = stripSize - 1;
    int i;
    for (i = 0; i < num; i++)
    {
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
  if (comand == 'E')
  {
    SetAllColors(colorR, colorG, colorB, 0, stripSize / 4);
    SetAllColors(colorR2, colorG2, colorB2, stripSize / 4, stripSize / 2);
    SetAllColors(colorR, colorG, colorB, stripSize / 2, stripSize - stripSize / 4);
    SetAllColors(colorR2, colorG2, colorB2, stripSize - stripSize / 4, stripSize);
    strip.show();
    delay(50);
    SetAllColors(colorR, colorG, colorB, stripSize / 4, stripSize / 2);
    SetAllColors(colorR2, colorG2, colorB2, stripSize / 2, stripSize - stripSize / 4);
    SetAllColors(colorR, colorG, colorB, stripSize - stripSize / 4, stripSize);
    SetAllColors(colorR2, colorG2, colorB2, 0, stripSize / 4);
    strip.show();
    delay(50);
  }
  // Ola efekt - Rainbow
  if (comand == 'F')
  {
    strip.setPixelColor(0, strip.Color(255, 0, 255));
    strip.setPixelColor(1, strip.Color(25, 25, 112));
    strip.setPixelColor(2, strip.Color(255, 69, 0));
    strip.setPixelColor(3, strip.Color(255, 255, 0));
    strip.setPixelColor(4, strip.Color(0, 255, 255));
    strip.setPixelColor(5, strip.Color(0, 0, 255));
    strip.setPixelColor(6, strip.Color(0, 128, 0));
    strip.setPixelColor(7, strip.Color(165, 42, 42));
    strip.setPixelColor(8, strip.Color(139, 69, 19));
    strip.setPixelColor(9, strip.Color(255, 0, 0));
    strip.setPixelColor(10, strip.Color(255, 255, 255));
    strip.setPixelColor(11, strip.Color(128, 128, 0));
    strip.show();
  }
  // Gromadzenie0
  if (comand == 'G')
  {
    int num = stripSize - 1;
    int i = 0;
    while (num >= 0)
    {
      for (i = 0; i < num; i++)
      {
        strip.setPixelColor(i, strip.Color(colorR, colorG, colorB));
        strip.show();
        delay(100);
        strip.setPixelColor(i, strip.Color(0, 0, 0));
        strip.setPixelColor(i + 1, strip.Color(colorR, colorG, colorB));
        strip.show();
        delay(100);
      }
      num--;
    }
    delay(250);
    SetAllColors(0, 0, 0, 0, stripSize);
    strip.show();
  }
  // LED mijanie
  if (comand == 'H')
  {
    int num = stripSize - 1;
    int i;
    for (i = 0; i < num; i++)
    {
      strip.setPixelColor(i, strip.Color(colorR, colorG, colorB));
      strip.setPixelColor(num - i, strip.Color(colorR2, colorG2, colorB2));
      strip.show();
      delay(100);
      strip.setPixelColor(i, strip.Color(0, 0, 0));
      strip.setPixelColor(num - i, strip.Color(0, 0, 0));
      strip.setPixelColor(i + 1, strip.Color(colorR, colorG, colorB));
      strip.setPixelColor(num - i - 1, strip.Color(colorR2, colorG2, colorB2));
      strip.show();
      delay(100);
      strip.setPixelColor(num, strip.Color(0, 0, 0));
    }
  }
  // Zmiana jasności
  if (comand == 'I')
  {
    int i = 0;
    int num = 0;
    SetAllColors(colorR, colorG, colorB, 0, stripSize / 2);
    SetAllColors(colorR, colorG, colorB, stripSize / 2, stripSize);
    for (i = 0; i < 20; i++)
    {
      strip.setBrightness(255 - num);
      num += 12;
      strip.show();
      if (i == 220)
      {
        strip.setBrightness(0);
      }
      delay(50);
    }
  }
  if (comand == 'J')
  {
    for (int i = 0; i < stripSize; i++)
    {
      if (i % 2 == 0)
      {
        strip.setPixelColor(i, strip.Color(colorR, colorG, colorB));
        strip.show();
      }
      else
      {
        strip.setPixelColor(i, strip.Color(0, 255, 0));
        strip.show();
      }
    }
  }
}
