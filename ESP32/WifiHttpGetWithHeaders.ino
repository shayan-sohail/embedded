#include <WiFi.h>
#include <HTTPClient.h>

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
        HTTPClient client;
        client.begin("Absolute-URI");
        client.addHeader("Header-Name", "Header-Value");
        int httpCode = client.GET();
        if (httpCode > 0)
        {
            String payload = client.getString();
            Serial.println("\nStatus Code: " + String(httpCode));
            Serial.println(payload);
            client.end();
        }
        else
        {
            Serial.println("HTTP Error");
        }
        delay(1000);
    }
    else
    {
        Serial.println("Connection Lost");
    }
    delay(1000);
}