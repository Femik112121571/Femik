int dm1,dm2,fem1,fem2,sr1,sr2,max1,max2,min1,min2,dm3,dm4,fem3,fem4,sr3,sr4,max3,max4,min3,min4,M1,M2,Ep;
int MO = 200;
float KP = 1;//2
float Kd = 2;//3
float Ki = 4;//5
int p1 = 2;
int p2 = 4;
int s1 = 3;
int s2 = 5;
void setup()
{
 pinMode(A0,INPUT);
 pinMode(A7,INPUT);
 //pinMode(A2,INPUT);
 //pinMode(A3,INPUT);
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 Serial.begin (9600);
}
void loop()
{
 IN();
 PID();
}
void PID()
{ 
  float EI[10]={0};
  float Ei=0;
  float Ep = dm1-dm2;
  for(int i=0;i<9;i++) {EI[i]=EI[i+1];Ei=Ei+EI[i];}
  EI[9]=Ep;  
  Ei=(Ei+Ep)/10;
  float Ed=Ep-Ei;
  float U = KP * Ep + Ki * Ei + Kd * Ed;
  M1 = MO + U;
  M2 = MO - U;
  M1 = constrain(M1, -255, 255);
  M2 = constrain(M2, -255, 255);
  analogWrite(s1, M1);
  analogWrite(s2, M2);
  if (M1 > 0) digitalWrite(p1, HIGH); else digitalWrite(p1, LOW);
  if (M2 > 0) digitalWrite(p2, HIGH); else digitalWrite(p2, LOW);
}
void IN ()
{
  fem1 = analogRead(0);
  fem2 = analogRead(7);
  //fem3 = analogRead(2);
  //fem4 = analogRead(3);
  if (max1<fem1) max1 = fem1;
  if (max2<fem2) max2 = fem2;
  //if (max3<fem3) max3 = fem3;
  //if (max4<fem4) max4 = fem4;
  if (min1>fem1||min1==0) min1 = fem1;
  if (min2>fem2||min2==0) min2 = fem2;
  if (min3>fem3||min3==0) min3 = fem3;
  if (min4>fem4||min4==0) min4 = fem4;
  dm1=map(fem1,max1,min1,100,0);
  dm2=map(fem2,max2,min2,100,0);
  //dm3=map(fem3,max3,min3,100,0);
  //dm4=map(fem4,max4,min4,100,0);
}
/*void REL ()
{
 if (dm3<30,dm4>30)go(1,1,100,100);
 if (dm3>30,dm4<30)go(1,0,100,0); 
 if (dm3<30,dm4<30)PID();
}*/
void ser ()
{
 Serial.print(dm1);
 Serial.print("dm1        ");
 Serial.print(dm2);
 Serial.print("dm2       ");
 Serial.print(M1);
 Serial.print("M1          ");
 Serial.print(M2);
 Serial.println("M2       ");
}
void go(int L,int R,int ls,int rs)
{
  digitalWrite(p1, L);
  analogWrite(s1, ls);
  analogWrite(s2, rs);
  digitalWrite(p2, R);
}
