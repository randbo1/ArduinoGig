/* @file EventSerialKeypad.pde
 || @version 1.0
 || @author Alexander Brevig
 || @contact alexanderbrevig@gmail.com
 ||
 || @description
 || | Demonstrates using the KeypadEvent.
 || #
 */
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};

byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
byte ledPin = 13; 

boolean blink = false;
boolean ledPin_state;
char IsProd = 'T';
void setup(){
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);              // Sets the digital pin as output.
    digitalWrite(ledPin, HIGH);           // Turn the LED on.
    ledPin_state = digitalRead(ledPin);   // Store initial LED state. HIGH when LED is on.
    keypad.addEventListener(keypadEvent); // Add an event listener for this keypad
}

void loop(){
 delay(20);
    
    char key = keypad.getKey();

    if (key) {
       // Serial.println(key);
       // Serial.println("line 45 printed");
    }
    if (blink){
        digitalWrite(ledPin,!digitalRead(ledPin));    // Change the ledPin from Hi2Lo or Lo2Hi.
        delay(100);
    }

    if(IsProd == 'T')
    {
   delay(1000);
key = keypad.getKey();
   delay(1000);
key = keypad.getKey();
   delay(1000);
key = keypad.getKey();
   delay(1000);
key = keypad.getKey();
   delay(1000);
key = keypad.getKey();
       if(key)
      {
        Serial.println("key from prod");
                Serial.println(key);
        }
      //Move the Servo
      Serial.println("moving servo");
   
    }
    else
    {
      Serial.println("adjusting Servo");
      if(key)
      {
                Serial.println(key);
        }
 
      
      
      }
}

// Taking care of some special events.
void keypadEvent(KeypadEvent key){
  //Serial.println("Keypad Event fired");
    switch (keypad.getState()){
    case PRESSED:
        if (key == '*') {
            digitalWrite(ledPin,!digitalRead(ledPin));
            ledPin_state = digitalRead(ledPin);        // Remember LED state, lit or unlit.
            IsProd = 'T';
        }
        else
        
        
        {
          IsProd = 'F';
        }
        break;

    case RELEASED:
        if (key == '*') {
            digitalWrite(ledPin,ledPin_state);    // Restore LED state from before it started blinking.
            blink = false;
        }
        else
        {
          IsProd = 'F';
        }
        break;

    case HOLD:
        if (key == '*') {
            blink = true;    // Blink the LED when holding the * key.
            IsProd = 'T';
        }
        else
        {
          IsProd = 'F';
        }
        break;
       
    }
}
