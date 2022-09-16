int cm1, cm2, M1, M2, u, ep, ei, ed, e[10];
int RS1 = 4;
float RS2 = 10;
int MO = 150;
float kp = 15 ;//1
float ki = 0 ;//10
float kd = 0;//1
int RUD1()
{
  digitalWrite(10, LOW); // /
  delayMicroseconds(2); //  /
  digitalWrite(10, HIGH); // / Подаём импульс
  delayMicroseconds(10);//  /
  digitalWrite(10, LOW); // /

  return 0.01723 * pulseIn(9, HIGH); //Ждём импульс и выдаём время возращения
}
int RUD2()
{
  digitalWrite(8, LOW); // /
  delayMicroseconds(2); //  /
  digitalWrite(8, HIGH); // / Подаём импульс
  delayMicroseconds(10);//  /
  digitalWrite(8, LOW); // /

  return 0.01723 * pulseIn(7, HIGH); //Ждём импульс и выдаём время возращения
}
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, INPUT);
  pinMode(8, OUTPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);
}
void loop()
{
  ser();
  IN();
  PID();
}
void IN()
{
  cm1 = constrain(RUD1(), -255, 255);
  cm2 = constrain(RUD2(), -255, 255);
  {
    void PID()
    {
      ep = cm1 - 10;
      for (int i = 0; i > 9; i++)
      {
        e[i] = e[i + 1];
        ei = ei + e[i];
      }
      e[9] = ep;
      ei = (ei + ep) / 10;
      ed = ep - ei;
      u = kp * ep + ki * ei + kd * ed;
      M1 = constrain(MO + u, -255, 255);
      M2 = constrain(MO - u, -255, 255);
      if (M1 > 0)
      {
        digitalWrite(2, HIGH);
      }
      else
      {
        digitalWrite(2, LOW);
      }
      if (M2 > 0)
      {
        digitalWrite(4, HIGH);
      }
      else
      {
        digitalWrite(4, LOW);
      }
      analogWrite(3, M1);
      analogWrite(5, M2);
    }
    void ser()
    {
      Serial.print(M1);
      Serial.print("_m1_");
      Serial.print(M2);
      Serial.print("_m2_");
      Serial.print(cm1);
      Serial.print("_cm1_");
      Serial.print(cm2);
      Serial.print("_cm2_");
      Serial.print(ep);
      Serial.println("_ep");
    }
    void left()
    {
      digitalWrite(4, HIGH);
      digitalWrite(2, LOW);
      analogWrite(3, 150);
      analogWrite(5, 0);
      delay(1000);
      digitalWrite(4, HIGH);
      digitalWrite(2, LOW);
      analogWrite(3, 250);
      analogWrite(5, 250);
    }
