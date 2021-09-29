/*
UVC-Water-Sensor
Scott Mikus
Northmeadow Medical
https://www.northmeadowmedical.com
eptember 29, 2021
*/

#include <Wire.h>
#include "functions.h"

void setup()
{
  Serial.begin(9600);
  pinMode(PowerPin, OUTPUT);
  readings = readings-1;
}

void loop()
{
  pressRead();
  uvc();
  delay(500);
  i = 0;
}
