#include <WiFi.h>

void setup()
{
    Serial.begin(9600);
    WiFi.begin("ssid", "password");
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
        //Business logic
    }
    else
    {
        Serial.println("Connection Lost");
    }
}