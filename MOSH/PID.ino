void PReg(){
  U=(analogRead(DatPinA)-analogRead(DatPinB))*KP;
}
