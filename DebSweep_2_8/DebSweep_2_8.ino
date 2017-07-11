/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int intdelay = 20;
int timeBetween = 2000;
int positionMax = 90;
int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  timeBetween = getTimeBetween();
  positionMax = getPositionMax();
  intdelay = getDelay();
  delay(timeBetween);

  for (pos = 0; pos <= positionMax; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(intdelay);                       // waits 15ms for the servo to reach the position
  }
  for (pos = positionMax; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(intdelay);                       // waits 15ms for the servo to reach the position
  }
}
//TODO: replace this with call to Pot1. return values between 15 and 180 max
int getPositionMax()
{

  int result = analogRead(A0); //A0 is how far the servo goes range 0 to 1024
  //Serial.println(result);
  float myResult = (result / 6.20) + 15.0;
// Serial.println(myResult);
 
  return myResult;
 // return random(15,180);
}
//TODO: Replace with call to Pot2 to return values between 250 and 5000 2.5 sec to 5 seconds.
int getTimeBetween()
{
 
  int result = analogRead(A1)* 5;  //how often
  //Serial.println(result);
 
  float result250 = result + 250;
//Serial.println(result250);
  return result250;
  //return random(250,5000);
}
//TODO: Replace with call to POT3 to return a value between 1 and 20 this is the delay between moving by degree
int getDelay()
{
  int result = analogRead(A2) ;  //how quickly or slowly servo moves 
  float result20 = (result /156) +1.0;
// Serial.println(result);
 Serial.println(result20);
  return result20;
  //return random(1,20);
}

