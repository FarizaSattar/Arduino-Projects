// Blink 3 LEDs

/* The code controls the states of all 3 LEDs with a push button. */

#define RED_LED 12
#define YELLOW_LED 11
#define GREEN_LED 10
#define PUSH_BUTTON_PIN 2

// Define the number of LEDs in the array
#define LED_ARRAY 3

// Initialize variable to track LED state
int LEDBlinkState = 1;

// Array to hold LED pins
byte LEDPinArray[LED_ARRAY] = {RED_LED, YELLOW_LED, GREEN_LED};

// Function to set LED pin modes as output
void setLEDPinModes() {
  for (int i = 0; i < LED_ARRAY; i++) {
    pinMode(LEDPinArray[i], OUTPUT);
  }
}

// Function to turn off all LEDs
void turnOffAllLEDs() {
  for (int i = 0; i < LED_ARRAY; i++) {
    digitalWrite(LEDPinArray[i], LOW);
  }
}

// Function to toggle LED states based on LEDBlinkState variable
void toggleLEDs() {
  if (LEDBlinkState == 1) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    LEDBlinkState = 2;
  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    LEDBlinkState = 1;
  }
}

void setup() {
  // Set the button pin as an input
  pinMode(PUSH_BUTTON_PIN, INPUT);

  // Set the LED pin modes and turn off all LEDs at the beginning
  setLEDPinModes();
  turnOffAllLEDs();
}

void loop() {
  // Check if the button is pressed
  if (digitalRead(PUSH_BUTTON_PIN) == LOW) {
    // Toggle the LED states when the button is pressed and add a delay
    toggleLEDs();
    delay(300);
  }
}
