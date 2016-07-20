/*
  Modified version of the Blink sample
  Turns on an LED on for one second, then off for one second, repeatedly.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
#define led_pin 13

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led_pin, OUTPUT); 
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led_pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led_pin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
