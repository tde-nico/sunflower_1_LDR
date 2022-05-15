#include <Servo.h>

Servo myservo;

int tri = 12;
int echo = 13;
int spk = 11;
int pin = 0;  
int pos; 
int dir; 
int g = 2;
float valfoto; 
float oldvalfoto; 
int duration, distance;

void setup()
{
  pinMode(tri, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(spk, OUTPUT);
  oldvalfoto = analogRead(pin);
  valfoto = oldvalfoto;
  myservo.attach(9);  
  pos = 40;
  dir = 1; 
  tone(5, 500, 200);
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  digitalWrite(tri, LOW);
  delay(10);
  digitalWrite(tri, HIGH);
  delay(10);
  digitalWrite(tri, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1;
  if(distance<10){
    analogWrite(spk, 255);}
    else{
      analogWrite(spk, 00);}
  Serial.println(valfoto); 
  if(valfoto < oldvalfoto) {
    dir = -dir; 
  }
  pos += dir * 5; 
  pos = max(-80,pos);
  pos = min(120,pos);
  myservo.write(pos);
  oldvalfoto = valfoto; 
  delay(150); 
   valfoto = 0;
  for(int i=0;i<20;i++) {
     valfoto += analogRead(pin) / 20.0;
  }
}
