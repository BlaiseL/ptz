/*
* Serial Command Structure: 2 bytes - [ID Byte][Servo Position byte]
* ID byte should be 0 or 1.
* Servo position should be a value between 0 and 180.
* Invalid commands are ignored
* The servo position is not error checked.
*/

#include <AccelStepper.h>  //Used to control the Pan/Tilt Steppers

//These are the objects for each servo.
AccelStepper pan(AccelStepper::DRIVER, 8, 9);
AccelStepper tilt(AccelStepper::DRIVER, 10, 11);

//These are variables that hold the servo IDs.
long tiltChannel = 2;
long panChannel = 3;
long inpu = -1;
long number = -1;



//This is a character that will hold data from the Serial port.

void setup()
{
  Serial.begin(9600);
  pan.setMaxSpeed(10000);
  pan.setSpeed(1000);
  tilt.setMaxSpeed(10000);
  tilt.setSpeed(1000);

}

void loop() {
while(!Serial.available()) ; //Wait for a character on the serial port.
inpu=Serial.parseInt();    //Copy the character from the serial port to the variable
Serial.println(inpu);
Serial.flush();
if (inpu == tiltChannel) { //Check to see if the character is the servo ID for the tilt servo
  Serial.println("Ready for Tilt Amount");
  Serial.flush();
  while(!Serial.available()); //Wait for the second command byte from the serial port.
  number=Serial.parseInt();
  tilt.moveTo(number); //Set the tilt servo position to the value of the second command byte received on the serial port
  Serial.print("Tilt is: ");
  Serial.println(tilt.currentPosition());
}

//  else if (inpu == panChannel) 
//  { //Check to see if the initial serial character was the servo ID for the pan servo.
//      while (Serial.available() <= 8); //Wait for the second command byte from the serial port.
//      
//        pan.moveTo(number);
//        Serial.print("Pan is: ");
//        Serial.println(pan.currentPosition());
//  }  //Set the pan servo position to the value of the second command byte received from the serial port.
}
    //If the character is not the pan or tilt servo ID, it is ignored.
