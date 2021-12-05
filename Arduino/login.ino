#include <Keypad.h>
#include <LiquidCrystal_I2C.h> 

#define LedSucc 10
#define LedRefus 11
char* pass = "1234";
int pos = 0;
LiquidCrystal_I2C lcd(0x27,20,4);
const byte rows = 4;
const byte cols = 4;
byte rowPins [rows] = {1,2,3,4};
byte colPins [cols] = {5,6,7,8};

char keyMap [rows][cols] =
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

Keypad myKeypad = Keypad(makeKeymap(keyMap),rowPins,colPins,rows,cols);
void setup(){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("Welcome");
  lcd.setCursor(0,1);
  lcd.print("Enter Password :");
  // lcd.begin(16, 2);
  pinMode(LedSucc, OUTPUT);  
  pinMode(LedRefus, OUTPUT);
  setLocked (true);
}
void setLocked(int locked){
  
  if(locked){
    digitalWrite(LedSucc, HIGH);
    digitalWrite(LedRefus, LOW);
    }
   else{
      digitalWrite(LedSucc, LOW);
      digitalWrite(LedRefus, HIGH);
    }
}
void loop() {
  char whichKey = myKeypad.getKey();
   if(whichKey == pass[pos])
    {
      pos++;
      if(pos == 4)
    {
      setLocked(false);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("*** Verified ***");
      delay(3000);
      lcd.clear();
       lcd.setCursor(0,1);
      lcd.print("/* WELCOME */");
    }
    }
   if(whichKey == '*' || whichKey == '#' || whichKey == 'A' || whichKey == 'B' || whichKey == 'C' || whichKey == 'D')
    {
      pos = 0;
      setLocked(true);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Invalid Key");
      delay(1000);
      lcd.clear();
       lcd.setCursor(0,1);
       lcd.print("Enter Password :");
    }
  }
