#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>

PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);

void setup(void)
{
    Serial.begin(9600);
    Serial.println("NFC Deleting data from the card");
    nfc.begin();
}

void loop(void) {

    Serial.println("Press the card you want to delete.");
    if (nfc.tagPresent()) {
        bool success = nfc.erase();
        if (success)
            Serial.println("\nSuccessful, data deleted from the card.");
        else
            Serial.println("\nUnsuccessful data deletion.");
    }

    delay(2000);
}