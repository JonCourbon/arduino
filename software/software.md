Arduino
--------------
Arduino + Arduino IDE

About Firmata: standard elements like pinMode, digitalRead or digitalWrite are possible

Processing
--------------
Processing + Processing IDE



NodeJS
--------------
Communication between NodeJS and Arduino can be down using a serial communication or using the Firmata protocol
- Possibilities: CylonJs ([https://cylonjs.com/](https://cylonjs.com/)), Johnny-Five ([http://johnny-five.io/](http://johnny-five.io/)), ...
- Advised library: Johnny-Five because a large number of electronic components are ready to use with this library. 

Sample:
    var five = require("johnny-five");
    var board = new five.Board({
    	port: "/dev/ttyACM0"
    });
    
    board.on("ready", function() {
      var led = new five.Led(13);
      led.blink(1000);
    });
