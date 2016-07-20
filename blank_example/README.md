Blank example
===================
Switch on/off the LED pluged on the pin no 13

Solution 1: standalone
-----------------
Using only Arduino
- Code: Blank_single
The LED is switch on / off every 1s (classical "Blank" example)


Solution 2: command comes on the serial port
-----------------
Arduino and the 2nd program communicate via the serial port: the character 0 (to switch on) or 1 (to switch off) is sent
- Arduino code: Blank_serial
- The Arduino IDE Serial Monitor can be used to send the command 
- 2nd program (example: Processing language, switch on/off every 1s): programOtherLanguage/BlankSerialProcessing
!! Change the serial port in function of the port used to communicate with the Arduino

