#define MotorAnPinB       5
#define MotorDfPinB       4
#define MotorAnPinA       6
#define MotorDfPinA       7
#define PrPinA            2
#define PrPinB            3
#define EchoPin           10
#define TrigPin           11
#define ServoPin          9
#define s2                8
#define s3                12
#define out               13
#define DatPinA           A0
#define DatPinB           A1
#define KP                0.5
#define Spid              150

int U=0;
int UltraZv=0;
int ko=0;
bool DatDfA=0;
bool DatDfB=0;
long countA=0;
bool flag1=0;
bool flag2=0;
long t=0;
byte red=0;
byte green=0;
byte blue=0;
byte Red=1;
byte Green=2;
byte Blue=3;
byte Wight=4;

void setup(){
  Serial.begin(9600);
  pinMode(MotorAnPinA,OUTPUT);
  pinMode(MotorDfPinA,OUTPUT);
  pinMode(MotorAnPinB,OUTPUT);
  pinMode(MotorDfPinB,OUTPUT);
  pinMode(TrigPin,OUTPUT); 
  pinMode(EchoPin,INPUT);
  pinMode(DatPinA,INPUT);
  pinMode(DatPinB,INPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(out,INPUT);
  pinMode(PrPinA,INPUT_PULLUP);
  pinMode(PrPinB,INPUT_PULLUP);
  flag1=digitalRead(PrPinA);
  flag2=digitalRead(PrPinB);
  //attachInterrupt(PrPinA,EncA11,RISING);
  //attachInterrupt(PrPinB,EncA21,RISING);
  //Otkr();
  //delay(500);
}

void loop(){
  /*
  DatAnalis();
  while(true){
    DatAnalis();
    PReg();
    Motors(Spid-U,Spid+U);
    if((DatDfA==1)&&(DatDfB==1))
    {
      break;
    }
  }
  while((DatDfA==1)&&(DatDfB==1))
  {
    DatAnalis();
    PReg();
    Motors(Spid,Spid);
  }
  t=millis()+50;
  while(t>millis())
  {
    PReg();
    Motors(Spid+50-U,Spid+50+U);
  }
  Right();
  Motors(0,0);
  delay(999999);
  *//*
  Motors(200,200);
  delay(3000);
  Zakr();
  delay(1500);
  Motors(200,200);
  delay(5000);
  Motors(0,0);
  delay(9999999);
  */
  //UltraZvAnalis();
  //Serial.println(UltraZv);
  Motors(100,100);
}
