int pin = 3 ;

void setup(){
  pinMode(pin,OUTPUT);
}
void loop(){
  int i ;
  
  for (i=0; i<256;i++){
    analogWrite(pin,i);
    delay(10);
  }
  for (i; i>0 ;i--){
    analogWrite(pin,i);
    delay(10);
  }
}

