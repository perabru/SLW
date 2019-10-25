
#include <Ultrasonic.h>
#include <Servo.h>

 Servo myservo;
 int pos = 0;
 char data = 0; 

 
#define TRIGGER_PIN 12
#define ECHO_PIN   13

 Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
Servo s; // Variável Servo

 
void setup ()
{
  myservo.attach(7);
  
  Serial.begin(9600);
  s.write(0); // Inicia motor posição zero
}
 
void loop()
{
   float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Exibe informacoes no serial monitor
  //Serial.print("Distancia em cm: ");
  Serial.println(cmMsec);
  //Serial.print(" - Distancia em polegadas: ");
  //Serial.println(inMsec);
  delay(1000);
  char data = Serial.read(); 
  
  if( data=='1' || data=='A'){
  }
  if (cmMsec > 15)
  for (pos = 0; pos <= 90; pos += 1){  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    //myservo.attach(7);
    myservo.write(pos); // tell servo to go to position in variable 'pos'
    
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
   //myservo.attach(7);
    myservo.write(pos);  // tell servo to go to position in variable 'pos'
    
    delay(15);   // waits 15ms for the servo to reach the position
  }
  {
 
    
  }


if (cmMsec < 15){
    for (pos = 0; pos <= 0; pos += 1){  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
   // myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
   myservo.detach();// waits 15ms for the servo to reach the position
  }
  for (pos = 0; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  myservo.detach();              // tell servo to go to position in variable 'pos'
    delay(15);   // waits 15ms for the servo to reach the position

  }
    }

if( data=='0' || data=='B'){
  for (pos = 0; pos <= 0; pos += 1){  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 0; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  }
  }
