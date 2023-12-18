#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>

PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);

void setup(void)
{
    Serial.begin(9600);
    Serial.println("NFC Tag Cleaner");
    nfc.begin();
}

void loop(void) {

    Serial.println("Press the card you want to clear.");

    if (nfc.tagPresent()) {
        bool success = nfc.clean();
        if (success)
            Serial.println("\nSuccessful, the card is returned to the default settings.");
        else
            Serial.println("\nError, clearing the card is unsuccessful.");
    }

    delay(2000);
}