// Simple bring-up of the RF module, using on-board UART. Connected to pin 1.
#include <Wire.h>

unsigned char counter;

void setup()   
{                
  Serial.begin(2400);
  counter = 0;
}

void loop()
{
  counter = 1;
  Serial.print(0xAA);
  Serial.print(counter);
  Serial.print(0xAA);
  //counter++;
  delay(500);
}

