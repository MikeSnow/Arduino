int g;
int f;
int a;
int b;
int e;
int d;
int c;
int h;
int i;
void setup() {
  // put your setup code here, to run once:
 pinMode(g,OUTPUT);
 pinMode(f,OUTPUT);
 pinMode(a,OUTPUT);
 pinMode(b,OUTPUT);
 pinMode(e,OUTPUT);
 pinMode(d,OUTPUT);
 pinMode(c,OUTPUT);
 pinMode(h,OUTPUT);
 int i=0;
  
}

void loop() {
  // put your main code here, to run repeatedly:
 switch (i){
   case 0:
     digitalWrite(g,LOW);
     digitalWrite(f,HIGH);
     digitalWrite(a,HIGH);
     digitalWrite(b,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(d,HIGH);
     digitalWrite(c,HIGH);
     digitalWrite(h,LOW);
     break;
   case 1:
     digitalWrite(g,LOW);
     digitalWrite(f,LOW);
     digitalWrite(a,LOW);
     digitalWrite(b,HIGH);
     digitalWrite(e,LOW);
     digitalWrite(d,LOW);
     digitalWrite(c,HIGH);
     digitalWrite(h,LOW);
     break;
   case 2:
     digitalWrite(g,HIGH);
     digitalWrite(f,LOW);
     digitalWrite(a,HIGH);
     digitalWrite(b,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(d,HIGH);
     digitalWrite(c,LOW);
     digitalWrite(h,LOW);
     break;
   case 3:
     digitalWrite(g,HIGH);
     digitalWrite(f,LOW);
     digitalWrite(a,HIGH);
     digitalWrite(b,HIGH);
     digitalWrite(e,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(c,HIGH);
     digitalWrite(h,LOW);
     break;
   case 4:
     digitalWrite(g,HIGH);
     digitalWrite(f,HIGH);
     digitalWrite(a,LOW);
     digitalWrite(b,HIGH);
     digitalWrite(e,LOW);
     digitalWrite(d,LOW);
     digitalWrite(c,HIGH);
     digitalWrite(h,LOW);
   case 5:
     digitalWrite(g,HIGH);
     digitalWrite(f,HIGH);
     digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite
   case 6:
   case 7:
   case 8:
   case 9:
   }
}
