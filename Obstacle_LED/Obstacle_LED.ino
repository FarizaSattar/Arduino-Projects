// Obstacle LED
/* The code uses ultrasonic sensors to measure distance and controls LEDs based on the measured distance with 
smoothing to reduce noise. */

// Define pin numbers for LEDs and ultrasonic sensor
#define LED_1_PIN 12
#define LED_2_PIN 11
#define LED_3_PIN 10
#define ECHO_PIN 3
#define TRIGGER_PIN 4

// Initialize variables for ultrasonic sensor functionality
unsigned long lastTimeUltrasonicTrigger = millis();
unsigned long ultrasonicTriggerDelay = 60;

volatile unsigned long pulseInTimeBegin;
volatile unsigned long pulseInTimeEnd;
volatile bool newDistanceAvailable = false;

double previousDistance = 400.0; // Initial distance value

// Function to trigger the ultrasonic sensor
void triggerUltrasonicSensor() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
}

// Function to calculate distance from ultrasonic sensor measurements
double getUltrasonicDistance() {
  double durationMicros = pulseInTimeEnd - pulseInTimeBegin;
  double distance = durationMicros / 58.0; // cm (148.0: inches)
  if (distance > 400.0) {
    return previousDistance; // Maintain previous distance if out of range
  }
  distance = previousDistance * 0.7 + distance * 0.3; // Smoothing the distance value
  previousDistance = distance;
  return distance;
}

// Interrupt service routine for ECHO_PIN changes
void echoPinInterrupt() {
  if (digitalRead(ECHO_PIN) == HIGH) { // Start measuring
    pulseInTimeBegin = micros();
  } else { // Stop measuring
    pulseInTimeEnd = micros();
    newDistanceAvailable = true;
  }
}

// Function to control LEDs based on distance
void powerLEDsFromDistance(double distance) {
  if (distance >= 100) {
    digitalWrite(LED_1_PIN, LOW);
    digitalWrite(LED_2_PIN, LOW);
    digitalWrite(LED_3_PIN, HIGH); // All LEDs ON for larger distance
  } else if (distance >= 15) {
    digitalWrite(LED_1_PIN, LOW);
    digitalWrite(LED_2_PIN, HIGH);
    digitalWrite(LED_3_PIN, LOW); // Middle LED ON for mid-range distance
  } else {
    digitalWrite(LED_1_PIN, HIGH);
    digitalWrite(LED_2_PIN, LOW);
    digitalWrite(LED_3_PIN, LOW); // Close-range LED ON for smaller distance
  }
}

void setup() {
  Serial.begin(115200); // Initialize serial communication
  pinMode(ECHO_PIN, INPUT); // Set ultrasonic sensor's ECHO_PIN as INPUT
  pinMode(TRIGGER_PIN, OUTPUT); // Set ultrasonic sensor's TRIGGER_PIN as OUTPUT
  pinMode(LED_1_PIN, OUTPUT); // Set LEDs as OUTPUT
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);

  // Attach interrupt to ECHO_PIN to handle changes
  attachInterrupt(digitalPinToInterrupt(ECHO_PIN),
                  echoPinInterrupt,
                  CHANGE);
}

void loop() {
  unsigned long timeNow = millis(); // Current time calculation
  
  // Trigger ultrasonic sensor at specified interval
  if (timeNow - lastTimeUltrasonicTrigger > ultrasonicTriggerDelay) {
    lastTimeUltrasonicTrigger += ultrasonicTriggerDelay;
    triggerUltrasonicSensor();
  }

  // Check for new distance measurement available
  if (newDistanceAvailable) {
    newDistanceAvailable = false;
    double distance = getUltrasonicDistance();
    powerLEDsFromDistance(distance); // Control LEDs based on distance
    Serial.println(distance); // Print distance value over serial
  }
}
