
//Includes
////////////////////////////////////

#include <NewPing.h>

////////////////////////////////////
//Definitions
////////////////////////////////////


//Ultrasonic sensor

#define TRIG_PIN 2
#define ECHO_PIN 3

#define MAX_DISTANCE 200

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);


////////////////////////////////////
//Global Variables
////////////////////////////////////

int distance = 100;

////////////////////////////////////
//Setup Function
////////////////////////////////////
void setup()
{

  Serial.begin(9600);

  //ultrasonic
  pinMode(TRIG_PIN, OUTPUT); // Sets the trigPin as an Output

  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an Input
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);

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

  distance = readPing();
  Serial.print("distance   ");
  Serial.println(distance);
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
