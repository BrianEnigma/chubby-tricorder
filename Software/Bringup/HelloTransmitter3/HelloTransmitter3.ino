// Simple bring-up of the RF module, using on-board UART. Connected to pin 1.
#include <Wire.h>

void setup()   
{                
  Serial.begin(400);
}

void loop()
{
   for(int i=0; i<44; i++)
   {
     Send('A');
   }
   
   for(int i=0; i<44; i++)
   {
     Send('B');
   }
   
   for(int i=0; i<44; i++)
   {
     Send('C');
   }
   
   for(int i=0; i<44; i++)
   {
     Send('D');
   }

   /*   
   //Go silent
   delay(1000);
   */
 }

void Send(char val)
{
  Serial.print(val); 
  delay(50);
}

