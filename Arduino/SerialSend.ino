void setup()
{
    Serial.begin(9600);
    Serial1.begin(9600);
}

//MEGA PIN 18-19

void loop()
{
    if (Serial.available() > 0)
    {
        Serial1.println(Serial.readString());
        Serial1.flush();
    }

    if (Serial1.available() > 0)
    {
        Serial.println("Message from Source: " + Serial1.readString());
    }
}