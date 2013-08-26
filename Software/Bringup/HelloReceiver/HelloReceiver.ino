// Receiver hooked to pin 8.
// 128x32 SPI display hooked to 9..13

#include <Wire.h>
#include <VirtualWire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_DC 11
#define OLED_CS 12
#define OLED_CLK 10
#define OLED_MOSI 9
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

void setup()
{
    Serial.begin(9600);	// Debugging only
    Serial.println("setup");

    display.begin(SSD1306_SWITCHCAPVCC);
    display.clearDisplay();   // clears the screen and buffer
    display.display();
    display.setCursor(0,0);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.println("Receiving...");
    display.display();

    pinMode(2, INPUT);     

    // Initialise the IO and ISR
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);	 // Bits per sec
    vw_set_rx_pin(2);
    vw_rx_start();       // Start the receiver PLL running
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
	int i;

	// Message with a good checksum received, dump it.
	Serial.print("Got: ");
        display.fillRect(0,0,127,31,BLACK);
        display.setTextSize(1);
        display.setTextColor(WHITE);
	display.setCursor(0,0);
	for (i = 0; i < buflen; i++)
	{
            if (buf[i] > ' ' && buf[i] <= '~')
            {
	      Serial.print("\"");
	      Serial.write(buf[i]);
	      Serial.print("\" ");
              display.write(buf[i]);
            } else {
              Serial.print(buf[i], HEX);
	      Serial.print("   ");
              display.write('?');
            }
	}
        display.println("");
        display.display();
	Serial.println("");
    }
}

