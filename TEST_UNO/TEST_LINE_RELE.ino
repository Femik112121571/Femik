int MO = 150;
int fem1 = 0,fem2 = 0;
void setup()
{
    Serial.begin (9600);
}
void loop()
{
 IN();
 IG();
  Serial.print(fem1);
  Serial.print(" L ");
  Serial.print(fem2);
  Serial.println(" R ");
}
void GO ()
{
  digitalWrite(12, HIGH);
  analogWrite(10, MO);
  analogWrite(11, MO);
  digitalWrite(13, HIGH);
}
void BACK ()
{
  digitalWrite(12, LOW);
  analogWrite(10, MO);
  analogWrite(11, MO);
  digitalWrite(13, LOW);
}
void STOP ()
{
  digitalWrite(12, HIGH);
  analogWrite(10, 0);
  analogWrite(11, 0);
  digitalWrite(13, HIGH);
}
void LEFT ()
{
  digitalWrite(12, LOW);
  analogWrite(10, 0);
  analogWrite(11, MO);
  digitalWrite(13, HIGH);
}
void RIGHT ()
{
  digitalWrite(12, HIGH);
  analogWrite(10, MO);
  analogWrite(11, 0);
  digitalWrite(13, LOW);
}
void IN ()
{
  fem1 = digitalRead(2);
  fem2 = digitalRead(3);
}
void IG ()
{
 if (fem1>300,fem2>300)GO();
 if (fem1>300,fem2<300)LEFT();
 if (fem1<300,fem2>300)RIGHT();     
}
