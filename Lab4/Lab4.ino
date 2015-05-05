#include <Wirefree.h>
#include <WifiServer.h>
WIFI_PROFILE w_prof = { "networkname", /* SSID */
  "wifi_password" , /* passphrase */
  NULL, /* DHCP */
  "255.255.255.0" , /* subnet mask */
  "192.168.0.1" , /* Gateway IP */
};
// port 80 is default for HTTP
WifiServer server(80);
void parseRxData(String data)
{
  
}
void setup() {
  // connect to AP and start server
  Wireless.begin(&w_prof, &parseRxData);
  server.begin();
  delay(1000);
}
void loop()
{
  // Listen for incoming clients
  WifiClient client = server.available();
  if (client) {
  // an HTTP request ends with a blank line
  while (client.connected()) {
    if (client.available()) {
    int b;
    while((b = client.read()) == -1);
      // Process data
    }
  }
  // close the connection
  client.stop();
  }
}
