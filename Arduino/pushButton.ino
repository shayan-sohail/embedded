const int BUTTON = 2;
const int DEBOUNCE_DELAY = 250;

/*One side is connected to ground, while the other side is connected to BUTTON*/
void setup()
{
    Serial.begin(9600);
    pinMode(BUTTON, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BUTTON), Isr, FALLING);
}

void loop()
{
}

void Isr()
{
    static unsigned long lastTime = 0;
    unsigned long currentTime = millis();
    if (currentTime - lastTime > DEBOUNCE_DELAY)
    {
        Serial.println("Button pressed!");
    }
    lastTime = currentTime;
}
