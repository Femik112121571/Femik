int MO = 150;
int fem1 = 0,fem2 = 0;

void setup()
{
    Serial.begin (115200);
  while (digitalRead(2) == HIGH)delay(10);
}
void loop()
{
 IN();
 IG();
  Serial.print(fem1);
  Serial.print(" fem1 ");
  Serial.print(fem2);
  Serial.println(" fem2 ");
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
  fem1 = analogRead(1);
  fem2 = analogRead(2);
}
void IG ()
{
 if (fem1>1,fem2>1)GO();
 if (fem1<1,fem2>1)LEFT();
 if (fem1>1,fem2<1)RIGHT();     
}
