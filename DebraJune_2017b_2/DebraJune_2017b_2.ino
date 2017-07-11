/*

   Demonstrates the use a 16x2 LCD display and
  4x4 LCD display.  T
   The  Arduino circuit connection for LCD:
   * LCD RS  pin to analog pin A0
   * LCD  Enable pin to analog pin A1
   * LCD D4  pin to analog pin A2
   * LCD D5  pin to analog pin A3
   * LCD D6  pin to analog pin A4
   * LCD D7  pin to analog pin A5
   The  Arduino circuit connection for MAtrix Key Pad:
   * ROW1 pin  to digital pin 5
   * ROW2 pin  to digital pin 4
   * ROW3 pin  to digital pin 3
   * ROW4 pin  to digital pin 2
   * COLUMN1  pin to digital pin 6
   * COLUMN2  pin to digital pin 7
   * COLUMN3  pin to digital pin 8
   * COLUMN4  pin to digital pin 9
   */
  // include the library code:
  #include <LiquidCrystal.h>
  #include <Keypad.h>
  #include <Servo.h>
Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position
int servoSpeed = 0;
int servoSwing =90;
int servoDelay = 50;



  //initialize the library with the numbers of the interface pins
  LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
  //4x4 Matrix key pad
  const byte ROWS = 4; // Four rows
  const byte COLS = 4; // Four columns
  // Define the Keymap
  char keys[ROWS][COLS] = 
  {
   
  {'*','0','#','D'},
   
  {'7','8','9','C'},
   
  {'4','5','6','B'},
   
  {'1','2','3','A'}
  };
 
  byte rowPins[ROWS] = { 5, 4, 3, 2 };

  byte colPins[COLS] = { 6, 7, 8, 9 }; 
  // Create the Keypad
  
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
  void setup() {
  {
      myservo.attach(10);// attaches the servo on pin 10 to the servo object
  }
    // set up the LCD's number of columns and rows
   
  lcd.begin(16, 2);
    // Print a message to the LCD.
   
 lcd.print("Sped|Swing|Delay"); 
  }
  void loop() 
  {
    char key  = kpd.getKey();
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
   
  lcd.setCursor(0, 1);
    // print the number of seconds since reset:
   
 // lcd.print("SEC= ");
   
 // lcd.print(millis() / 1000);
    // Check for a valid key
   
  if(key)  
    {
       // set the cursor to column 9, line 1
       //  (note: line 1 is the second row, since counting begins with 0):
      
      
  lcd.setCursor(9, 1);
      
  //Print the detected key
 Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // prints title with ending line break
 // Serial.println (key);

       switch(key){

        case '1':
       // lcd.setCursor(0,5);
        servoSpeed ++; 
       // Serial.println(servoSpeed);
       // lcd.print ( String(servoSpeed));
        break;
        case '4':
       // lcd.setCursor(0,5);
       
        servoSpeed --;
       //  Serial.println(servoSpeed);
       // lcd.print(String(servoSpeed));
        break;
        case '2':
        servoSwing ++;
        break;
        case '5':
        servoSwing --;
        break;
        case '3':
        servoDelay ++;
        break;
        case '6':
        servoDelay --;
        break;
        default:
        break;
       
       }
    lcd.setCursor(0,5);
    lcd.print(String(servoSpeed));
    lcd.setCursor(4,5);
    lcd.print('|');// 
    lcd.setCursor(6,5);
    lcd.print(String(servoSwing));
    lcd.setCursor(10,5);
    lcd.print('|');
    lcd.setCursor(12,5);
    lcd.print(String(servoDelay));
      
 // lcd.print("KEY= ");
      
//  lcd.print(key);
//   for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
 //   myservo.write(pos);              // tell servo to go to position in variable 'pos'
 //   delay(15);                       // waits 15ms for the servo to reach the position
 // }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    }  
  }

