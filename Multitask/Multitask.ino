// Multitask

/* The code manages three different actions: adjusting the blink rate of an LED using Serial communication, 
controlling LED brightness based on a potentiometer, and toggling another LED based on a button press. */

// Define pin numbers for LEDs, button, and potentiometer
#define LED_1_PIN 12
#define LED_2_PIN 11
#define LED_3_PIN 10
#define BUTTON_PIN 2
#define POTENTIOMETER_PIN A2

// Variables to control LED1 blinking
unsigned long previousTimeLED1Blink = millis();
unsigned long blinkDelayLED1 = 500;
int LED1State = LOW;

void setup() {
  // Begin serial communication at a baud rate of 115200 and set timeout
  Serial.begin(115200);
  Serial.setTimeout(10);

  // Set pin modes for LEDs and button
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  // Adjust blink rate of LED 1 via Serial communication
  if (Serial.available() > 0) {
    int data = Serial.parseInt();
    if ((data >= 100) && (data <= 4000)) {
      blinkDelayLED1 = data;
    }
  }

  // Control blinking of LED 1 based on time and blink delay
  unsigned long timeNow = millis();
  if (timeNow - previousTimeLED1Blink > blinkDelayLED1) {
    if (LED1State == LOW) {
      LED1State = HIGH;
    } else {
      LED1State = LOW;
    }
    digitalWrite(LED_1_PIN, LED1State);
    previousTimeLED1Blink += blinkDelayLED1;
  }

  // Adjust LED2 brightness based on potentiometer value
  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  int intensity = potentiometerValue / 4;
  analogWrite(LED_2_PIN, intensity);
  
  // Toggle LED3 based on button press
  if (digitalRead(BUTTON_PIN) == HIGH) {
    digitalWrite(LED_3_PIN, HIGH);
  } else {
    digitalWrite(LED_3_PIN, LOW);
  }
}
