#include <Servo.h>

Servo leftDown;
Servo rightDown;  
Servo leftUp;
Servo rightUp;// create servo object to control a servo
// twelve servo objects can be created on most boards
//180 is anti-clock most, since all of  right part rotation in my program is clockwise, it should be achived by decreasing the angle. all left part need anti-clock
// wise rotation, so it increase from 0.

// variable to store the servo position
int rightDownPos = 110;    
int rightUpPos=90;      
int leftDownPos=120;
int leftupPos=180;         // start posotion

int posCountDown=0;
int posCountUp=0;     //for rotation control

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  rightDown.attach(9); // attaches the servo on pin 9 to the servo object
  rightDown.write(rightDownPos); 
  digitalWrite(LED_BUILTIN, HIGH);
  rightUp.attach(11);
  rightUp.write(rightUpPos);
digitalWrite(LED_BUILTIN, LOW);
  leftDown.attach(8);
  leftDown.write(leftDownPos);
digitalWrite(LED_BUILTIN, HIGH);
  leftUp.attach(10);
  leftUp.write(leftupPos);
digitalWrite(LED_BUILTIN, LOW);
delay(3000);
}
void loop() {
  for (posCountUp=0;posCountUp <= 90; posCountUp += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    leftUp.write(leftupPos-posCountUp);  
    rightUp.write(rightUpPos-posCountUp);                                         // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (posCountDown = 0; posCountDown <= 90; posCountDown += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    leftDown.write(leftDownPos-posCountDown);  
    rightDown.write(rightDownPos-posCountDown);  
    delay(20);                       // waits 15ms for the servo to reach the position
  }
   for (posCountUp = 90; posCountUp >= 0; posCountUp -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    leftUp.write(leftupPos-posCountUp);  
    rightUp.write(rightUpPos-posCountUp);                                         // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (posCountDown = 90; posCountDown >= 0; posCountDown -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    leftDown.write(leftDownPos-posCountDown);  
    rightDown.write(rightDownPos-posCountDown);            // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }
}