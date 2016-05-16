
#include <AccelStepper.h>

AccelStepper pan(AccelStepper::FULL2WIRE, 8, 9);
AccelStepper tilt(AccelStepper::FULL2WIRE,10,11);

int spd = 1000;    // The current speed in steps/second
int moveCommand[3];
void setup()
{  
  Serial.begin(9600);
  pan.setMaxSpeed(1000);
  pan.setSpeed(1000);
  tilt.setMaxSpeed(1000);
  tilt.setSpeed(1000);
}

void loop()
{  
  
  if(Serial.available()) {
    moveCommand = Serial.read();
    if (c == 'f') {  // forward
      sign = 1;
    }
    if (c == 'r') {  // reverse
      sign = -1;
    }
    if (c == 's') {  // stop
      sign = 0;
    }
    if (c == '1') {  // super slow
      spd = 10;
    }
    if (c == '2') {  // medium 
      spd = 100;
    }
    if (c == '3') {  // fast
      spd = 1000;
    }
    stepper.setSpeed(sign * spd);
  }
  stepper.runSpeed();
}
    
