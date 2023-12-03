// Serial Input

/* The code utilizes a LiquidCrystal library to display user-provided text on an LCD screen, checking and 
formatting the text length before printing it, alternating between two lines on the display. */

#include <LiquidCrystal.h>

// Define LCD pins
#define LCD_RS_PIN A5
#define LCD_E_PIN A4
#define LCD_D4_PIN 6
#define LCD_D5_PIN 7
#define LCD_D6_PIN 8
#define LCD_D7_PIN 9

// Initialize LCD object with pin configuration
LiquidCrystal lcd(LCD_RS_PIN, LCD_E_PIN, LCD_D4_PIN,
                  LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

int cursorLine = 0; // Variable to keep track of the cursor line

void printUserTextOnDisplay(String text)
{
  // Validate text length
  if (text.length() > 16) {
    text = "Text too long."; // Limit text length to 16 characters
  }
  for (int i = text.length(); i < 16; i++ ) {
    text += " "; // Fill remaining characters with spaces for consistent display
  }
  // Set cursor line 0 or 1 based on previous state
  lcd.setCursor(0, cursorLine);
  // Print text on the LCD
  lcd.print(text);
  // Alternate between two lines
  if (cursorLine == 0) {
    cursorLine = 1;
  }
  else {
    cursorLine = 0;
  }
}

void setup() {
  Serial.begin(115200); // Initialize serial communication
  Serial.setTimeout(10); // Set timeout for serial input
  lcd.begin(16, 2); // Initialize LCD with 16 columns and 2 rows
}

void loop() {
  // Check for incoming serial data
  if (Serial.available() > 0) {
    String text = Serial.readString(); // Read incoming text from serial input
    printUserTextOnDisplay(text); // Call function to print the text on the LCD
  }
}
