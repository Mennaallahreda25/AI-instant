

///////////////////////////////////
//Includes
////////////////////////////////////

#include <NewPing.h>
#include <Servo.h>

////////////////////////////////////
//Definitions
////////////////////////////////////

#define Debug

//Ultrasonic sensor

#define TRIG_PIN 2
#define ECHO_PIN 3

#define MAX_DISTANCE 200

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);


// Motor (L298n)
#define ENA          6
#define motorInput1  8
#define motorInput2  9
#define motorInput3  10
#define motorInput4  11
#define ENB          7

#define MotorSpeed 60

//#define MotorSpeed_POT A8

//Servo
Servo myservo;

#define Servo_Pin 4
#define Servo_CenterAngle 100
#define Servo_RightAngle  30
#define Servo_LeftAngle   150

////////////////////////////////////
//Global Variables
////////////////////////////////////

int distance = 100;

////////////////////////////////////
//Setup Function
////////////////////////////////////
void setup()
{
#ifdef Debug
  Serial.begin(9600);
#endif
  //ultrasonic
  pinMode(TRIG_PIN, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an Input
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);

  //Motor Init
  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);
  pinMode(motorInput3, OUTPUT);
  pinMode(motorInput4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // pinMode(MotorSpeed_POT, INPUT);

  analogWrite(ENA, MotorSpeed); //Left Motor initial Speed
  analogWrite(ENB, MotorSpeed); //Right Motor initial Speed

  //Servo Init
  myservo.attach(Servo_Pin); // set servo pin
  myservo.write(Servo_CenterAngle); // set servo angle

  delay(2000);

  //Get multiple readings before start
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);

  delay(2000);
}

////////////////////////////////////
//Loop Function
////////////////////////////////////
void loop() {

  int distanceR = 0;
  int distanceL =  0;
  delay(40);

  if (distance <= 30)
  {
    Stop();
    delay(100);
    Back();
    delay(300);
    Stop();
    delay(200);
    distanceR = lookRight();
    delay(200);
    distanceL = lookLeft();
    delay(200);

    if (distanceR >= distanceL)
    {
      Sharp_Left();
      delay(300);
      Stop();
    } else
    {
      Sharp_Right();
      delay(300);
      Stop();
    }

  }
  else
  {
    Move();
  }
  distance = readPing();
  Serial.print("distance   ");
  Serial.println(distance);
}


////////////////////////////////////
//Move Function
//Move both motors in forward direction
////////////////////////////////////
void Move() {

  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);

}
////////////////////////////////////
//Back Function
//Move both motors in backward direction
////////////////////////////////////
void Back() {

  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);

}
////////////////////////////////////
//Right Function
//Move Right motor in forward direction and stop Left motor
////////////////////////////////////
void Right() {

  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);

}
////////////////////////////////////
//Left Function
//Move Left motor in forward direction and stop Right motor
////////////////////////////////////
void Left() {

  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);

}
////////////////////////////////////
//Stop Function
//Stop both motors directions
////////////////////////////////////
void Stop() {

  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);

}
////////////////////////////////////
//Sharp_Right Function
//Move Right motor in forward direction and Left motor in backward direction
////////////////////////////////////
void Sharp_Right() {

  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);

}
////////////////////////////////////
//Sharp_Left Function
//Move Left motor in forward direction and Right motor in backward direction
////////////////////////////////////
void Sharp_Left() {

  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);

}
////////////////////////////////////
//lookRight Function
//Turn servo to the right and take reading
///////////////////////////////////
int lookRight()
{
  myservo.write(Servo_RightAngle);
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(Servo_CenterAngle);
  return distance;
}
////////////////////////////////////
//lookLeft Function
//Turn servo to the Left and take reading
///////////////////////////////////
int lookLeft()
{
  myservo.write(Servo_LeftAngle);
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(Servo_CenterAngle);
  return distance;
  delay(100);
}
////////////////////////////////////
//readPing Function
//Takes ultrasonic sensor reading
///////////////////////////////////
int readPing() {
  delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0)
  {
    cm = 250;
  }
  return cm;
}
