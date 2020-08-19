/* 
 *  This program creates web server in NodeMCU.
 *  Provides two buttons to client to turn pin on and off.
 */

#include <ESP8266WiFi.h>

const char *ssid = "s";
const char *password = "harrypotter";

int ledPin = D7;
WiFiServer server(80);          // Port number

void setup() {

  Serial.begin(115200);
  delay(10); 

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  // Retry while wifi is not connected
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address 
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  Serial.println();
  
}

void loop() {
  // put your main code here, to run repeatedly:

  // Check if client has connected
  WiFiClient client = server.available();
  if(!client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()) {
    delay(1);
  }

  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Match the request
  int value = LOW;
  if(request.indexOf("/LED=ON") != -1) {
    digitalWrite(ledPin, HIGH);
    value = HIGH;
  }
  if(request.indexOf("/LED=OFF") != -1){
    digitalWrite(ledPin, LOW);
    value = LOW;
  }


  // Set LED pin accirdig to the request
  // digitalWrite(ledPin, value);

  // Return the reaponse
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");       // Important; don't forget
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");

  client.print("Led pin is now: ");
  if(value == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }

  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>Turn on</button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Turn off</button></a>");
  client.println("</html>");

  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
  
}
