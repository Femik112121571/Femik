int fem=0;
int counter=0,flag=0;
int min1=0,max1=0,sr=0;
void setup() 
{
pinMode(3,INPUT);
Serial.begin(9600);
}
void loop() 
{
fem=analogRead(0);
Serial.print(flag);
Serial.print("     flag ");
Serial.print(fem);
Serial.print("          fem     ");
Serial.print(counter);
Serial.print("      counter   ");
Serial.print(max1);
Serial.print("      MAX  ");
Serial.print(min1);
Serial.println("      MIN   ");
if (min1>fem||min1==0)min1=fem;
if (max1<fem||max1==0)max1=fem;
sr =(max1+min1)/2;
if(fem>sr)
{
if (flag==0){counter++;flag=1;}else flag=1;
}
else
{
  flag=0;
}
}
