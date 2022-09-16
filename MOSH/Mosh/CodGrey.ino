void EncA11() {flag1=1;attachInterrupt(PrPinA,EncA12, RISING); flag2==0? countA++:countA--;}
void EncA12() {flag1=0;attachInterrupt(PrPinA,EncA11, FALLING); flag2==1? countA++:countA--;}
void EncA21() {flag2=1;attachInterrupt(PrPinB,EncA22, RISING); flag1==0? countA--:countA++;}
void EncA22() {flag2=0;attachInterrupt(PrPinB,EncA21, FALLING); flag1==1? countA--:countA++;}
