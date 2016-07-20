Blank example
===================
Switch on/off the LED pluged on the pin no 13

Solution 1: standalone
-----------------
Using only Arduino
- ARDUINO Build and upload: Blank_single
The LED is switch on / off every 1s (classical "Blank" example)


Solution 2: command comes on the serial port
-----------------
Arduino and the 2nd program communicate via the serial port: the character 0 (to switch on) or 1 (to switch off) is sent
- ARDUINO Build and upload: Blank_serial
- The Arduino IDE Serial Monitor can be used to send the command 
- 2nd program: send 1 or 0 every 1s
-- Processing language

!! Change the serial port in function of the port used to communicate with the Arduino
-- NodeJS: `npm install` and then `node app.js`

!! Change the serial port in function of the port used to communicate with the Arduino


Solution 3: firmata
-----------------
Firmata a generic protocol for communicating with microcontrollers like the Arduino from software on a host computer. 

- ARDUINO Build and upload: StandardFirmata
- 2nd program
-- NodeJS: `npm install` and then `node app.js`

The Johnny-Five JS library is used ([http://johnny-five.io/](http://johnny-five.io/))

[I'm an inline-style link](https://www.google.com)


