#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
SoftwareSerial BT1(4, 2);
int lectura;
int hp;
boolean finish;
String terminar;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BT1.begin(9600);
  lcd.begin(16, 2);
  for (int i = 0; i < 3; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.backlight();
    delay(250);
  }
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Iniciando");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("Iniciando conexion");
  hp = 150;
  finish = false;
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(150);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BT1.available()) {
    terminar = BT1.readStringUntil('\n');
    Serial.println(terminar);
    terminar=terminar.substring(0,1);
    if (terminar.equals("t")) {
      setup();
    }
  }
  if ( hp<=0){
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    delay(500);
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    delay(500);
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    finish=true;
  }
  if (!finish) {
    lectura = analogRead(A1);
    //Serial.println(lectura);
    if (lectura > 970) {
      lcd.clear();
      lcd.setCursor(0, 0);
      hp = hp - 20;
      String texto = String(hp);
      lcd.print(texto);
      lcd.setCursor(0, 1);
      lcd.print("Golpe brazo izq");
      BT1.println("hi");
      digitalWrite(11,HIGH);
      delay(1000);
      digitalWrite(11,LOW);
    } else {
      lectura = analogRead(A2);
      if (lectura > 850) {
        lcd.clear();
        lcd.setCursor(0, 0);
        hp = hp - 20;
        String texto = String(hp);
        lcd.print(texto);
        lcd.setCursor(0, 1);
        lcd.print("Golpe brazo der");
        BT1.println("hd");
        digitalWrite(12,HIGH);
        delay(1000);
        digitalWrite(12,LOW);
      } else {
        lectura = analogRead(A3);
        if (lectura > 875) {
          lcd.clear();
          lcd.setCursor(0, 0);
          hp = hp - 50;
          String texto = String(hp);
          lcd.print(texto);
          lcd.setCursor(0, 1);
          lcd.print("Corazon");
          BT1.println("co");
          digitalWrite(13,HIGH);
          delay(1000);
          digitalWrite(13,LOW);
        } else {
          lectura = analogRead(A4);
          if (lectura > 950) {
            lcd.clear();
            lcd.setCursor(0, 0);
            hp = hp - 30;
            String texto = String(hp);
            lcd.print(texto);
            lcd.setCursor(0, 1);
            lcd.print("Cadera izquierda");
            BT1.println("ci");
            digitalWrite(10,HIGH);
            delay(1000);
            digitalWrite(10,LOW);
            } else {
            lectura = analogRead(A5);
            //Serial.println(lectura);
            if (lectura > 950) {
              lcd.clear();
              lcd.setCursor(0, 0);
              hp = hp - 30;
              String texto = String(hp);
              lcd.print(texto);
              lcd.setCursor(0, 1);
              lcd.print("Cadera derecha");
              BT1.println("cd");
              digitalWrite(9,HIGH);
              delay(1000);
              digitalWrite(9,LOW);
            }
          }
        }
      }
    }
  }else{
     setup();
    }
}
