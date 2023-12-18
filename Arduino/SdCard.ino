#include <SD.h>
#include <SPI.h>

int CS_PIN = 53;
File file;
void setup()
{

    Serial.begin(9600);
    pinMode(CS_PIN, OUTPUT);

    if (SD.begin())
    {
        Serial.println("SD card is ready to use.");
        file = SD.open("codes.txt");
        if (file)
        {
            Serial.println("File opened with success!");
            Serial.println(readLine());
        }
        else
        {
            Serial.println("Error opening file...");
        }
        file.close();
    }
    else
    {
        Serial.println("SD card initialization failed");
    }
}

void loop()
{
}

String readLine()
{
    String received = "";
    char ch;
    while (file.available())
    {
        ch = file.read();
        if (ch == '\n')
        {
            Serial.println("String->" + received);
            return String(received);
        }
        else
        {
            received += ch;
        }
    }
    return "";
}
