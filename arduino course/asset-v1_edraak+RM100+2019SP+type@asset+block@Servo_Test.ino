
///////////////////////////////////
//Includes
////////////////////////////////////
#include <Servo.h>

////////////////////////////////////
//Definitions
////////////////////////////////////

//Servo
Servo myservo;

#define Servo_Pin 4

#define Servo_CenterAngle 115
#define Servo_RightAngle  50
#define Servo_LeftAngle  170

////////////////////////////////////
//Setup Function
////////////////////////////////////
void setup()
{

  //Servo Init
  myservo.attach(Servo_Pin);
  myservo.write(Servo_CenterAngle);

}

////////////////////////////////////
//Loop Function
////////////////////////////////////
void loop() {

myservo.write(Servo_CenterAngle);
delay(1000);
myservo.write(Servo_RightAngle);
delay(1000);
myservo.write(Servo_LeftAngle);
delay(1000);

}
