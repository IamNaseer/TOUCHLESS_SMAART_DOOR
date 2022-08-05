#define trigpin 8
#define echopin 7
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include<Servo.h>
Servo s1;

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
void setup() {
  s1.attach(9);
  Serial.begin(9600);
  Serial.println("Adafruit MLX90614 test");  
  mlx.begin(); 
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT); 
}
void loop() {
  long distance,duration;
digitalWrite(trigpin,LOW);
delayMicroseconds(2);
digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin,LOW);
duration = pulseIn(echopin,HIGH);
distance = (duration/2) / 29.1;
if(distance>=200 || distance<=0)
{
  Serial.println("Out of range");
}
else
{
  Serial.print("DISTANCE:");
  Serial.println(distance);
  if(distance <=10 and distance>=2)

{
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF()); 
  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");
  Serial.println();
  delay(2000);
  if (mlx.readObjectTempC()>=28 & mlx.readObjectTempC()<=40  )
  {
     for (int i=0; i<= 180; i+= 1)
   {
    s1.write(i);             
    delay(0);                     
   }
    
 for (int i=180; i>=0; i-= 1) 
   { 
    s1.write(i);            
    delay(100);
  }
}
 else
 delay(5000);
}
}
}
