int a,b;
void setup() 
{
 Serial.begin(9600);
  pinMode(A0, OUTPUT);                                                    
}
void loop()
{
  in();
}
void in ()
{
  a = analogRead(A0);
  b = analogRead(A1);
  Serial.print("D1___");
  Serial.print(a);
  Serial.print("D2___");
  Serial.println(b);
}
