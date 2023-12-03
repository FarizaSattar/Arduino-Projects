// Blink 3 LEDs

/* The code defines pins for three LEDs and a button, sets LED states based on button presses, toggles LEDs' 
states, and creates functions to control LED states. */

// Define pin numbers for LEDs and the button
#define LED_1_PIN 12
#define LED_2_PIN 11
#define LED_3_PIN 10
#define BUTTON_PIN 2

// Define the number of LEDs in the array
#define LED_PIN_ARRAY_SIZE 3

// Initialize variable to track LED state
int LEDBlinkState = 1;

// Array to hold LED pins
byte LEDPinArray[LED_PIN_ARRAY_SIZE] = {LED_1_PIN, LED_2_PIN, LED_3_PIN};

// Function to set LED pin modes as output
void setLEDPinModes() {
  for (int i = 0; i < LED_PIN_ARRAY_SIZE; i++) {
    pinMode(LEDPinArray[i], OUTPUT);
  }
}

// Function to turn off all LEDs
void turnOffAllLEDs() {
  for (int i = 0; i < LED_PIN_ARRAY_SIZE; i++) {
    digitalWrite(LEDPinArray[i], LOW);
  }
}

// Function to toggle LED states based on LEDBlinkState variable
void toggleLEDs() {
  if (LEDBlinkState == 1) {
    digitalWrite(LED_1_PIN, HIGH);
    digitalWrite(LED_2_PIN, LOW);
    digitalWrite(LED_3_PIN, HIGH);
    LEDBlinkState = 2;
  } else {
    digitalWrite(LED_1_PIN, LOW);
    digitalWrite(LED_2_PIN, HIGH);
    digitalWrite(LED_3_PIN, LOW);
    LEDBlinkState = 1;
  }
}

void setup() {
  // Set the button pin as an input
  pinMode(BUTTON_PIN, INPUT);

  // Set the LED pin modes and turn off all LEDs at the beginning
  setLEDPinModes();
  turnOffAllLEDs();
}

void loop() {
  // Check if the button is pressed
  if (digitalRead(BUTTON_PIN) == LOW) {
    // Toggle the LED states when the button is pressed and add a delay
    toggleLEDs();
    delay(300);
  }
}
