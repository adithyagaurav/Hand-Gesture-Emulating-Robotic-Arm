
int GNDPin=A4; //Set Analog pin 4 as GND
int VccPin=A5; //Set Analog pin 5 as VCC
int GNDPina=A0;
int xPin=A3; //X axis input
int yPin=A2; //Y axis input
int Q1=7;
int Q2=8;
int Q3=9;
const int f=A1;
int v;
const int t=2;
long x; //Variabe for storing X coordinates
long y; //Variabe for storing Y coordinates
long z; //Variabe for storing Z coordinates
void setup()
{
  Serial.begin(9600);

              
  
  pinMode(GNDPin, OUTPUT);
  pinMode(VccPin, OUTPUT);
  pinMode(GNDPina, OUTPUT);
  pinMode(Q1,OUTPUT);
  pinMode(Q2,OUTPUT);
  pinMode(Q3,OUTPUT);
  pinMode(f, INPUT);
  pinMode(t, OUTPUT);
  digitalWrite(GNDPin, LOW); //Set A4 pin LOW
  digitalWrite(VccPin, HIGH); //Set A5 pin HIGH
  digitalWrite(GNDPina, LOW); 
}
void loop()
{
  x = analogRead(xPin); //Reads X coordinates
  y = analogRead(yPin); //Reads Y coordinates
 
    
     if ( y>370)// Change the value for adjusting sensitivity
      forward();
      else if  (y<294)
      backward();
    else if(x>400)  // Change the value for adjusting sensitivity
      right();
    else if(x<300)  // Change the value for adjusting sensitivity
      left();
      else
      stop_();
    
}

  

void forward()
{
  v=analogRead(f);
  if(v<550)
  {
  Serial.println("");
  Serial.println("Forward Close");
  digitalWrite(Q1,HIGH);
  digitalWrite(Q2,HIGH);
  digitalWrite(Q3,HIGH);
  digitalWrite(t, HIGH);
}
if(v>551)
  {
  Serial.println("");
  Serial.println("Forward Open");
  digitalWrite(Q1,HIGH);
  digitalWrite(Q2,HIGH);
  digitalWrite(Q3,HIGH);
  digitalWrite(t, LOW);
}
}
void backward()
{
  v=analogRead(f);
  if(v<550)
  {
  Serial.println("");
  Serial.println("Backward Close");
  digitalWrite(Q1,LOW);
  digitalWrite(Q2,HIGH);
  digitalWrite(Q3,LOW);
  digitalWrite(t, HIGH);
  }
  if(v>551)
  {
  Serial.println("");
  Serial.println("Backward Open");
  digitalWrite(Q1,LOW);
  digitalWrite(Q2,HIGH);
  digitalWrite(Q3,LOW);
  digitalWrite(t, LOW);
  }
  
}
void left()
{
  v=analogRead(f);
  if(v<550)
  {
  Serial.println("");
  Serial.println("Left Close");
  digitalWrite(Q1,LOW);
  digitalWrite(Q2,LOW);
  digitalWrite(Q3,HIGH);
  digitalWrite(t, HIGH);
  }
  if(v>551)
  {
  Serial.println("");
  Serial.println("Left Open");
  digitalWrite(Q1,LOW);
  digitalWrite(Q2,LOW);
  digitalWrite(Q3,HIGH);
  digitalWrite(t, LOW);
  }
}
void right()
{
  v=analogRead(f);
  if(v<550)
  {
  Serial.println("");
  Serial.println("Right Close");
 digitalWrite(Q1,HIGH);
  digitalWrite(Q2,LOW);
  digitalWrite(Q3,LOW);
  digitalWrite(t, HIGH);
  }
  if(v>551)
  {
  Serial.println("");
  Serial.println("Right Open");
  digitalWrite(Q1,HIGH);
  digitalWrite(Q2,LOW);
  digitalWrite(Q3,LOW);
  digitalWrite(t, LOW);
  }
}
void stop_()
{
  v=analogRead(f);
  if(v<550)
  {
  Serial.println("");
  Serial.println("stop Close");
  digitalWrite(Q1,LOW);
  digitalWrite(Q2,LOW);
  digitalWrite(Q3,LOW);
  digitalWrite(t, HIGH);
  }
   if(v>551)
  {
  Serial.println("");
  Serial.println("stop Open");
  digitalWrite(Q1,LOW);
  digitalWrite(Q2,LOW);
  digitalWrite(Q3,LOW);
  digitalWrite(t, LOW);
  }
}

