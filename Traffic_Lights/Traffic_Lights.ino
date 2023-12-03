// Traffic Lights

/* The code sequentially blinks three LEDs connected to pins 12, 11, and 10, with varying delays to create
 different blinking patterns. */

 // Define the pin numbers for three LEDs
#define LED_1_PIN 12
#define LED_2_PIN 11
#define LED_3_PIN 10

void setup() {
  // Set the pin modes for the three LEDs as output pins
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);

  // Turn off all LEDs at the beginning
  digitalWrite(LED_1_PIN, LOW);
  digitalWrite(LED_2_PIN, LOW);
  digitalWrite(LED_3_PIN, LOW);
}

void loop() {
  // First LED on, others off, delay for 3 seconds
  digitalWrite(LED_1_PIN, HIGH);
  digitalWrite(LED_2_PIN, LOW);
  digitalWrite(LED_3_PIN, LOW);
  delay(3000);

  // Second LED on, others off, delay for 3 seconds
  digitalWrite(LED_1_PIN, LOW);
  digitalWrite(LED_2_PIN, LOW);
  digitalWrite(LED_3_PIN, HIGH);
  delay(3000);

  // Third LED on, others off, delay for 1 second
  digitalWrite(LED_1_PIN, LOW);
  digitalWrite(LED_2_PIN, HIGH);
  digitalWrite(LED_3_PIN, LOW);
  delay(1000);
}
