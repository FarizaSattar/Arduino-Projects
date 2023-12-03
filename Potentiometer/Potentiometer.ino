// Potentiometer

/* The code sets up a connection between a potentiometer and an LED, adjusting the LED's brightness based
on the analog input from the potentiometer. */

// Define the pin numbers for the LED and potentiometer
#define LED_PIN 11
#define POTENTIOMETER_PIN A2

void setup() {
  // Set the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Read the analog value from the potentiometer
  int potentiometerValue = analogRead(POTENTIOMETER_PIN);

  // Map the potentiometer value to LED brightness (dividing by 4 for a range of 0-255)
  int LEDBrightness = potentiometerValue / 4;

  // Set the LED brightness using PWM based on the potentiometer value
  analogWrite(LED_PIN, LEDBrightness);
}

