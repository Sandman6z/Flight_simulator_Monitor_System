#include <WiFiClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <OneWire.h>

#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);
DeviceAddress insideThermometer;  // arrays to hold device address

const char* ssid     = "SFA-Senior";
const char* password = "woaisfair";

ESP8266WebServer server(80);

bool human;            // Values read from sensor
String webString = "";  // String to display

void handle_root()
{
  server.send(200, "text/plain", "Hello from ESP8266, read from /human");
  delay(100);
}

void setup(void)
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("\n\r \n\rWorking to connect");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.print("Locating devices...");
  sensors.begin();
  Serial.print("Found ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println(" devices.");

  Serial.println("");

  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handle_root);    //初始化WebServer
  server.on("/human", []() {
    webString = "区域状态: " + String(human) + "人"; // Arduino has a hard time with float to string
    server.send(200, "text/plain", webString);            // send to someones browser when asked
  });
  server.begin();
  Serial.println("HTTP server started");
}



void loop(void)
{
  Serial.print("Requesting whether Human...");
  Serial.println("DONE");

 
 


  server.handleClient();
}

void printAddress(DeviceAddress deviceAddress)  // function to print a device address
{
  for (uint8_t i = 0; i < 8; i++)
  {
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}
