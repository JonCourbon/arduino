// to be changed according to the configuration
String serialPortName="/dev/ttyACM0";


import processing.serial.*;
import org.json.*;

String texte="";
String printedMessage="";

// le port série
Serial serialPortArduino;

JSONObject jsonReceived;
JSON json;

boolean switchLED13;
int Led13statechangetime;


//=================================================== //
// initialisation
//=================================================== //
void setup() {
  	// loop frequency
  	frameRate(60);
  
  	// constructor and initialisation
  	json = JSON.createObject();
  
  
  	// Create port
  	serialPortArduino = new Serial(this, serialPortName, 115200); 
  
  	texte="";
  
  	// remove the remaining data on the serial port
  	String myString = serialPortArduino.readStringUntil('\n');
  
  	// window ... for debug only
  	size(300, 300);
  	
  	// waiting that the Arduino reboots
  	delay(2000);
  
  	// send first message
  	switchLED13=true;
  	sendMessage(switchLED13);
  	Led13statechangetime=millis();


}

//=================================================== //
// Main function
//=================================================== //
void draw(){

	background(220);
	fill(0);
        text(printedMessage,10,50);
	
	// switch the led state each 2s
	if(millis()-Led13statechangetime>2000)
	{
		switchLED13=!switchLED13;
		sendMessage(switchLED13);
		Led13statechangetime=millis();
	}
}

//=================================================== //
// serialEvent
//=================================================== //

void serialEvent(Serial p) {
	texte="";
	String receivedMessage=p.readStringUntil('\n');

	// if a message have been received
	if (receivedMessage != null) {
		texte = trim(receivedMessage); // Clean up to remove \n from println

		println(receivedMessage); // for debug

		// add code within a try catch if the recevied message is badly formatted
		try {
			json = JSON.parse(texte);

			String type=json.getString("type");

			if(type.equals("message") == true)
			{      
				int numberofswitchon=json.getInt("numberofswitchon");  
                                printedMessage="We switched on "+numberofswitchon+ " time(s) the led13";
			}

		}
		catch(Exception e){
		}

	}
}


//=================================================== //
// send message
//=================================================== //
void sendMessage(boolean switchLED13)
{    
	JSON obj= JSON.createObject();

	// add a text
	obj.setString("text", "it is a test");
	// add a number
	obj.setInt("anumber", 1);

	// add a boolean
	obj.setBoolean("switchLED13",switchLED13);

	// convert to string
	String str=obj.toString();

	// send the message
	serialPortArduino.write(str);

}
