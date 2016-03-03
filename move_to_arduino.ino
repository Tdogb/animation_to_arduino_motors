#include <Servo.h>

Servo servo_X;
Servo servo_Y;
Servo servo_Z;

int origXpos = 0;
int origYpos = 0;
int origZpos = 0;
float locX;
float locY;
float locZ;
float nextLocX;
float nextLocY;
float nextLocZ;
float nextMotorLocX;
float nextMotorLocY;
float nextMotorLocZ;
float animArrayX[] = {1.12332, 3.59464, 6.06595, 7.18927};
float animArrayY[] = {1.12332, 3.59464, 6.06595, 7.18927};
float animArrayZ[] = {1.12332, 3.59464, 6.06595, 7.18927};
int arrayline = 0;
int i = 1;

//Interpolating
/*float interpolatetimeX = 41.6; //for 24 fps
float percentageX;
float counterX;
*/

//test
float oldValue;
float finalValue;
float counterTime;
float counter;
float percentage;
float interpolate;
float interpolateTime = 41.6;

void setup() {
  servo_X.attach(9); //attach servo control to pin 9
  servo_Y.attach(8);
  servo_Z.attach(7);
  locX = origXpos;
  locY = origYpos;
  locZ = origZpos;
}

void loop() {
//Lerping
/*if (finalValue != oldValue) counterTime = interpolateTime;
 if (counterTime != 0) counter++;
 if (counter > counterTime) counter = counterTime;
 percentage = map (counter, 0, interpolateTime, 0., 1.);
 interpolate = lerp (oldValue, finalValue, percentage);
 if (percentage == 1.) oldValue = finalValue;
 counterTime = 0;
*/
 
  while(i=1, arrayline++){
    nextLocX = animArrayX[arrayline];
    nextMotorLocX = nextLocX - locX;
    servo_X.write(nextMotorLocX);
    delay (10);
    locX = nextLocX;
   }
  while(i=1) {
    nextLocY = animArrayY[arrayline];
    nextMotorLocY = nextLocY - locY;
    servo_Y.write(nextMotorLocY);
    delay (10);
    locX = nextLocY;
  }
  while(i=1) {
    nextLocZ = animArrayZ[arrayline];
    nextMotorLocZ = nextLocZ - locZ;
    servo_Y.write(nextMotorLocZ);
    delay (10);
    locX = nextLocZ;
  }
}
