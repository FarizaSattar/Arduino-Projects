// Blink LED
/* The code turns an LED on for 2 seconds and off for 1 second. 
A message will be printed to the serial monitor eveytime the LED state changes */

void setup() {
  Serial.begin(9600); // Initialize the serial monitor
  pinMode(13, OUTPUT); // Initialize pin 13 as the output
}

void loop() {
  Serial.println("The LED is on!"); // Print message to serial monitor
  digitalWrite(13, HIGH); // LED is at a high state
  delay(2000); // Do nothing for 2 seconds
  Serial.println("The LED is off!"); // Print message to serial monitor
  digitalWrite(13, LOW); // LED is at a low state
  delay(1000); // Do nothing for 1 second
}