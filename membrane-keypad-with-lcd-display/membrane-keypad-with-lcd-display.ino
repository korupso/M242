#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(A1, A0, 9, 10, 11, 12);

char keyValues[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[4] = {13, 6, 5, 4};
byte colPins[4] = {3, 2, 8, 7};

Keypad keypad = Keypad( makeKeymap(keyValues), rowPins, colPins, 4, 4); 

void setup() {
  lcd.clear();
  lcd.begin(16, 2);
  lcd.print("Push button");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    lcd.clear();
    lcd.print(key);
  }
}
