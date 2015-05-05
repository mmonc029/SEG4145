#include <Wirefree.h>
#include <WifiClient.h>
#include <SoftwareSerial.h>
#include <Servo.h>
#include <Wire.h>



//Define constants 
#define TEMPSENSOR 0x68 
#define SONAR_SENSOR 22
#define BOARD_LED 13
#define LCD_PIN 18
#define LEFT_MOTOR 45
#define RIGHT_MOTOR 8
#define RIGHT_SENSOR 49
#define LEFT_SENSOR 48
#define CENTER_MOTOR 7


SoftwareSerial LCD(0, LCD_PIN);

int reg = 0x01; // Ambient temperature = 0x01


WIFI_PROFILE wireless_prof = {
  "Elwe",
  "asdfghjkl",
  "NULL",
  "255.255.255.0",
  "192.168.43.1",
};
  
String remote_server = "192.168.43.90"; 
String remote_port = "9876"; 

WifiClient client(remote_server, remote_port, PROTO_UDP);

void setup()
{


    Wireless.begin(&wireless_prof);
    Wire.begin(); // Join I2C bus
  Serial.begin(9600);
    Serial.println("test");

  if (client.connect()) {
    Serial.println("connected");
    
    // Send message over UDP socket to peer device
    client.print("Hello server!");
    //Serial.println("Waiting for command...");
  } 
  else {
    // if connection setup failed:
    Serial.println("failed");
  }

}

void loop()
{

      String x;
      x = getMessage();
      Serial.println(x);
      client.print(x);

}


String getMessage(){
	String message;
	message = "";
	int in;
	while (client.available()){
		in = client.read();
		if(in != 255 && in != -1){
			message += (char) in;
		}
	}
	return message;
}
