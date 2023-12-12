// Push Button
/* The code configures a push button to turn an LED off and on */

#define LED_PIN 11
#define PUSH_BUTTON_PIN 2

void setup(){
  // Initalize the LED and push button pins 
  pinMode(LED_PIN, OUTPUT);
  pinMode(PUSH_BUTTON_PIN, INPUT);
  
}

void loop(){
  // When the user presses on the push button, the LED will light up
  if (digitalRead(PUSH_BUTTON_PIN) == HIGH){
    digitalWrite(LED_PIN, HIGH);
  }

  else {
  // When the user stops pressing on the push button, the LED will turn off
    digitalWrite(LED_PIN, LOW);
  }
}