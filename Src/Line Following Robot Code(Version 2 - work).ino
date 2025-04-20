#include <AFMotor.h>

#define left A0
#define right A1

AF_DCMotor motor1(1); 
AF_DCMotor motor2(2);

int leftState;
int rightState;
int y;

void setup() {
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  Serial.begin(9600);
}
int sensor_Read(){
  int x;
  leftState = digitalRead(left);
  rightState = digitalRead(right);
  if (leftState == 0 && rightState == 0){
    x = 1;
  }
  else if (leftState == 0 && rightState == 1){
    x = 2;
  }
  else if (leftState == 1 && rightState == 0){
    x = 3;
  }
  else if (leftState == 1 && rightState == 1){
    x = 4;
  }
  return x;
}
void loop() {

    y = sensor_Read();
    Serial.println (y);
   switch(y){

      case 1 :
       motor1.run(FORWARD);
       motor1.setSpeed(50);
       motor2.run(FORWARD);
       motor2.setSpeed(50);
      break;

      case 2 :
       motor1.run(FORWARD);
       motor1.setSpeed(60);
       motor2.run(BACKWARD);
       motor2.setSpeed(40);
      break;

      case 3 :
       motor1.run(BACKWARD);
       motor1.setSpeed(40);
       motor2.run(FORWARD);
       motor2.setSpeed(60);
      break;

      case 4 :
       motor1.run(RELEASE);
       motor1.setSpeed(0);
       motor2.run(RELEASE);
       motor2.setSpeed(0);
      break;
  }
}

