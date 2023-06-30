////////////////////////////////////
//Definitions
////////////////////////////////////

// Motor (L298n)
#define ENA          6
#define motorInput1  8
#define motorInput2  9
#define motorInput3  10
#define motorInput4  11
#define ENB          7

#define MotorSpeed 60

////////////////////////////////////
//Setup Function
////////////////////////////////////
void setup()
{

  //Motor Init
  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);
  pinMode(motorInput3, OUTPUT);
  pinMode(motorInput4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  analogWrite(ENA, MotorSpeed); //Left Motor initial Speed
  analogWrite(ENB, MotorSpeed); //Right Motor initial Speed

}

////////////////////////////////////
//Loop Function
////////////////////////////////////
void loop() {

  Move();
  delay(1000);
  Stop();
  delay(1000);
  Left();
  delay(1000);
  Stop();
  delay(1000);
  Right();
  delay(1000);
  Stop();
  delay(1000);
  Back();
  delay(1000);
  Stop();
  delay(1000);
  Sharp_Left();
  delay(1000);
  Stop();
  delay(1000);
  Sharp_Right();
  delay(1000);
  Stop();
  delay(1000);
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
