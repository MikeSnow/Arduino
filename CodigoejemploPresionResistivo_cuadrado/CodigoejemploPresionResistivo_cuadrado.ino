int pin;
int lector;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pin=3;
  
}

void loop() {
  // put your main code here, to run repeatedly:
   lector = analogRead(3);
   Serial.println(lector);  
   delay(100);
 }
