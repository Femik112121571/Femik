int a {};
void setup() 
{
  pinMode(6,OUTPUT);
}
void PDS(int d)
{
  digitalWrite(6,HIGH);
  delayMicroseconds(d);
  digitalWrite(6,LOW);
  delayMicroseconds(20000-d);
}
void loop() 
{
  a=544;
  while(a<2400){PDS(a);a++;delay(10);}
}
