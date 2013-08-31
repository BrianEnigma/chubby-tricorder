// Simple bring-up of the RF module, using square waves, connected to pin A5.
#include <Wire.h>

void setup()   
{                
  //Serial.begin(9600);
  pinMode(13, OUTPUT);     
  pinMode(A5, OUTPUT);

}

void loop()
{
  digitalWrite(13, true); // Flash a light to show received good message
  digitalWrite(A5, true); // Flash a light to show received good message
  delay(500);
  digitalWrite(13, false); // Flash a light to show received good message
  digitalWrite(A5, false); // Flash a light to show received good message
  delay(500);
}

