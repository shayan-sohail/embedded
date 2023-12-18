#define RXp2 16
#define TXp2 17

//Make sure that baud rate of two devices are same here 9600
// RX of this device will be connected to the TX of the other and vice versa
void setup()
{
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
}

void loop()
{
  if (Serial.available() > 0)
  {
    Serial2.println(Serial.readString());
    Serial2.flush();
  }

  if (Serial2.available() > 0)
  {
    Serial.println("Message from Source: " + Serial2.readString());
  }
}