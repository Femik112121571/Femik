int x, a = 544;
int RUD()
{
  digitalWrite(10, LOW);
  delayMicroseconds(2);
  digitalWrite(10, HIGH);
  delayMicroseconds(10);
  digitalWrite(10, LOW);

  return 0.01723 * pulseIn(11, HIGH);
}
void KR(int d)
{
  digitalWrite(6, HIGH);
  delayMicroseconds(d);
  digitalWrite(6, LOW);
  delayMicroseconds(20000 - d);
}
void setup()
{
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(A0,INPUT);
  KR(544);
  Serial.begin(9600);
}
void loop()
{
  //ser();
  //if (RUD() > 51) 
  go(1,0,255,255);
}
void ser()
{
  Serial.println(RUD());
}
void go(int h1,int h2,int s1,int s2)
{
  digitalWrite(4, h1);
  digitalWrite(2, h2);
  analogWrite(3, s1);
  analogWrite(5, s2);
}
