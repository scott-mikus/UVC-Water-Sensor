#include <Wire.h>
#include "functions.h"

void setup()
{
  Serial.begin(9600);
  pinMode(PowerPin, OUTPUT);
}

void loop()
{
  pressRead();
  uvc();
  delay(500);
  i = 0;
}
