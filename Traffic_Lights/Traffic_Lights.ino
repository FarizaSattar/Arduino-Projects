// Traffic Lights
/* The code creates a traffic light with 3 LEDs. */

#define RED_LED 12
#define YELLOW_LED 11
#define GREEN_LED 10

void setup() {
  // Set the 3 LED pins as outputs
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  // Turn off all 3 LEDs at the beginning
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
}

void loop() {
  // Turn the red LED on and leave the rest off
  digitalWrite(RED_LED, HIGH);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);

  // 1 second delay
  delay(1000);

  // Turn the yellow LED on and leave the rest off
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);

  // 2 second delay
  delay(2000);

  // Turn the green LED on and leave the rest off
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);

  // 3 second delay
  delay(3000);
}
