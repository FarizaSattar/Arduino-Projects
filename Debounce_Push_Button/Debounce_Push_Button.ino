// Debounce Push Button

/* The code manages three LEDs, blinking LED 1 at a specific interval while toggling the states of LED 2 and 
LED 3 in response to button presses with debouncing. */

// Define pin numbers for LEDs and button
#define LED_1_PIN 12
#define LED_2_PIN 11
#define LED_3_PIN 10
#define BUTTON_PIN 2

// Initialize variables for LED blink, button, and LED toggling
unsigned long lastTimeLED1Blinked = millis();
unsigned long blinkDelayLED1 = 1000;
byte LED1State = LOW;

unsigned long lastTimeButtonChanged = millis();
unsigned long debounceDelay = 50;
byte buttonState = LOW;

int toggleLEDState = 1;

void setup() {
  // Set pin modes for LEDs and button, initialize button state
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  buttonState = digitalRead(BUTTON_PIN);
}

// Function to blink LED1
void blinkLED1() {
  if (LED1State == HIGH) {
    LED1State = LOW;
  } else {
    LED1State = HIGH;
  }
  digitalWrite(LED_1_PIN, LED1State);
}

// Function to toggle LED 2 and LED 3 states
void toggleOtherLEDs() {
  if (toggleLEDState == 1) {
    toggleLEDState = 2;
    digitalWrite(LED_2_PIN, LOW);
    digitalWrite(LED_3_PIN, HIGH);
  } else {
    toggleLEDState = 1;
    digitalWrite(LED_2_PIN, HIGH);
    digitalWrite(LED_3_PIN, LOW);
  }
}

void loop() {
  unsigned long timeNow = millis();

  // Blink LED1 at the specified interval
  if (timeNow - lastTimeLED1Blinked > blinkDelayLED1) {
    lastTimeLED1Blinked += blinkDelayLED1;
    blinkLED1();
  }

  // Toggle LED 2 and LED 3 based on button press with debouncing
  if (timeNow - lastTimeButtonChanged > debounceDelay) {
    byte newButtonState = digitalRead(BUTTON_PIN);
    if (newButtonState != buttonState) {
      lastTimeButtonChanged = timeNow;
      buttonState = newButtonState;
      if (buttonState == HIGH) {
        toggleOtherLEDs();
      }
    }
  }
}
