// RF receiver hooked to UART via pin 0

#include <Wire.h>

int incomingByte = 0;

void setup()
{
    Serial.begin(2400);	// Debugging only
}

void loop()
{
  if (Serial.available() > 0)
  {
    incomingByte = Serial.read();
    if (incomingByte != 0)
      Serial.println(incomingByte, HEX);
  }
  incomingByte = 0;
}

