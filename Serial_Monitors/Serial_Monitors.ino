// Serial Monitors

/* The code adjusts the blinking of an LED with the serial monitor. */

#define LED_PIN 12

// LED will be turned off and have a 0.5 second delay at the beginning
int currentDelay = 500;
int LEDState = LOW;

// This variable will track the previous delay 
int previousDelay = 0;
unsigned long previousMillis = 0; 

// Set up serial monitor and LED pin
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);
  pinMode(LED_PIN, OUTPUT);
}

// Checks to make sure that the user typed in a value between 100 to 4000
void loop() {
  if (Serial.available() > 0) {
    int data = Serial.parseInt();
    if ((data >= 100) && (data <= 4000)) {
      previousDelay = currentDelay;
      currentDelay = data;
    }
  }

  // If the LED blink delay has changed, print the new value to the serial monitor
  if (currentDelay != previousDelay) {
    previousDelay = currentDelay;
    String outputString = "LED Blink Delay: " + String(currentDelay);
    Serial.println(outputString);
  }

  // Tracks the blinking of the LED when the delay changes
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= currentDelay) {
    previousMillis = currentMillis;
    if (LEDState == LOW) {
      LEDState = HIGH;
    } else {
      LEDState = LOW;
    }
    digitalWrite(LED_PIN, LEDState);
  }
}
