#include "Servo.h"
int Th1, Th2, tmp;
Servo M1, M2;
void setup() 
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  digitalWrite(13,0);
  Th1 = 0;
  Th2 = 0;
  M1.attach(2);
  M2.attach(4);

  M1.write(90);
  M2.write(90);
  
}
boolean lzer = false;
void loop() 
{
  delay(200);
  //digitalWrite(13,lzer==true?HIGH:LOW);

  if(Serial.available()>=2)
  {
    Th1 = Serial.read();
    Th2 = Serial.read();
    M1.write(Th1);
    M2.write(Th2);
    digitalWrite(13,HIGH);

    //Remove any extra worng reading
    while(Serial.available()) tmp = Serial.read();    
    
    // Run the robotic arm here. For testing, we will 
    //switch On or switch off a LED according to Th1 value
    if(Th1 ==1) digitalWrite(13,1);
    else digitalWrite(13,0);

    
    Serial.print('1'); // This tell the PC that Arduino is Ready for next angles
  }


}
