
#include <Servo.h>
const int buzzerPin = 12;
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int intdelay = 20;
int timeBetween = 2000;
int positionMax = 90;
int pos = 0;    // variable to store the servo position
const int songLength = 18;
// Notes is an array of text characters corresponding to the notes
// in your song. A space represents a rest (no tone)

char notes[] = " c C c C c C c C c C c C c C c C c C  "; // a space represents a rest

// Beats is an array of values for each note and rest.
// A "1" represents a quarter-note, 2 a half-note, etc.
// Don't forget that the rests (spaces) need a length as well.

int beats[] = {4,2,4,2,4,2,4,2,4,1,4,1,4,1,4,1,4,1};

// The tempo is how fast to play the song.
// To make the song play faster, decrease this value.

int tempo = 300;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
    pinMode(buzzerPin, OUTPUT);
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
 //Serial.println(myResult);
 
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
 Serial.println(result);
  return result20;
  //return random(1,20);
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
}

