int MO=255;
int s1 = 3;
int s2 = 5;
int p1 = 2;
int p2 = 4;
void setup() 
{
//while (digitalRead(2)==HIGH)delay(10);
}
void loop() 
{
 go();
}
void go ()
{
 analogWrite(s1,MO);
 analogWrite(s2,MO); 
 digitalWrite(p1,HIGH); 
 digitalWrite(p2,HIGH);
}
void left ()
{
 analogWrite(s1,MO);
 analogWrite(s2,0);  
 digitalWrite(p1,HIGH);
}
void right ()
{
 analogWrite(10,0);
 analogWrite(11,MO); 
 digitalWrite(p2,HIGH); 
}
void stop ()
{
 analogWrite(s1,0);
 analogWrite(s2,0); 
}
