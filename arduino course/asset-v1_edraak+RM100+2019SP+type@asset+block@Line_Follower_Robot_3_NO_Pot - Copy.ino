

////////////////////////////////////
//Definitions
////////////////////////////////////
//#define Debug

// IR Sensors
#define sensor1   A2      // Left most sensor
#define sensor2   A1
#define sensor3   A0      // Right most sensor
//Doesn't have to be analog Pins

// Motor (L298n)
#define ENA          6
#define motorInput1  8
#define motorInput2  9
#define motorInput3  10
#define motorInput4  11
#define ENB          7

//#define MotorSpeed_POT A8

////////////////////////////////////
//Global Variables
////////////////////////////////////

int sensor[3] = {0, 0, 0}; // Initial Values of Sensors

int LastState = 1 ;   //Last State of movement the robot was at // 1 = move // 2 = Right // 3 = Left

int MotorSpeed = 50 ;      // Initial Value of the Motor Speed

////////////////////////////////////
//Setup Function
////////////////////////////////////
void setup()
{
#ifdef Debug
  Serial.begin(9600);
#endif

  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);

  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);
  pinMode(motorInput3, OUTPUT);
  pinMode(motorInput4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  analogWrite(ENA, MotorSpeed); //Left Motor initial Speed
  analogWrite(ENB, MotorSpeed); //Right Motor initial Speed

  delay(2000); //Delay to put the car in it's start position
}

////////////////////////////////////
//Loop Function
////////////////////////////////////
void loop() {

  Read_sensor_values(); //Read sensors and take action depending on this readings
}

////////////////////////////////////
//Read_sensor_value Function
//Read sensors and take action depending on this readings
////////////////////////////////////
void Read_sensor_values()
{
  sensor[0] = digitalRead(sensor1);
  sensor[1] = digitalRead(sensor2);
  sensor[2] = digitalRead(sensor3);

#ifdef Debug
  Serial.print(sensor[0]);
  Serial.print("\t");
  Serial.print(sensor[1]);
  Serial.print("\t");
  Serial.print(sensor[2]);
 

#endif

  if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 0)) { // Move Robot forward

    if (LastState != 1) {
      LastState = 1 ;
    }

    Move();

#ifdef Debug
    Serial.println("Move");
#endif
  }
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0)) {// Turn robot right side

    if (LastState != 2) {
      LastState = 2 ;
    }

    Right();

#ifdef Debug
    Serial.println("Right");
#endif
  }
  else if ((sensor[0] == 0) && (sensor[1] == 1 && (sensor[2] == 1))) { // Turn robot left side
    
    if (LastState != 3) {
      LastState = 3 ;
    }

    Left();

#ifdef Debug
    Serial.println("Left");
#endif

  }
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0)) { // Out of track

    if (LastState == 1) {
      Stop() ;
#ifdef Debug
      Serial.println("Stop");
#endif
    }
    else if (LastState == 2) {
      Sharp_Right() ;
#ifdef Debug
      Serial.println("Sharp_Right");
#endif
    }
    else if (LastState == 3) {
      Sharp_Left() ;
#ifdef Debug
      Serial.println("Sharp_Left");
#endif
    }
  }
  
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) ) { // Stop Robot
    
    Stop();

#ifdef Debug
    Serial.println("Stop");
#endif
  }
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
