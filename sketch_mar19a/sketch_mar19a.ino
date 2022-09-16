void setup()
{
while (digitalRead(2) == HIGH)delay(10);
}
void loop() 
{
IN();
PID();
}
void IN()
{
fem1 = analogRead(1);
fem2 = analogRead(0);  
}
void PID ()
{
if (max1<fem1) max1 = fem1;
if (max2<fem2) max2 = fem2;
if (min1>fem1||min1==0) min1 = fem1;
if (min2>fem2||min2==0) min2 = fem2;
dm1=map(fem1,max1,min1,100,0);
dm2=map(fem2,max2,min2,100,0);
analogWrite(10, M1);
analogWrite(11, M2);
if (M1 > 0) digitalWrite(12, HIGH); else digitalWrite(12, LOW);
if (M2 > 0) digitalWrite(13, HIGH); else digitalWrite(13, LOW);
}
