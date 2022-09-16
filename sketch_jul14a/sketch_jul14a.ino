void setup() 
{
 pinMode(9,OUTPUT);
} 
void KD(int d)
{
  digitalWrite(9, HIGH);
  delayMicroseconds(d);
  digitalWrite(9, LOW);
  delayMicroseconds(20000 - d);
  delay(0);
}
void loop()
{
  KD(2400);
}
