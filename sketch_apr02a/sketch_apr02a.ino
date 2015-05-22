#include<TimedAction.h>

TimedAction accion1=TimedAction(1000,encender);
int pinEntrada = A2;
int pinled = 8;
int lectura ;
boolean prueba;
void setup(){
  Serial.begin(9600);
  pinMode(pinled,OUTPUT);
  digitalWrite(pinled,LOW);
}
void loop(){
  lectura = analogRead(pinEntrada);
  Serial.println(lectura);
}




