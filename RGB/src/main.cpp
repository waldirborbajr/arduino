#include <Arduino.h>

#define Red D1
#define Green D2
#define Blue D3

void rgb_Color(int i, int j, int k);

void setup() {

  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);
}

void loop() {

  rgb_Color(0,0,0);   // blak
  delay(1000);
  rgb_Color(255,255,255);   // White
  delay(1000);
  rgb_Color(255,0,0);   // red
  delay(1000);
  rgb_Color(0,255,0);   // lime
  delay(1000);
  rgb_Color(0,0,255);   // Blue
  delay(1000);
  rgb_Color(255,255,0);   // yellow
  delay(1000);
  rgb_Color(0,255,255);   // cyan
  delay(1000);
  rgb_Color(255,0,255);   // magenta
  delay(1000);
  rgb_Color(192,192,192);   // silver
  delay(1000);
  rgb_Color(128,128,128);   // gray
  delay(1000);
  rgb_Color(128,0,0);   // maroon
  delay(1000);
  rgb_Color(128,128,0);   // olive
  delay(1000);
  rgb_Color(0,128,0);   // green
  delay(1000);
  rgb_Color(128,0,128);   // purple
  delay(1000);
  rgb_Color(0,128,128);   // teal
  delay(1000);
  rgb_Color(0,0,128);   // navy
  delay(1000);
}

void rgb_Color(int i, int j, int k)
{
  analogWrite(Red, i);
  analogWrite(Green, j);
  analogWrite(Blue, k);
}
