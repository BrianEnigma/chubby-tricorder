#include <Wire.h>
#include <Keypad.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "SoftwareSerial.h"
#include "Adafruit_Thermal.h"
#include "VirtualWire.h"
#include <avr/pgmspace.h>

// Debug settings
//#define DEBUG_FAST_STARTUP_ANIM
//#define DEBUG_SKIP_STARTUP

// Display constants

#define OLED_DC A2
#define OLED_CS A4
#define OLED_CLK A1
#define OLED_MOSI A0
#define OLED_RESET A3
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

// Keypad constants

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// Printer constants

int printer_RX_Pin = 12;  // This is the green wire
int printer_TX_Pin = 13;  // This is the yellow wire
Adafruit_Thermal printer(printer_RX_Pin, printer_TX_Pin);

// Run mode

char runMode[2] = {'1', 0};

void startupAnimation();

void setup()   
{                
  //Serial.begin(9600);

  // Display init  
  display.begin(SSD1306_SWITCHCAPVCC);
  
  // Keypad init (none)
  
  // Printer init
  printer.begin();
  
  // Wireless init
  vw_set_tx_pin(A5);
  vw_setup(2000);	 // Bits per sec
  
  // Boot sequence
#ifdef DEBUG_SKIP_STARTUP
#else
  startupAnimation();
#endif

}

void startupAnimation()
{
  unsigned char width = 5;
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.println(F("Unstable shutdown"));
  display.println(F("detected."));
  display.println(F("Initiating Power-On"));
  display.println(F("Self Test."));
  display.drawRoundRect(0, SSD1306_LCDHEIGHT / 4 * 3, SSD1306_LCDWIDTH, 15, 3, WHITE);
  display.fillRoundRect(0, SSD1306_LCDHEIGHT / 4 * 3, width, 15, 3, WHITE);
  display.display();
  while (width < SSD1306_LCDWIDTH)
  {
#ifdef DEBUG_FAST_STARTUP_ANIM
    //delay(5);
#else
    delay(500);
#endif
    width = min(width + 5, SSD1306_LCDWIDTH);
    display.fillRect(0, SSD1306_LCDHEIGHT / 2 + 4, SSD1306_LCDWIDTH, SSD1306_LCDHEIGHT / 8, BLACK);
    display.setCursor(0, SSD1306_LCDHEIGHT / 2 + 4);
    if (width < 20)
      display.print(F(" LOGIC CORE:"));
    else if (width < 40)
      display.print(F(" LOGIC CORE:GOOD"));
    else if (width < 60)
      display.print(F(" FUEL CELL:"));
    else if (width < 80)
      display.print(F(" FUEL CELL:BAD"));
    else if (width < 100)
      display.print(F(" MICROCODE:"));
    else
      display.print(F(" MICROCODE:DAMAGED"));
    
    display.fillRoundRect(0, SSD1306_LCDHEIGHT / 4 * 3, width, 15, 3, WHITE);
    display.display();
  }
}

// Print a "COMM PROBE DAMAGED splash screen and wait for a key press.
void damageSplashScreen()
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(0, 0);
  display.print(F("COMM PROBE"));
  display.setCursor(0, SSD1306_LCDHEIGHT / 8 * 2);
  display.print(F("DAMAGED"));
  display.setTextSize(1);
  display.setCursor(0, SSD1306_LCDHEIGHT - SSD1306_LCDHEIGHT / 8 - 1);
  display.print(F("Press any key..."));
  display.display();
  while(1)
  {
    if (0 != keypad.getKey())
      return;
    delay(100);
  }
}

// Interactively get an entry. Return the entry.
void getEntry(char *entry, unsigned char maxLength)
{
  unsigned int loopCount = 100;
  char key = 0;
  char pos = 0;
  *entry = 0;
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(0, SSD1306_LCDHEIGHT / 8 * 3);
  display.println(F("Enter memory address\nof repair subroutine\nto execute?"));
  display.setTextSize(2);
  display.display();

  while(1)
  {
    key = keypad.getKey();
    if (key >= '0' && key <= '9' && pos < maxLength)
    {
      entry[pos] = key;
      entry[pos + 1] = 0;
      pos++;
    }
    if ('*' == key && pos > 0)
    {
      pos--;
      entry[pos] = 0;
    }
    display.fillRect(0, SSD1306_LCDHEIGHT / 4 * 3, SSD1306_LCDWIDTH, SSD1306_LCDHEIGHT, BLACK);
    display.setCursor(0, SSD1306_LCDHEIGHT / 4 * 3);
    display.setTextColor(WHITE, BLACK);
    display.print(">");
    display.print(entry);
    display.setTextColor(BLACK, WHITE); // 'inverted' text
    display.print(" ");
    display.setTextColor(WHITE, BLACK);
    display.display();
    if ('#' == key)
      return;
    delay(10);
    if (loopCount++ >= 10)
    {
      vw_send((uint8_t *)runMode, 1);
      vw_wait_tx(); // Wait until the whole message is gone
      loopCount = 0;
    }
  }
}

unsigned char printEntry(const char *entry)
{
  PROGMEM const char *NUM_42 = "42";
  PROGMEM const char *NUM_911 = "911";
  PROGMEM const char *NUM_411 = "411";
  PROGMEM const char *NUM_JENNY = "8675309";
  if (strcmp(entry, "42") == 0)
  {
    printer.inverseOn();
    printer.println(F(" EXECUTING REPAIR CODE 42 "));
    printer.inverseOff();
    printer.println(F("\nDon't Panic!\n\n\n\n"));
    return 1;
  } else if (strcmp(entry, "911") == 0)
  {
    printer.inverseOn();
    printer.println(F(" EXECUTING REPAIR CODE 911 "));
    printer.inverseOff();
    printer.println(F("\n911 is a joke in your town.\n\n\n\n"));
    return 1;
  } else if (strcmp(entry, "411") == 0)
  {
    printer.inverseOn();
    printer.println(F(" EXECUTING REPAIR CODE 411 "));
    printer.inverseOff();
    printer.println(F("\nDirectory services are\nunavailable\n\n\n\n"));
    return 1;
  } else if (strcmp(entry, "8675309") == 0)
  {
    printer.inverseOn();
    printer.println(F(" EXECUTING REPAIR CODE 867-5309 "));
    printer.inverseOff();
    printer.println(F("\nJenny, I got your number\nI need to make you mine\nJenny, don't change your number\n867-5309\n\n\n\n"));
    return 1;
  }
  return 0;
}

void printBadEntry()
{
  unsigned char i;
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(0, 0);
  for (i = 1; i <= 21 * 4 + 2; i++)
  {
    if ('\n' != i)
    {
      display.write(i);
      display.display();
    }
  }
  display.setTextSize(2);
  for (i = 0; i < 20; i++)
  {
    display.setCursor(0, SSD1306_LCDHEIGHT / 2);
    if (i % 2 == 0)
      display.setTextColor(BLACK, WHITE);
    else
      display.setTextColor(WHITE, BLACK);
    display.print("BAD ADDR");
    display.display();
    delay(100);
  }
}

char entry[32];
void loop()
{
#ifdef DEBUG_SKIP_STARTUP
#else
  damageSplashScreen();
#endif
  while (1)
  {
    memset(entry, 0, sizeof(entry));
    getEntry(entry, 8);
    if (!printEntry(entry))
    {
      printBadEntry();
    }
  }
  
}

