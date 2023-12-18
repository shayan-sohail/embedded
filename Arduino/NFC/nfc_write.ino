#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>

PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);
//Format nahi karna, wo corrupt kar deta hai, Erase/delete tag karna hai
void setup()
{
    Serial.begin(9600);
    Serial.println("NDEF Writer");
    nfc.begin();
}

void loop() {
    Serial.println("Press the formatted card against the reader.");
    if (nfc.tagPresent())
    {
        NdefMessage message = NdefMessage();
        message.addUriRecord("Hello 1!");
        message.addUriRecord("Hello 2!");
        message.addUriRecord("Hello 3!");

        bool success = nfc.write(message);
        if (success)
            Serial.println("Successful. Try reading the message using reader or mobile phone.");
        else
            Serial.println("Writing unsuccessful.");
    }
    delay(2000);
}