void reser()
{
  int sp = 150;
  sr = 200;
  /*Serial.print(C);
  Serial.print("__");
  Serial.print(sr);
  Serial.print("__");
  Serial.println(D);*/
  if(C<sr && D<sr){Motors(sp,sp);}
  if(C<sr && D>sr){Motors(-150,sp);}
  if(C>sr && D<sr){Motors(sp,-150);}
  DatAnalis();
}
