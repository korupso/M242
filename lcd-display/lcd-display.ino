#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.clear();
  lcd.begin(16, 2);
  lcd.print("Hello world!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
