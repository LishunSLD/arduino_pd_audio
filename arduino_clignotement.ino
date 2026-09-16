// Le code minimal

#include <Arduino.h>
#include <Chrono.h>
#include <Bounce2.h>

#define BUTTON1 2
#define BUTTON2 4
#define LED1 3
#define LED2 5

Bounce2::Button button1 = Bounce2::Button();
Bounce2::Button button2 = Bounce2::Button();

bool ledState1 = LOW;
bool ledState2 = LOW;

void setup()
{
    Serial.begin(115200);

    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    digitalWrite(LED1, ledState1);
    digitalWrite(LED2, ledState2);

    button1.attach(BUTTON1, INPUT_PULLUP);
    button2.attach(BUTTON2, INPUT_PULLUP);
    button1.setPressedState(LOW);
    button2.setPressedState(LOW);
}

void loop()
{
    button1.update();
    button2.update();

    if (button1.isPressed())
    {
        digitalWrite(LED1, HIGH);
        Serial.print("button1 ");
        Serial.print("1");
        Serial.println("");
    } else {
        digitalWrite(LED1, LOW);
    }

    if (button2.pressed())
    {
        ledState2 = !ledState2;
        digitalWrite(LED2, ledState2);
        if (ledState2)
        {
            Serial.print("button2 ");
            Serial.print("1");
            Serial.println("");
        }
        else
        {
            Serial.print("button2 ");
            Serial.print("0");
            Serial.println("");
        }
    }
}