//Pass coordinates for the camera to move to as pan,tilt over serial. Speeds still need to be tuned but functional

#include <AccelStepper.h>  //Used to control the Pan/Tilt Steppers

//These are the objects for each servo.
AccelStepper pan(AccelStepper::DRIVER, 8, 9);
AccelStepper tilt(AccelStepper::DRIVER, 10, 11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  pan.setMaxSpeed(1000000);
  pan.setSpeed(1000000);
  tilt.setMaxSpeed(1000000);
  tilt.setSpeed(1000000);
}

void loop() {
// put your main code here, to run repeatedly:
// if there's any serial available, read it:
  while (Serial.available() > 1) {
    long panl = Serial.parseInt();
    long tiltl = Serial.parseInt();
    Serial.print("Pan is:");
    Serial.println(panl);
    Serial.print("Tilt is:");
    Serial.println(tiltl);
    if (Serial.read() == '\n') {
      pan.runToNewPosition(panl);
      tilt.runToNewPosition(tiltl);
      Serial.print("tilt moved to:");
      Serial.println(tilt.currentPosition());
      Serial.print("pan moved to:");
      Serial.println(pan.currentPosition());
      Serial.flush();
    }
    
  }
}
    
