var SerialPort = require('serialport');

var serialPort = new SerialPort("/dev/ttyACM0", {
  baudrate: 9600
});

var switchon = false;


serialPort.on("open", function () {
	setInterval(function () {
	  switchon=!switchon;
	  if(switchon)
		sendCommand('1');
	  else
	    sendCommand('0');
	}, 1000)
});

function sendCommand(command)
{
   serialPort.write(command, function(err) {
    if (err) {
      return console.log('Error on write: ', err.message);
    }
  });	
}

