#include <WiFi.h>

/*Install Arduinojson library by Benoit*/
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "WifiName";
const char* password = "WifiPassword";

void setup()
{
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(500);
    }
    Serial.println("\nConnected to WiFi");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
}

void loop()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        long rnd = random(1, 10);
        HTTPClient client;
        client.begin("http://jsonplaceholder.typicode.com/comments?id=" + String(rnd));
        int httpCode = client.GET();
        if (httpCode > 0)
        {
            String payload = client.getString();
            Serial.println("\nStatus Code: " + String(httpCode));
            Serial.println(payload);
        }
        else
        {
            Serial.println("HTTP Error");
        }
        delay(5000);
    }
    else
    {
        Serial.println("Connection Lost");
    }
    delay(10000);
}