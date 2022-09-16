void UltraZvAnalis(){
  int duration; 
  digitalWrite(TrigPin,LOW); 
  delayMicroseconds(2); 
  digitalWrite(TrigPin,HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TrigPin,LOW); 
  duration=pulseIn(EchoPin, HIGH); 
  UltraZv=duration/58;
  delay(50);
}
