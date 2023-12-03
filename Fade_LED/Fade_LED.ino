// Fade LED

/* The code sets up a LED connected to pin 11 to gradually increase and then decrease in brightness using PWM 
(Pulse Width Modulation) without serial communication. */

#define LED_PIN 11 // Define the pin for the LED as pin 11

void setup() {
  // Serial.begin(9600); // Initialize serial communication (commented out)
  pinMode(LED_PIN, OUTPUT); // Set the LED pin as an output
}

void loop() {
  for (int i = 0; i <= 255; i++) { // Loop to increase LED brightness from 0 to 255
    // Serial.println(i); // Serial print current brightness (commented out)
    analogWrite(LED_PIN, i); // Set LED brightness using PWM
    delay(5); // Pause for a short duration
  }

  for (int i = 255; i >= 0; i--) { // Loop to decrease LED brightness from 255 to 0
    // Serial.println(i); // Serial print current brightness (commented out)
    analogWrite(LED_PIN, i); // Set LED brightness using PWM
    delay(5); // Pause for a short duration
  }
}
