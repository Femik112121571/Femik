void PReg()
{
  int M1,M2;
  int sp = 200; 
  U=(analogRead(DPA)-analogRead(DPB))*KP;
  M2 = constrain(sp + U, -255, 255);
  M1 = constrain(sp - U, -255, 255);
  Motors(M2,M1);
}
