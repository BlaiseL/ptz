#include <AccelStepper.h>

AccelStepper pan(AccelStepper::FULL2WIRE, 8, 9);
AccelStepper tilt(AccelStepper::FULL2WIRE,6,7);

int spd = 1000;    // The current speed in steps/second

void setup()
{  
  
  pan.setMaxSpeed(1000);
  pan.setSpeed(500);
  tilt.setMaxSpeed(1000);
  tilt.setSpeed(500);
  tilt.move(500);
}

void loop()
{  
  tilt.move(500);
}
  
  
