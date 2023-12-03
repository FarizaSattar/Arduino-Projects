// Push Button

/* The code configures an LED and a button, lighting up the LED when the button is pressed and turning it
off otherwise. */

// Assign pin numbers for the LED and the button
#define LED_PIN 11
#define BUTTON_PIN 2

void setup() {
  // Set LED pin as output and button pin as input
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  // Check if the button is pressed
  if (digitalRead(BUTTON_PIN) == HIGH) {
    // Turn on the LED if the button is pressed
    digitalWrite(LED_PIN, HIGH);
  } else {
    // Turn off the LED if the button is not pressed
    digitalWrite(LED_PIN, LOW);
  }
}

