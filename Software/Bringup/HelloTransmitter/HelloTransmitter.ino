// Simple bring-up of the RF module using VirtualWire, connected to pin A5.
// Enable LED while transmitting.
#include <Wire.h>
#include "VirtualWire.h"

void setup()   
{                
  pinMode(13, OUTPUT);     
  pinMode(A5, OUTPUT);     

  // Wireless init
  vw_set_tx_pin(A5);
  vw_setup(2000);	 // Bits per sec
}

void loop()
{
  const char *msg = "hello";
  digitalWrite(13, true); // Flash light to indicate transmitting
  vw_send((uint8_t *)msg, strlen(msg));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13, false);
  delay(1000);
}

