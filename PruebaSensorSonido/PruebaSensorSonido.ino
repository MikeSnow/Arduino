int sensorPin = A0; // select the input pin for the potentiometer
int ledPin = 4; // select the pin for the LED
int sensorValue = 0; // variable to store the value coming from the sensor
 
void setup () {
  pinMode (ledPin, OUTPUT);
  Serial.begin (9600);
}
 
void loop () {
  
  digitalWrite (ledPin, HIGH);
  sensorValue = analogRead (sensorPin);
  delay(100);
  Serial.println (sensorValue);
}