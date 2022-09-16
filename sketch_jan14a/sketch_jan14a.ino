#define led 9
#define but_1 2
#define but_2 3

int brit = 100;
boolean fp = true;
boolean fm = true;
void setup() 
{
  pinMode(led, OUTPUT);
  pinMode(but_1, INPUT);
  pinMode(but_2, INPUT);
  Serial.begin(9600);
}
void loop() 
{
  analogWrite(led , brit);
  fp = handleClick(but_1 , fp , +35);
  fm = handleClick(but_2 , fm , -35);
  Serial.print(fp);
  Serial.print("_");
  Serial.println(fm);
}
boolean handleClick(int bp, boolean wasUp, int delta)
{
  boolean isUp = digitalRead(bp);
  if(wasUp && !isUp){
    delay(10);
    isUp = digitalRead(bp);
    if(!isUp)
      brit = constrain(brit + delta , 0 , 255);
  }
  return isUp;
}
