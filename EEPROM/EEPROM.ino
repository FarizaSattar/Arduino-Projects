// EEPROM

/* The code initializes a maximum brightness value stored in EEPROM, reads and updates it through Serial 
communication, and adjusts LED brightness based on a potentiometer while limiting it to the maximum set brightness.
*/

#include <EEPROM.h>  // Include EEPROM library to read/write from/to EEPROM memory

#define LED_PIN 10  // Define the pin for the LED
#define POTENTIOMETER_PIN A2  // Define the pin for the potentiometer

#define EEPROM_ADDRESS_MAX_BRIGHTNESS 350  // Define the EEPROM address to store maximum brightness
#define MAX_BRIGHTNESS_DEFAULT 255  // Define the default maximum brightness value

byte maxBrightness;  // Variable to hold the maximum brightness value

void setup() {
  Serial.begin(115200);  // Initialize serial communication at 115200 baud rate
  Serial.setTimeout(10);  // Set the serial read timeout to 10 milliseconds
  pinMode(LED_PIN, OUTPUT);  // Set the LED pin as an output

  // Read the maximum brightness value stored in EEPROM
  maxBrightness = EEPROM.read(EEPROM_ADDRESS_MAX_BRIGHTNESS);

  // If the EEPROM value is 0 (uninitialized), set it to the default maximum brightness
  if (maxBrightness == 0) {
    maxBrightness = MAX_BRIGHTNESS_DEFAULT;
  }
}

void loop() {
  // Check if there's data available in the serial buffer
  if (Serial.available() > 0) {
    int data = Serial.parseInt();  // Read the integer value from serial input
    // Check if the received data is within the valid brightness range
    if ((data >= 0) && (data < 256)) {
      // Write the received brightness value to EEPROM and update maxBrightness variable
      EEPROM.write(EEPROM_ADDRESS_MAX_BRIGHTNESS, data);
      maxBrightness = data;
    }
  }

  // Read the analog value from the potentiometer and scale it to obtain LED brightness
  byte LEDBrightness = analogRead(POTENTIOMETER_PIN) / 4;

  // Limit LED brightness to the maximum set brightness value
  if (LEDBrightness > maxBrightness) {
    LEDBrightness = maxBrightness;
  }

  // Set the LED brightness using PWM based on the calculated value
  analogWrite(LED_PIN, LEDBrightness);
}
