// Debounce Push Button
/* The code manages causes a red LED to blink at a specific interval, toggles a yellow LED 
and green LED when a push button is pressed with debouncing. */

#define RED_LED 12
#define YELLOW_LED 11
#define GREEN_LED 10
#define PUSH_BUTTON 2

// Initialize variables for the LEDs to blink, and toggle with a push button
unsigned long lastTimeRedLEDBlinked = millis();
unsigned long blinkDelayRedLED = 1000;
byte RedLEDState = LOW;

unsigned long lastTimeButtonChanged = millis();
unsigned long debounceDelay = 50;
byte pushButtonState = LOW;

int toggleLEDState = 1;

void setup() {
  // Intialize LEDs and push button
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(PUSH_BUTTON, INPUT);
  pushButtonState = digitalRead(PUSH_BUTTON);
}

// Allows red LED to blink
void blinkRedLED() {
  if (RedLEDState == HIGH) {
    RedLEDState = LOW;
  } else {
    RedLEDState = HIGH;
  }
  digitalWrite(RED_LED, RedLEDState);
}

// Toggle the state of the yellow and green LEDs
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

  // Allows red LED to blink at a specific time
  if (timeNow - lastTimeRedLEDBlinked > blinkDelayRedLED) {
    lastTimeRedLEDBlinked += blinkDelayRedLED;
    blinkRedLED();
  }

  // Toggles yellow and green LED when the push button is pressed with debouncing
  if (timeNow - lastTimeButtonChanged > debounceDelay) {
    byte newpushButtonState = digitalRead(PUSH_BUTTON);
    if (newpushButtonState != pushButtonState) {
      lastTimeButtonChanged = timeNow;
      pushButtonState = newpushButtonState;
      if (pushButtonState == HIGH) {
        toggleOtherLEDs();
      }
    }
  }
}
