#include <SoftwareSerial.h>

SoftwareSerial BT1(6,7);//RX,TX
int pinKey=4;
int pinState=8;

void setup()
   {
       Serial.begin(9600);
       Serial.println("Enter AT commands:");
       BT1.begin(9600);
       digitalWrite(pinKey,HIGH);
       delay(500);
       digitalWrite(pinState,HIGH);
   }

void loop()
   {
       if (BT1.available())
           Serial.write(BT1.read());
       
       if (Serial.available())
          {  String S = GetLine();
             BT1.print(S);
             Serial.println("---> " + S);
          }
}

String GetLine()
   {   String S = "" ;
       if (Serial.available())
          {    char c = Serial.read(); ;
                while ( c != '\n')            //Hasta que el caracter sea intro
                  {     S = S + c ;
                        delay(25) ;
                        c = Serial.read();
                  }
                return( S + '\n') ;
          }
   }


