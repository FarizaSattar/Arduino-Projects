// Serial Monitors

/* The code uses millis() to control the blinking of an LED connected to pin 12, with a blink rate that can be
 adjusted through Serial communication while ensuring consistent timing intervals without relying on delay(). */

// Define the pin number for the LED
#define LED_PIN 12

// Initialize variables for time tracking and LED state
unsigned long previousTimeLEDBlink = millis(); // Variable to track the previous time of LED blink
unsigned long blinkDelay = 500; // Initial blink delay duration
int LEDState = LOW; // Initial state of the LED

void setup() {
  // Begin serial communication at a baud rate of 115200 and set timeout
  Serial.begin(115200);
  Serial.setTimeout(10);

  // Set the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Check if data is available from Serial communication
  if (Serial.available() > 0) {
    // Read the incoming data as an integer
    int data = Serial.parseInt();
    // If the received data is within the specified range, update blink delay
    if ((data >= 100) && (data <= 4000)) {
      blinkDelay = data;
    }
  }

  // Get the current time
  unsigned long timeNow = millis();

  // Check if the time elapsed since the last blink is greater than the blink delay
  if (timeNow - previousTimeLEDBlink > blinkDelay) {
    // Toggle the LED state
    if (LEDState == LOW) {
      LEDState = HIGH;
    } else {
      LEDState = LOW;
    }
    
    // Set the LED to the updated state
    digitalWrite(LED_PIN, LEDState);

    // Update the time for the next blink
    previousTimeLEDBlink += blinkDelay;
  }
}
