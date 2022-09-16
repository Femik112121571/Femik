#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,3,2);

int t=0;
int flag=0;
int d=0;
int v=0;
int v2=0;

void setup() 
{
  lcd.begin(16,2);
  pinMode(8,INPUT);
}
void loop() 
{
  d=digitalRead(8);
  if((d==0)&&(flag==0))
  {
    t=millis();
    flag=1;
    lcd.setCursor(0,0);
    lcd.print("start!");
    delay(4000);
  }
  if(flag=1)
  {
    v=(millis()-t)/1000;
    v2=(millis()-t)/100;
    lcd.setCursor(0,0);
    lcd.print(v);
    lcd.print(".");
    lcd.print(v2-v*10);
  }
  d=digitalRead(8);
  if((d==0)&&(flag==1))
  {
    flag=2;
    v=(millis()-t)/1000;
    v2=(millis()-t)/100;
    lcd.setCursor(0,0);
    lcd.print("FINISH!");
    lcd.setCursor(0,1);
    lcd.print(v);
    lcd.print(".");
    lcd.print(v2-v*10);
    t=0;
    delay(900000); 
  }
  delay(50);
  lcd.clear();
}
