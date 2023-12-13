// EEPROM
/* The code initializes a maximum brightness value stored in EEPROM, updates it with
a serial monitor, and adjusts brightness the brightness of a green LED based on a 
potentiometer. */

#include <EEPROM.h>  // Include EEPROM library to read/write from/to EEPROM memory

#define GREEN_LED 10  
#define POTENTIOMETER A2  
#define EEPROM_ADDRESS_MAX_BRIGHTNESS 350 
#define MAX_BRIGHTNESS_DEFAULT 255  

// Holds the maximum brightness value
byte maxBrightness;  

void setup() {

  // Initializes LED and serial monitor
  Serial.begin(9600);  
  Serial.setTimeout(10); 
  pinMode(GREEN_LED, OUTPUT);  

  // Reads the maximum brightness value stored in EEPROM
  maxBrightness = EEPROM.read(EEPROM_ADDRESS_MAX_BRIGHTNESS);

  // If the EEPROM value is 0, set it to the default maximum brightness
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
  byte LEDBrightness = analogRead(POTENTIOMETER) / 4;

  // Limit LED brightness to the maximum set brightness value
  if (LEDBrightness > maxBrightness) {
    LEDBrightness = maxBrightness;
  }

  // Set the LED brightness using PWM based on the calculated value
  analogWrite(GREEN_LED, LEDBrightness);
}
