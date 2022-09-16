#include <Servo.h>
#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(4); 
Servo servo;
Servo ser;
int Tele=0;
float a = 90.0;
float b = 150.0;
void setup()
{
Serial.begin(9600);
pinMode(6,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(4,OUTPUT);
pinMode(9,OUTPUT);
servo.attach(10);
servo.write(90);
ser.attach(9);
ser.write(150);
}
void loop() 
{
Serial.println(Tele);
if (Serial.available()>0)Tele=Serial.read();
if (Tele == 70)ser.write(b=b+0.5);
if (Tele == 66)ser.write(b=b-0.5);
if (Tele == 76)servo.write(a=a+0.5);
if (Tele == 82)servo.write(a=a-0.5);
if (Tele == 119){analogWrite(A4,255);delay(500);analogWrite(A4,0);}
if (Tele == 120){analogWrite(A4,255);delay(500);analogWrite(A4,0);}
/*if (Tele == 53)servo.write(0);
if (Tele == "2")servo.write(36);
if (Tele == "3")servo.write(72);
if (Tele == "4")servo.write(108);
if (Tele == "5")servo.write(144);
if (Tele == "6")servo.write(180);
if (Tele == "7")servo.write(216);
if (Tele == "8")servo.write(252);
if (Tele == "9")servo.write(288);
if (Tele == 113)servo.write(360);*/
//if (Tele =='I')leftl();
//if (Tele =='G')rightr();
//if (Tele =='J')leftb();
//if (Tele =='H')rightb();
if (Tele == 83)STOP();
}
void GO()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD); 
  motor1.setSpeed(255); 
  motor2.setSpeed(255); 
}
void BACK()
{
  motor1.run(BACKWARD); // задаем движение назад
  motor2.run(BACKWARD); // задаем движение назад
  motor1.setSpeed(255);   // задаем скорость движения
  motor2.setSpeed(255);
}
void LEFT()
{
  motor1.run(FORWARD);
  motor2.run(BACKWARD); 
  motor1.setSpeed(255); 
  motor2.setSpeed(255); 
}
void RIGHT()
{
  motor1.run(BACKWARD);
  motor2.run(FORWARD); 
  motor1.setSpeed(255); 
  motor2.setSpeed(255); 
}
void STOP()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
//servo.write(360);
