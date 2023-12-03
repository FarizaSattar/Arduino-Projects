// Power LEDs

/* The code reads a light sensor (photoresistor) connected to an analog pin, and based on the measured luminosity, 
it controls two LEDs: one turning on when it's dark and the other adjusting its brightness based on the measured 
light intensity. */

// Define pin assignments and threshold values
#define PHOTORESISTOR_PIN A0
#define LED_1_PIN 12
#define LED_2_PIN 10
#define LUMINOSITY_NIGHT_THRESHOLD 330 // Threshold for detecting night time

void setup() {
  // Set LED pins as outputs
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
}

void loop() {
  // Read the light intensity from the photoresistor
  int luminosity = analogRead(PHOTORESISTOR_PIN);

  // Control LED 1 based on the measured luminosity
  if (luminosity < LUMINOSITY_NIGHT_THRESHOLD) {
    digitalWrite(LED_1_PIN, HIGH); // Turn on LED 1 when it's dark
  } else {
    digitalWrite(LED_1_PIN, LOW); // Turn off LED 1 when it's not dark
  }

  // Adjust brightness of LED 2 based on the measured light intensity
  int brightness = 255 - luminosity / 4; // Calculate brightness inversely proportional to light intensity
  analogWrite(LED_2_PIN, brightness); // Set LED 2 brightness level
}
