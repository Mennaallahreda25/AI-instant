
#include <Servo.h>

////////////////////////////////////
//Definitions
////////////////////////////////////
#define potpin     A8   // analog pin used to connect the potentiometer
#define Servo_Pin  9

Servo myservo;  // create servo object to control a servo

////////////////////////////////////
//Global Variables
////////////////////////////////////

int val;    // variable to read the value from the analog pin

////////////////////////////////////
//Setup Function
////////////////////////////////////
void setup() {
  myservo.attach(Servo_Pin);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
//Seriting pin A9 as HIGH to act as VCC for Potentiometer
 pinMode(A9,OUTPUT);
 digitalWrite(A9,1);
}

////////////////////////////////////
//Loop Function
////////////////////////////////////

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  Serial.print("Servo Angle :  ");
  Serial.println(val);
  delay(15);                           // waits for the servo to get there
}
