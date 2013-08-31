// Receiver hooked to pin 2. LED on 13 ganged to pin 2's value.

#include <Wire.h>

void setup()
{
    Serial.begin(9600);	// Debugging only
    Serial.println("setup");

    pinMode(2, INPUT);     
    pinMode(13, OUTPUT);     
}

void loop()
{
    digitalWrite(13, digitalRead(2));
}

