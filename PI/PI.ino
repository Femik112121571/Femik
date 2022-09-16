int ep,d1,d2;
float kp = 1;
void setup() 
{
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(2,OUTPUT);
pinMode(4,OUTPUT);
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
Serial.begin(9600);
}
void loop() 
{
ser();
IN();
p();
}
void IN()
{
  d1=analogRead(0);
  d2=analogRead(1);
}
void p()
{
  ep=d1-d2;
  
}
void ser ()
{
 Serial.print(d1);
 Serial.print("__d1__  ");
 Serial.print(d2);
 Serial.print("__d2____ ");
}
