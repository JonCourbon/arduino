#include <aJSON.h>

aJsonStream serial_stream(&Serial);


// listing of inputs/outpus
#define PIN_LED13 13

int numberofswitchon;



void setup(){
  // 13 as output
  pinMode(PIN_LED13,OUTPUT);  
  numberofswitchon=0;
  
  digitalWrite(PIN_LED13, LOW);

  Serial.begin(115200);
  
}

void loop(){
  if (serial_stream.available()) {
    /* First, skip any accidental whitespace like newlines. */
    serial_stream.skip();
  }
  if (serial_stream.available()) {
    /* Something real on input, let's take a look. */
    aJsonObject *msg = aJson.parse(&serial_stream);
    processMessage(msg);
    aJson.deleteItem(msg);
  } 
}

void processMessage(aJsonObject *msg)
{
  
  aJsonObject* name = aJson.getObjectItem(msg, "text");
  if(name)
  {
    char *text=name->valuestring;
    String message = String(text);
  }
  name = aJson.getObjectItem(msg, "switchLED13");
  if(name)
  {
    char allumer=name->valuebool;
    if(allumer == true)
    {
		digitalWrite(PIN_LED13, HIGH);
		numberofswitchon++;
		sendMessage();
    }
    else
    {
		digitalWrite(PIN_LED13, LOW);
    }
  }

}


void sendMessage(){

  // send the numberofswitchon
  aJsonObject *msg = aJson.createObject();
  aJson.addStringToObject(msg, "type", "message");
  aJson.addNumberToObject(msg, "numberofswitchon",numberofswitchon);
  aJson.print(msg, &serial_stream);
  Serial.println(); /* Add newline. */
  aJson.deleteItem(msg);
  
  delay(300);
}


