#include <ESP8266WiFi.h>

const char* ssid = "************"; // ssid
const char* password = "***********";// password
IPAddress ip(192, 168, 1, 100); //set static ip
IPAddress gateway(192, 168, 1, 1); //set gateway
IPAddress subnet(255, 255, 255, 0);//set subnet
WiFiServer server(80);

#define led1 D1
#define led2 D2
int l1=LOW, l2=LOW;

void setup()
{
    Serial.begin(115200);
    delay(10);
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);

    // Connecting to a WiFi network
    Serial.print("\nConnecting to ");
    Serial.println(ssid);
    WiFi.config(ip, gateway, subnet);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    server.begin();
    Serial.println("Server started");

    // Print the IP address in serial monitor. It must be the same we entered above
    Serial.print("Use this URL to connect: http://");
    Serial.print(WiFi.localIP());
    Serial.println("/");
}

void loop()
{
    // Check if a client has connected
    WiFiClient client = server.available();
    if (!client)
      return;
    // Wait until the client sends some data
    Serial.println("new client");
    while(!client.available())
      delay(1);

    // Read the first line of the request
    String request = client.readStringUntil('\r');
    Serial.println(request);
    client.flush();

    // Match the request
    if (request.indexOf("/LED1=ON") != -1)
    {
      digitalWrite(LED1, HIGH);
      l1 = HIGH;
    }
    if (request.indexOf("/LED1=OFF") != -1)
    {
      digitalWrite(LED1, LOW);
      l1 = LOW;
    }

    if (request.indexOf("/LED2=ON") != -1)
    {
      digitalWrite(LED2, HIGH);
      l2 = HIGH;
    }
    if (request.indexOf("/LED2=OFF") != -1)
    {
      digitalWrite(LED2, LOW);
      l2 = LOW;
    }

    // Return the response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");                       //  do not forget this one
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head>");
    client.println( "<title>Controls</title>"
                    "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\" /> "
                    "<style>"
                    ".button {"
                      "padding: 15px 25px;"
                      "font-size: 24px;"
                      "text-align: center;"
                      "cursor: pointer;"
                      "outline: none;"
                      "color: #fff;"
                      "background-color: #4CAF50;"
                      "border: none;"
                      "border-radius: 15px;"
                      "box-shadow: 0 9px #999;"
                    "}"
                    ".button:hover {background-color: #3e8e41}"
                    ".button:active {"
                      "background-color: #3e8e41;"
                      "box-shadow: 0 5px #666;"
                      "transform: translateY(4px);"
                    "}"
                    "</style>"
                    "</head>");
    client.println("<body bgcolor=\"##ffdd99\">");

    client.println("<br>\n<br>");
    client.print("<h1>LED1 is now: ");            //Details of LED1
    if(l1 == HIGH)
      client.print("on");
    else
      client.print("Off");
    client.println("<br><a href=\"/LED1=ON\"\"><button class=\"button\">Turn On LED1</button></a>");
    client.println("<a href=\"/LED1=OFF\"\"><button class=\"button\">Turn Off LED1</button></a>");

    client.println("<br><br>");
    client.print("<h1>LED2 is now: ");            //Details of LED2
    if(l2 == HIGH)
      client.print("on");
    else
      client.print("Off");
    client.println("<br><a href=\"/LED2=ON\"\"><button class=\"button\">Turn On LED2</button></a>");
    client.println("<a href=\"/LED2=OFF\"\"><button class=\"button\">Turn Off LED2</button></a>");

    delay(1);
    Serial.println("Client disonnected");
    Serial.println("");

    if(WiFi.status() != WL_CONNECTED)
    {
      Serial.println("WiFi disconnected");
      Serial.print("Reconnecting to ");
      Serial.println(ssid);
      WiFi.config(ip, gateway, subnet);
      WiFi.begin(ssid, password);

      while (WiFi.status() != WL_CONNECTED)
      {
        delay(500);
        Serial.print(".");
      }
      Serial.println("WiFi connected"); 
}
