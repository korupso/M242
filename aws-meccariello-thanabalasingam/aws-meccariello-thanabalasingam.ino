/** Imports **/
#include <Keypad.h>
#include <LiquidCrystal.h>

/** Global Variables **/
LiquidCrystal lcd(A1, A0, 9, 10, 11, 12);

char keyValues[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte rowPins[4] = {13, 6, 5, 4};
byte colPins[4] = {3, 2, 8, 7};

Keypad keypad = Keypad(makeKeymap(keyValues), rowPins, colPins, 4, 4);

//         0123456789ABCDEF

char plant;

enum States
{
    CHOOSE_PLANT,
    OPTIONS,
    SETTINGS,
    WATER_PLANT
};

int state = CHOOSE_PLANT;

/** Functions **/
void setup()
{
    pinMode(A2, OUTPUT);
    digitalWrite(A2, HIGH);
    lcd.begin(16, 2);
    choosePlant();
    Serial.begin(9600);
}

void loop()
{
    if (digitalRead(A2) == LOW)
    {
        state = CHOOSE_PLANT;
        choosePlant();
    }

    char key = keypad.getKey();

    if (key)
    {
        if (state == CHOOSE_PLANT && (key == 'A' || key == 'B' || key == 'C' || key == 'D'))
        {
            options(key);
        }
        else if (state == OPTIONS)
        {
            if (key == '*')
            {
                settings();
            }
            else if (key == '#')
            {
                waterPlant();
            }
        }
    }
}

void choosePlant()
{
    lcd.clear();
    lcd.home();
    lcd.print("Choose a plant");
    lcd.setCursor(0, 1);
    lcd.print("[A-D]");
    state = CHOOSE_PLANT;
}

void options(char key)
{
    plant = key;
    lcd.clear();
    lcd.home();
    lcd.print("*: Settings");
    lcd.setCursor(0, 1);
    lcd.print("#: Water Plant");
    state = OPTIONS;
}

void settings()
{
    lcd.clear();
    lcd.home();
    lcd.print("Settings");
    state = SETTINGS;
}

void waterPlant()
{
    lcd.clear();
    lcd.home();
    lcd.print("Water Plant");
    state = WATER_PLANT;
}