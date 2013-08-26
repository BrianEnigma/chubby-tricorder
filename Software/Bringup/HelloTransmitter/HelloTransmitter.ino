#include <Wire.h>
#include "VirtualWire.h"

void setup()   
{                
  //Serial.begin(9600);
  pinMode(13, OUTPUT);     
  pinMode(A5, OUTPUT);     

  // Wireless init
  vw_set_tx_pin(A5);
  vw_setup(2000);	 // Bits per sec
}

void loop()
{
  const char *msg = "hello";
  digitalWrite(13, true); // Flash a light to show received good message
  vw_send((uint8_t *)msg, strlen(msg));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13, false); // Flash a light to show received good message
  delay(1000);
}

