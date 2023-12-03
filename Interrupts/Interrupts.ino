// Interrupts

/* The code initializes and controls three LEDs (blinking LED1, toggling LED2 and LED3) based on button presses 
while using debouncing for stable input recognition. */

// Define pin numbers for LEDs and button
#define LED_1_PIN 12
#define LED_2_PIN 11
#define LED_3_PIN 10
#define BUTTON_PIN 2

// Initialize variables for LED blink, button, and LED toggling
unsigned long lastTimeLED1Blinked = millis(); // Time tracking for LED1 blinking
unsigned long blinkDelayLED1 = 1000; // Blink interval for LED1
byte LED1State = LOW; // State of LED1

unsigned long lastTimeButtonChanged = millis(); // Time tracking for button debounce
unsigned long debounceDelay = 50; // Debounce duration for button press
byte buttonState = LOW; // State of the button

int toggleLEDState = 1; // State tracker for LED2 and LED3 toggling

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

// Function to toggle LED2 and LED3 states
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

  // Toggle LED2 and LED3 based on button press with debouncing
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
