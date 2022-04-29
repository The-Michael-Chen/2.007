#include <Servo.h>

Servo liftMotor;
const int liftPin = 9;
const int liftInputPin = 5;

Servo doorServo; 
const int doorPin = 8; 

const int servoInputPin = 4; 
int ch4 = 0;
int ch5 = 0;
int turn;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("hello world"); 
  pinMode(liftInputPin, INPUT);
  liftMotor.attach(liftPin);
  pinMode(servoInputPin, INPUT);
  doorServo.attach(doorPin);
}

// i want to take the value 1000 -> 2000
// closer the value is to 2000 the value is the closer it should be to 100
// closer the value is to 1000 the closer it should be to 255


void loop() {
  // door servo code 
  int newch5 = pulseIn(liftInputPin, HIGH, 25000);
  if (abs(newch5 - ch5) > 30) {
    //Serial.println(ch4); // 1250->1770
    ch5 = newch5; 
    turn = map(ch5, 1000, 2000, -500, 500); //center over zero
    turn = constrain(turn, -255, 255); //only pass values whose absolutes are
    
    Serial.println(turn);
    liftMotor.write(turn); //1760 down 1600 up
  }

  
  int newch4 = pulseIn(servoInputPin, HIGH, 25000);
  if (abs(newch4 - ch4) > 30) {
    //Serial.println(ch4); // 1250->1770
    ch4 = newch4; 
    turn = map(ch4, 1000, 2000, 255, 100);
    doorServo.write(turn);
//    turn = map(ch4, 1000, 2000, -500, 500); //center over zero
//    turn = constrain(turn, -255, 255); //only pass values whose absolutes are
//    
//    Serial.println(turn);
//    doorServo.write(turn); //1760 down 1600 up
  }
  
}
