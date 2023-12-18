#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

char jsonOutput[128];

void setup()
{
    Serial.begin(115200);
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
        client.begin("http://jsonplaceholder.typicode.com/posts");
        client.addHeader("Content-Type", "application/json");

        const size_t CAPACITY = JSON_OBJECT_SIZE(1);
        StaticJsonDocument<CAPACITY> doc;

        JsonObject obj = doc.to<JsonObject>();
        obj["title"] = "Sample POST message";

        serializeJson(doc, jsonOutput);

        int httpCode = client.POST(String(jsonOutput));
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
    delay(2000);
}