#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 20 chars and 4 line display

String oneDisplay;
String twoDisplay;
String threeDisplay;
String fourDisplay;

int screenPos = 0;

byte baseline[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B00000,
  B00000,
  B00000
};

byte play[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte darkMatter[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

String one = String("\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x2\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x2\x1\x1\x1\x1\x1\x1\x2\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1");
String two = String("\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x2\x1\x1\x1\x1\x1\x1\x1\x2\x1\x1\x1\x2\x1\x1\x1\x1\x1\x1\x2\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1");
String three = String("\x1\x2\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x2\x1\x1\x1\x1\x1\x1\x1\x2\x1\x1\x2\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1");
String four = String("\x1\x1\x1\x1\x1\x2\x1\x1\x1\x1\x1\x1\x2\x1\x1\x1\x1\x1\x1\x1\x2\x1\x1\x1\x1\x1\x1\x2\x1\x1\x2\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1");

void setup() {
  // put your setup code here, to run once:

  lcd.init();
  lcd.backlight();
  
  lcd.createChar(1, baseline);
  lcd.createChar(2, play);
  lcd.createChar(3, darkMatter);

  Serial.begin(9600);

  reDraw();
}

void reDraw () {
  drawLevel(); // Draw the background level swag
  //collisionDetection();  // Finds out if the player has collided with a game object they're ontop of
}

void drawLevel() {
  oneDisplay = one.substring(screenPos,(screenPos+20)); // Get the top substring of the current position of the level (Level 1) 16 screen characters
  twoDisplay = two.substring(screenPos,(screenPos+20)); // Get the bottom substring of the current position of the level (Level 1) 16 screen characters
  threeDisplay = three.substring(screenPos,(screenPos+20));
  fourDisplay = four.substring(screenPos,(screenPos+20));
  
  lcd.setCursor(0,0);
  lcd.print(oneDisplay);
  lcd.setCursor(0,1);
  lcd.print(twoDisplay);
  lcd.setCursor(0,2);
  lcd.print(threeDisplay);
  lcd.setCursor(0,3);
  lcd.print(fourDisplay);
}


void loop() {
  // put your main code here, to run repeatedly:
  one.remove(0);
  one.remove(0);
  one.remove(0);
  two.remove(0);
  two.remove(0);
  two.remove(0);
  three.remove(0);
  three.remove(0);
  three.remove(0);
  four.remove(0);
  four.remove(0);
  four.remove(0);
  drawLevel();
  
}
