void Motors(int A,int B){
  if(A>255){A=255;}if(A<-255){A=-255;}
  if(B>255){B=255;}if(B<-255){B=-255;}
  if(A>0){digitalWrite(MotorDfPinA,HIGH);}else{digitalWrite(MotorDfPinA,LOW);}
  if(B<0){digitalWrite(MotorDfPinB,HIGH);}else{digitalWrite(MotorDfPinB,LOW);}
  analogWrite(MotorAnPinA,A);
  analogWrite(MotorAnPinB,B);
}

void MotorA(int A){
  if(A>255){A=255;}if(A<255){A=-255;}
  if(A<0){digitalWrite(MotorDfPinA,HIGH);}else{digitalWrite(MotorDfPinA,LOW);}
  analogWrite(MotorAnPinA,A);
}

void MotorB(int B){
  if(B>255){B=255;}if(B<255){B=-255;}
  if(B>0){digitalWrite(MotorDfPinB,HIGH);}else{digitalWrite(MotorDfPinB,LOW);}
  analogWrite(MotorAnPinB,B);
}

void Vir(){
  if(analogRead(DPA)<analogRead(DPB))
  {
    while(analogRead(DPA)<analogRead(DPB))
    {
      Motors(Spid,-Spid);
    }
  }else{
    while(analogRead(DPA)>analogRead(DPB))
    {
      Motors(-Spid,Spid);
    }
  }
}

void Right(){
  Vir();
  DatAnalis();
  while(DatDfA==0)
  {
    DatAnalis();
    Motors(Spid,-Spid);
  }
  while(DatDfB==0)
  {
    DatAnalis();
    Motors(Spid,-Spid);
  }
  Vir();
}

void Left(){
  Vir();
  DatAnalis();
  while(DatDfB==0)
  {
    DatAnalis();
    Motors(-Spid,Spid);
  }
  while(DatDfA==0)
  {
    DatAnalis();
    Motors(-Spid,Spid);
  }
  Vir();
}
