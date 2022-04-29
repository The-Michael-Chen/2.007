// include additional headers
#include <Servo.h>
 //global declarations
#define SERVO 4        //define a pin for servo
Servo myservo;        // initialize  servo
#define SERVOR 5        //define a pin for servo
Servo myservoR; 
// played around with values that sets the servos to each position
// these values need to be set for each servo!!!
const int neutral = 1500;
const int forward = 2000;
const int backward = 1000;
const int rbackward = 2000; // reverse right servo 
const int rforward = 1000; // reverse right servo  
//--- Function: Setup ()
void setup()
{ 
  pinMode (SERVO, OUTPUT); // want servo pin to be an output
  myservo.attach(SERVO); // attach pin to the servo 
  myservo.writeMicroseconds(neutral);  // set servo to mid-point
  myservoR.attach(SERVOR); // attach pin to the servo 
  myservoR.writeMicroseconds(neutral);  // set servo to mid-point
}
 
//--- Function: loop ()
void loop()
{
    forwardDrive(3000); // go forward 
    pause();         // Pauses the program 
    turnLeft(2100); // turns 90 degrees left
    pause();           // Pauses the program 
    forwardDrive(600); // go forward 
    pause();    // Pauses the program 
    turnLeft(2100); // turns 90 degrees left
    pause();   // Pauses the program 
    forwardDrive(3000); // go forward
}

void turnLeft(int duration) {
  myservo.writeMicroseconds(backward); // set servo to forward pulse
  myservoR.writeMicroseconds(rforward);
  delay(duration);   
}

void forwardDrive(int duration) {
  myservo.writeMicroseconds(forward); // set servo to forward pulse
  myservoR.writeMicroseconds(rforward);
  delay(duration);  
}

void pause() { // a function to pause the robot 
  myservo.writeMicroseconds(neutral);    // set servo to mid-point
  myservoR.writeMicroseconds(neutral); // same here 
  delay(500);  
}
