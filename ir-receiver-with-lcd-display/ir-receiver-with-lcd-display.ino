#include <IRremote.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int IR_RECEIVER_PIN = 6;

String BUTTON_VALUES[42] = {
  "POWER",
  "ba45ff00",
  "VOLUME_UP",
  "b946ff00",
  "FUNCTION_STOP",
  "b847ff00",
  "REWIND",
  "bb44ff00",
  "PLAY_PAUSE",
  "bf40ff00",
  "FORWARD",
  "bc43ff00",
  "DOWN",
  "f807ff00",
  "VOLUME_DOWN",
  "ea15ff00",
  "UP",
  "f609ff00",
  "0",
  "e916ff00",
  "EQ",
  "e619ff00",
  "ST_REPT",
  "f20dff00",
  "1",
  "f30cff00",
  "2",
  "e718ff00",
  "3",
  "a15eff00",
  "4",
  "f708ff00",
  "5",
  "e31cff00",
  "6",
  "a55aff00",
  "7",
  "bd42ff00",
  "8",
  "ad52ff00",
  "9",
  "b54aff00"
};

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVER_PIN, true);
  lcd.begin(16, 2);
}

void loop() {
  if (IrReceiver.decode()) {
    String data = String(IrReceiver.decodedIRData.decodedRawData, HEX);
    for (int i = 0; i < 42; i++) {
      if (data != "0" && data == BUTTON_VALUES[i]) {
        lcd.clear();
        lcd.print(BUTTON_VALUES[i - 1]);
        break;
      }
    }
    IrReceiver.resume();
  }
}
