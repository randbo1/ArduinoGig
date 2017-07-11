
#include <Servo.h>
const int buttonPin = 2;     // the number of the pushbutton pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
    // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {

  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
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

  float myResult = (result / 6.20) + 15.0;
 
  return myResult;
 // return random(15,180);
}
//TODO: Replace with call to Pot2 to return values between 250 and 5000 2.5 sec to 5 seconds.
int getTimeBetween()
{
 
  int result = analogRead(A1)* 5;  //how often
 
  float result250 = result + 250;

  return result250;
  //return random(250,5000);
}
//TODO: Replace with call to POT3 to return a value between 1 and 20 this is the delay between moving by degree
int getDelay()
{
  int result = analogRead(A2) ;  //how quickly or slowly servo moves 
  float result20 = (result / 51.2) +1.0;
  Serial.println(result20);
  return result20;
  //return random(1,20);
}

