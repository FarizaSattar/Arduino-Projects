// Blink LED

/* The code initializes serial communication, sets pin 13 as an output, and continuously toggles an LED on for 2 
seconds then off for 1 second while printing status messages through the Serial monitor. */

void setup() {
  Serial.begin(9600);   // Initializes serial communication at 9600 baud rate
  pinMode(13, OUTPUT);  // Sets pin 13 as an output
}

void loop() {
  Serial.println("LED on");     // Prints "LED on" to the Serial Monitor
  digitalWrite(13, HIGH);       // Turns on the LED connected to pin 13
  delay(2000);                   // Pauses execution for 2000 milliseconds (2 seconds)
  Serial.println("LED off");    // Prints "LED off" to the Serial Monitor
  digitalWrite(13, LOW);        // Turns off the LED connected to pin 13
  delay(1000);                   // Pauses execution for 1000 milliseconds (1 second)
}
