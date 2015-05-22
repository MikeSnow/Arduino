const int xAxis=A2;
const int yAxis=A3;
int x;
int y;
void setup(){
  Serial.begin(9600);
}
void loop(){
  x=analogRead(xAxis);
  y=analogRead(yAxis);
  String texto="X: "+String(x)+" Y: "+String(y);
  Serial.println(texto);
}


