#include "Wire.h"
#include "Openhab.h"
#include <ESP8266WiFi.h>

const char* ssid = "....";
const char* password = "....";

const char* host = "10.1.1.85";
const int port = 8080;

Openhab client = Openhab(host, port);

String item_name = "Test_Thing";

void sendToOpenHab(String value) {
  String response = client.put(item_name, value);
  Serial.print(response);
}


void setup() {
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

 
 
void loop() {
  float temp = 23.3; 
  char buf[100];
  dtostrf(temp, 6, 4, buf);
  sendToOpenHab(buf);

  delay(5000); //wait 5 seconds before printing our next set of readings.
}



