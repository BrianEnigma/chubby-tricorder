// RF receiver hooked to UART via pin 0

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_DC A3
#define OLED_CS A5
#define OLED_CLK A2
#define OLED_MOSI A1
#define OLED_RESET A4
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

int incomingByte = 0;

void setup()
{
    Serial.begin(400);
    display.begin(SSD1306_SWITCHCAPVCC);
    display.clearDisplay();   // clears the screen and buffer
    display.display();
    display.setCursor(0,0);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.println("Receiving...");
    display.display();
}

int counter = 0;
char str[2] = {0,0};
void loop()
{
  if (Serial.available() > 0)
  {
    incomingByte = Serial.read();
    if (incomingByte != 0)
    {
      if (incomingByte > ' ' && incomingByte <= '~')
      {
        str[0] = incomingByte;
      } else {
        str[0] = '.';
      }
      counter++;
      if (counter >= 22 * 4)
      {
        display.clearDisplay();
        display.setCursor(0,0);
        counter = 0;
      }
      display.print(str);
      display.display();
    }
  }
  incomingByte = 0;
}

