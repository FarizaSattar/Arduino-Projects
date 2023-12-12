// Fade LED
/* The code allows a LED to gradually increase and decrease its brightness level */

#define LED_PIN 11

void setup() {
  // Set LED as the output
  pinMode(LED_PIN, OUTPUT);
}

void loop(){

  // Increase the LED's brightness from 0 to 255
  for (int led_brightness = 0; led_brightness <= 255; led_brightness++) {
    analogWrite(LED_PIN, led_brightness);
    delay(5);
}

  // Decrease the LED's brightness from 255 to 0
  for (int led_brightness = 255; led_brightness >= 0; led_brightness--) {
    analogWrite(LED_PIN, led_brightness);
    delay(5);
  }
}