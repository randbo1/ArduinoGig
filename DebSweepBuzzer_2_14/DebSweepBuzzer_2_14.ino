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
bool useRandom = true;
const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status
  /*
This sketch uses the buzzer to play songs.
The Arduino's tone() command will play notes of a given frequency.
We'll provide a function that takes in note characters (a-g),
and returns the corresponding frequency from this table:

  note  frequency
  c     262 Hz
  d     294 Hz
  e     330 Hz
  f     349 Hz
  g     392 Hz
  a     440 Hz
  b     494 Hz
  C     523 Hz

For more information, see http://arduino.cc/en/Tutorial/Tone
*/

const int buzzerPin = 10;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);

  pinMode(buttonPin, INPUT);
 }
 {
  pinMode(buzzerPin, OUTPUT);
}
{
  int i, duration;

  for (i = 0; i < songLength; i++) // step through the song arrays
  {
    duration = beats[i] * tempo;  // length of note/rest in ms

    if (notes[i] == ' ')          // is this a rest? 
    {
      delay(duration);            // then pause for a moment
    }
    else                          // otherwise, play the note
    {
      tone(buzzerPin, frequency(notes[i]), duration);
      delay(duration);            // wait for tone to finish
    }
    delay(tempo/10);              // brief pause between notes
  }

  // We only want to play the song once, so we'll pause forever:
  while(true){}
  // If you'd like your song to play over and over,
  // remove the above statement
}


int frequency(char note) 
{
  // This function takes a note character (a-g), and returns the
  // corresponding frequency in Hz for the tone() function.

  int i;
  const int numNotes = 8;  // number of notes we're storing

  // The following arrays hold the note characters and their
  // corresponding frequencies. The last "C" note is uppercase
  // to separate it from the first lowercase "c". If you want to
  // add more notes, you'll need to use unique characters.

  // For the "char" (character) type, we put single characters
  // in single quotes.

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};

  // Now we'll search through the letters in the array, and if
  // we find it, we'll return the frequency for that note.

  for (i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names[i] == note)         // Is this the one?
    {
      return(frequencies[i]);     // Yes! Return the frequency
    }
  }
  return(0);  // We looked through everything and didn't find it,
              // but we still need to return a value, so return 0.

void loop() {

  // set up the button state 
 
buttonState = digitalRead(buttonPin);
if(buttonState == HIGH){
  useRandom = true;
}
else
{
  useRandom = false;
}

Serial.println(buttonState);

  
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
// Serial.println(result20);
  return result20;
  //return random(1,20);
}

