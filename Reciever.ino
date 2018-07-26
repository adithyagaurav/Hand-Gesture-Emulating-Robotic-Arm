#include <Servo.h> //include servo library
Servo myservo; // create servo object to control a servo
int q=11; //data pin Do from decoder
int w=12; //data pin D1 from decoder
int e=13; //data pin D2 from decoder
int potpin = 10; //data pin from decoder
int Vccpin= A4; // Vcc for decoder and receiver
int Gndpin=A5; // Gnd for decoder and receiver
int V=A0; //Vcc for L293D IC
int G=A1; //Gnd for L293D IC
int a=2; // motor1 terminal 1 connected to digital pin 2
int b=3; // motor1 terminal 2 connected to digital pin 3
int c=8; // motor2 terminal 1 connected to digital pin 8
int d=9; // motor2 terminal 2 connected to digital pin 9
int val; // variable to read the value from the analog pin
void setup()
{
 Serial.begin(9600);
 myservo.attach(6); // attaches the servo on pin 9 to the servo object
 pinMode(potpin,INPUT);
 pinMode(Gndpin,OUTPUT);
 pinMode(Vccpin, OUTPUT);
 pinMode(V, OUTPUT);
 pinMode(G, OUTPUT);
 pinMode(q, INPUT);
 pinMode(w, INPUT);
 pinMode(e, INPUT);
 pinMode(a, OUTPUT);
 pinMode(b, OUTPUT);
 pinMode(c, OUTPUT);
 pinMode(d, OUTPUT);
 digitalWrite(Gndpin,LOW);
 digitalWrite(Vccpin,HIGH);
digitalWrite(V, HIGH);
digitalWrite(G, LOW);
}
void loop()
{
 val=digitalRead(potpin);
 int val1=digitalRead(q);
 int val2=digitalRead(w);
 int val3=digitalRead(e);
 if (val1==1 && val2==1 && val3==1)
 {
 val =map (val, 0,1,0,100);
 Serial.println(val);
 myservo.write(val);
 digitalWrite(a, HIGH);
 digitalWrite(b, LOW);
 digitalWrite(c, LOW);
 digitalWrite(d, LOW);
 Serial.println(" ");
 Serial.println("forward");
 }
 if (val1==0 && val2==1 && val3==0)
 {
 val = map (val, 0,1,0,100);
 Serial.println(val);
 myservo.write(val);
 Serial.println(" ");
 Serial.println("backward");
 digitalWrite(a, LOW);
 digitalWrite(b, HIGH);
 digitalWrite(c, LOW);
 digitalWrite(d, LOW);
 }
 if (val1==1 && val2==0 && val3==0)
 {
 val =map (val, 0,1,0,100);
 Serial.println(val);
 myservo.write(val);
 Serial.println("");
 Serial.println("right");
 digitalWrite(a, LOW);
 digitalWrite(b, LOW);
 digitalWrite(c, LOW);
 digitalWrite(d, HIGH);
 }
 if (val1==0 && val2==0 && val3==0)
 {
 val =map (val, 0,1,0,100);
 Serial.println(val);
 myservo.write(val);
 Serial.println("");
 Serial.println("stop");
 digitalWrite(a, LOW);
 digitalWrite(b, LOW);
 digitalWrite(c, LOW);
 digitalWrite(d, LOW);
 }
 if (val1==0 && val2==0 && val3==1)
 {
 val =map (val, 0,1,0,100);
 Serial.println(val);
 myservo.write(val);
 Serial.println(" ");
 Serial.println("left");
 digitalWrite(a, LOW);
 digitalWrite(b, LOW);
 digitalWrite(c, HIGH);
 digitalWrite(d, LOW);
 }
}
