// RF transmitter hooked to pin 13

// Added to SoftwareSerial.cpp for 400 baud:
//   { 400,      2535,      5078,      5078,     5074,  },
//   { 400,      1263,      2536,      2536,     2531,  },

// TODO: test that this doesn't interfere with PWM on 9

#include <SoftwareSerial.h>

SoftwareSerial mySerial(12, 13); // RX, TX

void setup()
{
    Serial.begin(9600);
    mySerial.begin(400);
    Serial.println("Starting XMit...");
}

void loop()
{
   Serial.println("Sending A");
   for(int i=0; i<20; i++)
   {
     Send('A');
   }
   
   Serial.println("Sending B");
   for(int i=0; i<20; i++)
   {
     Send('B');
   }
   
   Serial.println("Sending C");
   for(int i=0; i<20; i++)
   {
     Send('C');
   }
   
   Serial.println("Sending D");
   for(int i=0; i<20; i++)
   {
     Send('D');
   }
   
   //Go silent
   delay(1000);
 
 }
 
void Send(char val)
{
  mySerial.print(val); 
  delay(50);
}

