/*
Adafruit Arduino - Lesson 10. Simple Sounds
*/

int speakerPin = 12;

int numTones = 14;
//int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440, 2200};
//            mid C  C#   D    D#   E    F    F#   G    G#   A
int tones[]= {261, 440, 261, 440, 261, 440, 261, 440, 261, 440, 2800, 2800, 2800, 2200 };


void setup()
{
  for (int i = 0; i < numTones; i++)
  {
    tone(speakerPin, tones[i]);
    delay(500);
  }
  noTone(speakerPin);
}

void loop()
{
}
