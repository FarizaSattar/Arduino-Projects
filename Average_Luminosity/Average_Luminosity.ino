// Average Luminosity

/* The code takes multiple luminosity value from a photoresistor at regular intervals, calculates and 
prints the average luminosity over a specified number of samples. It updates every set interval. */

// Pin connected to the photoresistor
#define PHOTORESISTOR_PIN A0

// Number of samples to compute the average luminosity
#define LUMINOSITY_SAMPLES_SIZE 100

// Array to store luminosity samples
int luminositySamples[LUMINOSITY_SAMPLES_SIZE] = { 0 };

// Counter to keep track of the current sample index
int indexCounter = 0;

// Timestamp of the last luminosity reading
unsigned long lastTimeReadLuminosity = millis();

// Delay between each luminosity sample reading
unsigned long luminositySampleDelay = 50;

// Function to compute the average luminosity from the samples
int computeAverageLuminosity() {
  long sum = 0;
  for (int i = 0; i < LUMINOSITY_SAMPLES_SIZE; i++) {
    sum += luminositySamples[i];
  }
  return sum / LUMINOSITY_SAMPLES_SIZE;
}

// Function to print the average luminosity over samples
void printAverageLuminosity() {
  int average = computeAverageLuminosity();
  Serial.println("");
  Serial.print("Average luminosity for ");
  Serial.print(LUMINOSITY_SAMPLES_SIZE);
  Serial.print(" samples, taken every ");
  Serial.print(luminositySampleDelay);
  Serial.print(" milliseconds: ");
  Serial.println(average);
}

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
}

void loop() {
  unsigned long timeNow = millis();
  if (timeNow - lastTimeReadLuminosity > luminositySampleDelay) {
    lastTimeReadLuminosity += luminositySampleDelay;
    
    // Check if the required number of samples is collected
    if (indexCounter == LUMINOSITY_SAMPLES_SIZE) {
      indexCounter = 0;
      
      // Calculate and print the average luminosity
      printAverageLuminosity();
    }
    
    // Read and store the current luminosity sample
    luminositySamples[indexCounter] = analogRead(PHOTORESISTOR_PIN);
    indexCounter++;
    Serial.print(".");
  }
}
