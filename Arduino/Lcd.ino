#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//20x4
char array1[] = "TEST..........";
char array2[] = "TEST..........";
char array3[] = "TEST..........";
char array4[] = "TEST..........";

LiquidCrystal_I2C lcd(0x27, 20, 4);
void setup()
{
    lcd.init();
    lcd.backlight();

    lcd.print(array1);

    lcd.setCursor(0, 1);
    lcd.print(array2);

    lcd.setCursor(0, 2);
    lcd.print(array3);

    lcd.setCursor(0, 3);
    lcd.print(array4);
}
void loop()
{}