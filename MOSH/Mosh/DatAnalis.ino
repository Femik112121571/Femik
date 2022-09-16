void DatAnalis(){
  C=analogRead(DPA);
  D=analogRead(DPB);
  if(C>500){DatDfA=1;}else{DatDfA=0;}
  if(D>500){DatDfB=1;}else{DatDfB=0;}
}
