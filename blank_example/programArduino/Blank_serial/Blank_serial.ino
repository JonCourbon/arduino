/*
  Modified version of the Blink sample
  Turns on / off a LED depending on the character receveid on the serial port.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
#define led_pin 13

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led_pin, OUTPUT);     
  
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
}

// the loop routine runs over and over again forever:
void loop() {
}


void serialEvent(){
  char incomingChar = Serial.read();
  if(incomingChar=='0')
  {
    digitalWrite(led_pin, LOW);
  }
  else if(incomingChar=='1')
  {
    digitalWrite(led_pin, HIGH);  
  }
  // else: tabulation, space, line break, new line, ...
}
