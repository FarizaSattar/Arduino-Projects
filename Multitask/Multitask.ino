// Multitask

/* The code adjusts the LED blink delay with the serial monitor, controls the LED brightness
with a potentiometer, and toggles another LED with a push button. */

#define RED_LED 12
#define YELLOW_LED 11
#define GREEN_LED 10
#define PUSH_BUTTON_PIN 2
#define POTENTIOMETER_PIN A2

// Control red LED blinking
unsigned long previousTimeRedLEDBlink = millis();
unsigned long blinkDelayRedLED = 500;
int RedLEDState = LOW;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);

  // Initalize 3 LEDs and push button
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(PUSH_BUTTON_PIN, INPUT);
  pinMode(POTENTIOMETER_PIN, INPUT);
}

void loop() {
  // Adjust blink rate of red LED via Serial monitor
  if (Serial.available() > 0) {
    int userBlinkDelay = Serial.parseInt();
    if ((userBlinkDelay >= 100) && (userBlinkDelay <= 4000)) {
      blinkDelayRedLED = userBlinkDelay;
    }
  }

  // User can control the blinking of the red LED 
  unsigned long timeNow = millis();
  if (timeNow - previousTimeRedLEDBlink > blinkDelayRedLED) {
    if (RedLEDState == LOW) {
      RedLEDState = HIGH;
    } else {
      RedLEDState = LOW;
    }
    digitalWrite(RED_LED, RedLEDState);
    previousTimeRedLEDBlink += blinkDelayRedLED;
  }

  // Adjust the brightness of the yellow LED based on the potentiometer value
  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  int intensity = potentiometerValue / 4;
  analogWrite(YELLOW_LED, intensity);
  
  // Toggle green LED on and off based on button press
  if (digitalRead(PUSH_BUTTON_PIN) == HIGH) {
    digitalWrite(GREEN_LED, HIGH);
  } else {
    digitalWrite(GREEN_LED, LOW);
  }
}
