#define ff 5
#include <NewPing.h>
NewPing UzR(A0, A1); //Правый УЗД - A0 триггер, A1 эхо
NewPing UzF(A2, A3); //Фронтальный УЗД - A2 триггер, A3 эхо
int massR[ff];
int massRS[ff];
int massF[ff];
int massFS[ff];
int L = 5;
int Mo = 65;
int Mp = 90;
float kp = 2;//5
float ki = 1;//1
float kd = 15;//15
int E[10];
unsigned int sR = 0;
unsigned int sF = 0;

void setup()
{
  pinMode(3, OUTPUT); //скорость левого
  pinMode(6, OUTPUT); //скорость правого
  pinMode(2, OUTPUT); //направление левого
  pinMode(4, OUTPUT); //направление левого
  pinMode(5, OUTPUT); //направление правого
  pinMode(7, OUTPUT); //направление правого
  Serial.begin(9600);
  pinMode(A0, OUTPUT); //триггер правого
  pinMode(A2, OUTPUT); //триггер фронтального
  pinMode(A1, INPUT); //эхо правого
  pinMode(A3, INPUT); //эхо фронтального
  for (int i = 0; i < ff; i++)
  {
    distR();
    distF();
  }
  L = distR();
}
int distR() {
  for (int i = 0; i < ff - 1; i++)
  {
    massR[i] = massR[i + 1];
  }
  massR[ff - 1] = UzR.ping_cm();
  for (int i = 0; i < ff; i++)
  {
    massRS[i] = massR[i];
  }
  for (int j = 0; j < ff; j++)
  { for (int i = 0; i < ff - 1; i++)
    { if (massRS[i] > massRS[i + 1])
      { int temp = massRS[i];
        massRS[i] = massRS[i + 1];
        massRS[i + 1] = temp;
      }
    }
  }
  return massRS[(ff - 1) / 2];
}

int distF() {
  for (int i = 0; i < ff - 1; i++)
  {
    massF[i] = massF[i + 1];
  }
  massF[ff - 1] = UzF.ping_cm();
  for (int i = 0; i < ff; i++)
  {
    massFS[i] = massF[i];
  }
  for (int j = 0; j < ff; j++)
  { for (int i = 0; i < ff - 1; i++)
    { if (massFS[i] > massFS[i + 1])
      { int temp = massFS[i];
        massFS[i] = massFS[i + 1];
        massFS[i + 1] = temp;
      }
    }
  }
  return massFS[(ff - 1) / 2];
}
void pid()
{
  int Ei = 0;
  int Ep = sR - L;
  for (int i = 0; i < 9; i++)
  {
    E[i] = E[i + 1];
    Ei = Ei + E[i];
  }
  E[9] = Ep;
  Ei = 0.1 * (Ei + Ep);
  int Ed = Ep - Ei;
  int U = kp * Ep + ki * Ei + kd * Ed;
  int M1 = Mp - U;
  int M2 = (Mp + U)*1.1;
  M1 = constrain(M1, -150, 150);
  M2 = constrain(M2, -150, 150);
  analogWrite(3, M1);
  analogWrite(6, M2);
  if (M1 > 0) {
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
  } else  {
    digitalWrite(4, HIGH);
    digitalWrite(2, LOW);
  }
  if (M2 > 0) {
    digitalWrite(5, HIGH);
    digitalWrite(7, LOW);
  } else  {
    digitalWrite(7, HIGH);
    digitalWrite(5, LOW);
  }
}
void go(int Lv, int Ln, int Rv, int Rn, int Mk1, int Mk2)
{
  digitalWrite(2, Lv);
  digitalWrite(4, Ln);
  digitalWrite(5, Rv);
  digitalWrite(7, Rn);
  analogWrite(3, Mk1);
  analogWrite(6, Mk2);
}

void loop()
{
    sR = distR();
    sF = distF();
    /*Serial.print(sR);
    Serial.print("lol");
    Serial.print(sF);
    Serial.println("kol ");*/
    unsigned int sR = distR();
    unsigned int sF = distF();
  if(sF > 8 && sR < 21)
  {
    pid();
  }
  else if (sR > 21)
  {
    go(1, 0, 1, 0, Mo/1.2,1.7*Mo);
    delay(50);
  }
  else 
  {
    go(1, 0, 0, 1, Mo, Mo*1.13);
    delay(50);
  }
}
