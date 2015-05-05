#include <Wirefree.h>
#include <WifiClient.h>
WIFI_PROFILE wireless_prof = {
  /* SSID */ "Elwe",
  /* WPA/WPA2 passphrase */ "asdfghjkl",
  /* Robot IP address */ "192.168.43.26",
  /* subnet mask */ "255.255.255.0",
  /* Gateway IP */ "192.168.43.1", };
String remote_server = "192.168.43.90"; // peer device IP address.
String remote_port = "9876"; // arbitrary
// Initialize client with IP address and port number
WifiClient client(remote_server, remote_port, PROTO_UDP);

void setup()
{
  Serial.begin(9600);
  // connect to AP
  Wireless.begin(&wireless_prof);
  
  // if you get a connection, report back via serial:
  if (client.connect()) {
    Serial.println("connected");
    
    // Send message over UDP socket to peer device
    client.println("Hello server!");
  } 
  else {
    // if connection setup failed:
    Serial.println("failed");
  }
}

void loop()
{
  // if there are incoming bytes available 
  // from the peer device, read them and print them:
  if (client.available()) {
    char in;
    in = client.read();
    //Serial.println(in);
    delay(100);
    client.println(in);
  }
  
  if(!client.connected())
  {
    Serial.println("disconnecting");
    client.stop();
    while(1);
  }
 
}
