// PulseIn Function

/* The code reads the ultrasonic sensor by triggering the sensor and calculating 
distance measurements based on the returned echo signal. */

#define ECHO_PIN 3
#define TRIGGER_PIN 4

// Variables to manage triggering intervals for the ultrasonic sensor
unsigned long lastTimeUltrasonicTrigger = millis(); // Time tracking for triggering
unsigned long ultrasonicTriggerDelay = 100; // Delay between triggering in milliseconds

// Function to trigger the ultrasonic sensor
void triggerUltrasonicSensor()
{
  digitalWrite(TRIGGER_PIN, LOW); // Set trigger pin to LOW
  delayMicroseconds(2); // Wait for stabilization
  digitalWrite(TRIGGER_PIN, HIGH); // Generate 10us pulse for triggering
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW); // Reset trigger pin
}

// Function to measure distance using the ultrasonic sensor
double getUltrasonicDistance()
{
  unsigned long timeBegin = micros(); // Record the start time
  double durationMicros = pulseIn(ECHO_PIN, HIGH); // Measure pulse duration
  unsigned long timeEnd = micros(); // Record the end time
  unsigned long codeDuration = timeEnd - timeBegin; // Calculate code execution duration
  Serial.print("Duration :");
  Serial.println(codeDuration); // Print code execution duration for debugging
  double distance = durationMicros / 58.0; // Convert pulse duration to distance in centimeters
  return distance; // Return calculated distance
}

void setup() {
  Serial.begin(115200); // Initialize serial communication
  pinMode(ECHO_PIN, INPUT); // Set the ECHO pin as input to receive the echo signal
  pinMode(TRIGGER_PIN, OUTPUT); // Set the TRIGGER pin as output to send trigger signals
}

void loop() {
  unsigned long timeNow = millis(); // Record current time
  
  // Check if it's time to trigger the ultrasonic sensor
  if (timeNow - lastTimeUltrasonicTrigger > ultrasonicTriggerDelay) {
    lastTimeUltrasonicTrigger += ultrasonicTriggerDelay; // Increment the trigger time
    triggerUltrasonicSensor(); // Trigger the ultrasonic sensor
    Serial.println(getUltrasonicDistance()); // Print the measured distance
  }
}
