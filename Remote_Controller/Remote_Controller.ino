// Remote Controller

/* The code uses an IR remote to control and toggle LEDs while displaying commands and actions on an LCD screen 
based on the received IR signals corresponding to specific buttons. */

#include <IRremote.h>
#include <LiquidCrystal.h>

// Define LCD pins
#define LCD_RS_PIN A5
#define LCD_E_PIN A4
#define LCD_D4_PIN 6
#define LCD_D5_PIN 7
#define LCD_D6_PIN 8
#define LCD_D7_PIN 9

// Define LED pins
#define LED_1_PIN 12
#define LED_2_PIN 11
#define LED_3_PIN 10

// Define IR receiver pin and IR button codes
#define IR_RECEIVE_PIN 5
#define IR_BUTTON_0 22
#define IR_BUTTON_1 12
#define IR_BUTTON_2 24
#define IR_BUTTON_3 94
#define IR_BUTTON_FUNC_STOP 71

#define LED_ARRAY_SIZE 3

// Arrays to store LED pins and their states
byte LEDArray[LED_ARRAY_SIZE] = {LED_1_PIN, LED_2_PIN, LED_3_PIN};
byte LEDStateArray[LED_ARRAY_SIZE] = {LOW, LOW, LOW};

LiquidCrystal lcd(LCD_RS_PIN, LCD_E_PIN, LCD_D4_PIN,
                  LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

// Initialize LED pin modes
void initLEDModes() {
  for (int i = 0; i < LED_ARRAY_SIZE; i++) {
    pinMode(LEDArray[i], OUTPUT);
  }
}

// Turn off all LEDs
void powerOffAllLEDs() {
  for (int i = 0; i < LED_ARRAY_SIZE; i++) {
    LEDStateArray[i] = LOW;
    digitalWrite(LEDArray[i], LOW);
  }
}

// Toggle an LED based on its index in the array
void toggleLEDFromIndex(int index) {
  if (index >= LED_ARRAY_SIZE) {
    return;
  }
  if (LEDStateArray[index] == HIGH) {
    LEDStateArray[index] = LOW;
  } else {
    LEDStateArray[index] = HIGH;
  }
  digitalWrite(LEDArray[index], LEDStateArray[index]);
}

// Print command on the LCD
void printCommandOnLCD(int command) {
  lcd.setCursor(0, 0);
  lcd.print(command);
  lcd.print("      ");
}

// Print action on the LCD
void printActionOnLCD(String action) {
  lcd.setCursor(0, 1);
  lcd.print(action);
}

void setup() {
  IrReceiver.begin(IR_RECEIVE_PIN); // Begin IR receiver
  initLEDModes(); // Initialize LED modes
  lcd.begin(16, 2); // Begin LCD display
}

void loop() {
  if (IrReceiver.decode()) { // If an IR signal is received
    IrReceiver.resume(); // Resume receiving IR signals
    int command = IrReceiver.decodedIRData.command; // Get the received command
    switch (command) {
      case IR_BUTTON_0: {
        powerOffAllLEDs(); // Power off all LEDs
        printCommandOnLCD(command);
        printActionOnLCD("Power off LEDs. ");
        break;
      }
      case IR_BUTTON_1: {
        toggleLEDFromIndex(0); // Toggle LED 1
        printCommandOnLCD(command);
        printActionOnLCD("Toggle LED 1.   ");
        break;
      }
      case IR_BUTTON_2: {
        toggleLEDFromIndex(1); // Toggle LED 2
        printCommandOnLCD(command);
        printActionOnLCD("Toggle LED 2.   ");
        break;
      }
      case IR_BUTTON_3: {
        toggleLEDFromIndex(2); // Toggle LED 3
        printCommandOnLCD(command);
        printActionOnLCD("Toggle LED 3.   ");
        break;
      }
      case IR_BUTTON_FUNC_STOP: {
        lcd.clear(); // Clear LCD display
        break;
      }
      default: {
        printCommandOnLCD(command);
        printActionOnLCD("Not recognized. ");
      }
    }
  }
}
