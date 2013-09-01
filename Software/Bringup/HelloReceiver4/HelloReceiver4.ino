// RF receiver hooked to pin 10

// Added to SoftwareSerial.cpp for 400 baud:
//   { 400,      2535,      5078,      5078,     5074,  },
//   { 400,      1263,      2536,      2536,     2531,  },

#include <SoftwareSerial.h>

SoftwareSerial mySerial(12, 13); // RX, TX

int incomingByte = 0;

void setup()
{
    Serial.begin(9600);
    mySerial.begin(400);
    Serial.println("Starting Receive...");
}

void loop()
{
  if (mySerial.available() > 0)
  {
    incomingByte = mySerial.read();
    if (incomingByte != 0)
    {
      Serial.print(incomingByte, HEX);
      if (incomingByte >= 'A' && incomingByte <= 'D')
        Serial.print("*****");
      Serial.println("");
    }
  }
  incomingByte = 0;
}

