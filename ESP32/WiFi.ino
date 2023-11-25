#include <WiFi.h>

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
        //Bijness logic
        delay(5000);
    }
    else
    {
        Serial.println("Connection Lost");
    }
}