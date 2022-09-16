int ep, cm, M1, M2, u, ei, ed, e[10];
int x = 7;
int MO = 150;
float kp = 1;
float ki = 1;
float kd = 1;
float ke = 1.2;
int RUD()
{
  digitalWrite(A0, LOW);
  delayMicroseconds(2);
  digitalWrite(A0, HIGH);
  delayMicroseconds(10);
  digitalWrite(A0, LOW);

  return 0.01723 * pulseIn(A1, HIGH);
}
void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  x=RUD();
}
void loop()
{
  //ser();
  IN();
  PID();
}
void IN()
{
  cm = constrain(RUD(), -255, 255);
}
void PID()
{
  ep = cm - x;
  for (int i = 0; i > 9; i++)
  {
    e[i] = e[i + 1];
    ei = ei + e[i];
  }
  e[9] = ep;
  ei = (ei + ep) / 10;
  ed = ep - ei;
  /*if (ep < x - 3 || ep > x + 3){*/u = kp * ep + ki * ei + kd * ed;//}else {u = ke * ep * ep * ep;}  
  M2 = constrain(MO + u, -255, 255);
  M1 = constrain(MO - u, -255, 255);
  if (M1 > 0)
  {
    digitalWrite(5, HIGH);
    digitalWrite(7, LOW);
  }
  else
  {
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
  }
  if (M2 > 0)
  {
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
  }
  else
  {
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
  }
  analogWrite(6, M1);
  analogWrite(3, M2);
}
void ser()
{
  Serial.print(M1);
  Serial.print("_m1_");
  Serial.print(M2);
  Serial.print("_m2_");
  Serial.print(cm);
  Serial.print("_cm_");
  Serial.print(ke);
  Serial.print("_ep__");
  Serial.print(u);
  Serial.println("_u__");
  Serial.print(cm);
  Serial.println("_cm");
}
