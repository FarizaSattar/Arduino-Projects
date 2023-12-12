// Potentiometer

/* This code configures a potentiometer to adjust an LED's brightness */

#define LED_PIN 11
#define POTENTIOMETER_PIN A2

void setup(){
  // Initalize LED pin as an output
  pinMode(LED_PIN, OUTPUT);
}

void loop(){
  // Track the potentiometer's brightness
  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  // The LED's brightness is the potentiometer's value divided by 4 
  int LEDBrightness = potentiometerValue / 4;
  // The LED will change its brightness depending on the potentiometer's value
  analogWrite(LED_PIN, LEDBrightness);
}