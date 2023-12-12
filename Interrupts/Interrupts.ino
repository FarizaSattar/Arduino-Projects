// Interrupts

/* The code causes a red LED to blink, and also toggling LED2 and LED3) based on a
push button with debouncing. */


#define RED_LED 12
#define YELLOW_LED 11
#define GREEN_LED 10
#define PUSH_BUTTON 2

// Initialize variables for LED blink, button, and LED toggling
unsigned long lastTimeRedLEDBlinked = millis(); // Track blinking of red LED
unsigned long blinkDelayRedLED = 1000; // Red LED blinking delay
byte RedLEDState = LOW; // State of red LED

// Tracker for time for push button debounce
unsigned long lastTimeButtonChanged = millis(); 
unsigned long debounceDelay = 50; // Debounce delay when the push button is pressed
byte buttonState = LOW; // Tracks the state of the button

int toggleLEDState = 1; // Tracks the state of the yellow and green LED

void setup() {
  
  // Initialize LEDs and push button
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(PUSH_BUTTON, INPUT);
  buttonState = digitalRead(PUSH_BUTTON);
}

// Allows the red LED to blink
void blinkRedLED() {
  if (RedLEDState == HIGH) {
    RedLEDState = LOW;
  } else {
    RedLEDState = HIGH;
  }
  digitalWrite(RED_LED, RedLEDState);
}

// Toggle the states of the yellow and green LEDs
void toggleOtherLEDs() {
  if (toggleLEDState == 1) {
    toggleLEDState = 2;
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  } else {
    toggleLEDState = 1;
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  }
}

void loop() {
  unsigned long timeNow = millis();

  // Blinks red LED at a specified interval
  if (timeNow - lastTimeRedLEDBlinked > blinkDelayRedLED) {
    lastTimeRedLEDBlinked += blinkDelayRedLED;
    blinkRedLED();
  }

  // Toggles the yellow and green LED based on button press with debouncing
  if (timeNow - lastTimeButtonChanged > debounceDelay) {
    byte newButtonState = digitalRead(PUSH_BUTTON);
    if (newButtonState != buttonState) {
      lastTimeButtonChanged = timeNow;
      buttonState = newButtonState;
      if (buttonState == HIGH) {
        toggleOtherLEDs();
      }
    }
  }
}
