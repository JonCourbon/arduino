String port="/dev/ttyACM0";
int baudrate=9600;

import processing.serial.*; 
Serial myPort;
long lastTime = 0;
boolean switchon;


void setup() {
  // create serial
  myPort = new Serial(this, port, baudrate); 
  
  // clear serial content
  myPort.readStringUntil('\n');
  
  switchon=true;
  myPort.write('1');
  
  // update time
  lastTime = millis();

}

void draw() {
  if ( millis() - lastTime > 1000 ) { // 1s
    switchon=!switchon;
    if(switchon)
      myPort.write('1');
    else
      myPort.write('0');
      
    lastTime = millis();
  }
}