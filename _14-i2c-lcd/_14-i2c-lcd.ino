//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
// https://github.com/chaeplin/LiquidCrystal_I2C
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

// make some custom characters:
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

void setup()
{
  // default wire
  // P0_29 D14 TWI_SDA SDA1
  // P0_28 D15 TWI_SCL SCL1
  Wire.begin();
  //Wire.begin(15, 14, 400000);
  lcd.init();

  // create a new character
  lcd.createChar(0, heart);
  // create a new character
  lcd.createChar(1, smiley);
  // create a new character
  lcd.createChar(2, frownie);
  // create a new character
  lcd.createChar(3, armsDown);
  // create a new character
  lcd.createChar(4, armsUp);

  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello, world!");

  lcd.setCursor(0, 1);
  lcd.write(0);
  lcd.setCursor(1, 1);
  lcd.write(1);  
  lcd.setCursor(2, 1);
  lcd.write(2);  
  lcd.setCursor(3, 1);
  lcd.write(3);
  lcd.setCursor(4, 1);
  lcd.write(4);
}

void loop()
{
}
