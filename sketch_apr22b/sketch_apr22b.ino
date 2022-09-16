#define ff 11
int d1, d2, mfl[ff], mfr[ff], mfsl[ff], mfsr[ff], ep, cm, M1, M2, u, ei, ed, e[10];
void setup()
{
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT);
}
void loop()
{
  Serial.print(mfsl[0]);
  Serial.print(" ");
  Serial.print(mfsl[1]);
  Serial.print(" ");
  Serial.print(mfsl[2]);
  Serial.print(" ");
  Serial.print(mfsl[3]);
  Serial.print(" ");
  Serial.print(mfsl[4]);
  Serial.print(" ");
  Serial.print(mfsl[5]);
  Serial.print(" ");
  Serial.print(mfsl[6]);
  Serial.print("             ");
  Serial.println(clean1());
}
int clean1()
{
  digitalWrite(A0, LOW);
  delayMicroseconds(2);
  digitalWrite(A0, HIGH);
  delayMicroseconds(10);
  digitalWrite(A0, LOW);
  for (int i = 0; i < ff - 1; i++)
  {
    constrain (mfl[i] = mfl[i + 1],0,100);
    constrain (mfl[i],0,100);
  }
  mfl[ff - 1] = 0.0172 * pulseIn(A1, HIGH);
  constrain(mfl[ff-1],0,100);
  for (int i = 0; i < ff; i++)
  {
    constrain (mfsl[i] = mfl[i],0,100);
  }
  for (int j = 0; j < ff; j++)
  {
    for (int i = 0; i < ff - 1; i++)
    {
      if (mfsl[i] > mfsl[i + 1])
      {
        int temp1 = mfsl[i];
        constrain (mfsl[i] = mfsl[i + 1],0,100);
        constrain (mfsl[i + 1] = temp1,0,100);
      }
    }
  }
  return constrain(mfsl[(ff - 1) / 2],0,100);
}
