int d1 = 0,d2 = 0,d3 = 0,d4 = 0,dm1 = 0,dm2 = 0,dm3 = 0,dm4 = 0,max1=0,max2=0,min1=0,min2=0,max3=0,max4=0,min3=0,min4=0,d=50;
void setup()
{
 Serial.begin(9600);
 pinMode(A0,INPUT);
 pinMode(A1,INPUT);
 pinMode(A2,INPUT);
 pinMode(A3,INPUT);

 pinMode(13,OUTPUT);//скорость 1
 pinMode(12,OUTPUT);
 pinMode(11,OUTPUT);//скорость 2
 pinMode(10,OUTPUT);
}
void flp(int L, int P,int m1 , int m2)
{
 digitalWrite(12,L);
 digitalWrite(13,P);
 analogWrite(11,m1); 
 analogWrite(10,m2);
}
void loop()
{
d1=analogRead(0);
d2=analogRead(1);
d3=analogRead(2);
d4=analogRead(3);
/*
Serial.print(dm1);
Serial.print("__");
Serial.print(dm2);
Serial.print("__");
Serial.print(dm3);
Serial.print("__");
Serial.println(dm4);
*/
if(max1<d1)max1=d1;
if(max2<d2)max2=d2;
if(max3<d3)max3=d3;
if(max4<d4)max4=d4;

if(min1>d1||min1==0)min1=d1;
if(min2>d2||min2==0)min2=d2;
if(min3>d3||min3==0)min3=d3;
if(min4>d2||min4==0)min4=d4;

dm1=map(d1,max1,min1,0,100);
dm2=map(d2,max2,min2,0,100);
dm3=map(d3,max3,min3,0,100);
dm4=map(d4,max4,min4,0,100);
//слева  А0(dm1) и А1 ( dm2).....справа А2(dm3) и А3 (dm4)
if( dm1 < d && dm2 < d && dm3 < d && dm4 < d) flp(1,1,100,125);
if( dm1 > d && dm2 > d && dm3 > d && dm4 > d) flp(1,1,100,125);
if( dm1 > d && dm2 > d && dm3 < d && dm4 > d) flp(0,1,100,0);
if( dm1 < d && dm2 > d && dm3 > d && dm4 > d) flp(1,0,0,100);
if( dm1 > d && dm2 < d && dm3 > d && dm4 > d) flp(0,1,100,125);
if( dm1 > d && dm2 > d && dm3 > d && dm4 < d) flp(1,0,100,125);
if( dm1 < d && dm2 < d && dm3 > d && dm4 > d) flp(0,1,100,125);
if( dm1 > d && dm2 > d && dm3 < d && dm4 < d) flp(1,0,100,125);
}
