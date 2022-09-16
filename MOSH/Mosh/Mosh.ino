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
#define DPA           A0
#define DPB           A1
#define KP                1
#define Spid              150
int MIN,sr,MAX;
int C,D;
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
  pinMode(DPA,INPUT);
  pinMode(DPB,INPUT);
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
int flag = 0;
void loop(){
  DatAnalis();
  //UltraZvAnalis();
  //if(C<800 && D<800 && flag==0){Motors(120,150);}else
  //{Motors(120,120);delay(100);Motors(-150,150);delay(1000);flag++;}
  //if (flag==1){reser();}
  Motors(120,150);
  delay(2000);
  Motors(-120,-150);
  delay(2000);
  Motors(0,0);
  delay(10000000);
}
