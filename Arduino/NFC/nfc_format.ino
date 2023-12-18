#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>

PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);

void setup(void)
{
    Serial.begin(9600);
    Serial.println("NDEF Formatting.");
    nfc.begin();
}

void loop(void)
{
    Serial.println("Press the unformatted card or tag against the module");
    if (nfc.tagPresent())
    {
        bool success = nfc.format();
        if (success)
            Serial.println("\nThe card (tag) successfully formatted in the NTAG.");
        else
            Serial.println("\nUnsuccessful formatting.");
    }
    delay(2000);
}