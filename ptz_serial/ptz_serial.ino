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
char tiltChannel = 0;
char panChannel = 1;




//This is a character that will hold data from the Serial port.
char serialChar = 0;

void setup()
{
  Serial.begin(57600);
  pan.setMaxSpeed(10000);
  pan.setSpeed(1000);
  tilt.setMaxSpeed(10000);
  tilt.setSpeed(1000);
}

void loop() {
  while (Serial.available() <= 0); //Wait for a character on the serial port.
  serialChar = Serial.read();     //Copy the character from the serial port to the variable
  if (serialChar == tiltChannel) { //Check to see if the character is the servo ID for the tilt servo
    Serial.print("In da Loop");
    while (Serial.available() <= 0); //Wait for the second command byte from the serial port.
    input=Serial.read();
    long number = atol( input );
      tilt.moveTo(number); //Set the tilt servo position to the value of the second command byte received on the serial port
      Serial.print("Tilt is: ");
      Serial.println(tilt.currentPosition());      
    }
  }
  else if (serialChar == panChannel) { //Check to see if the initial serial character was the servo ID for the pan servo.
      while (Serial.available() <= 0); //Wait for the second command byte from the serial port.
      static char input[16];
      static uint8_t i;
      char c = Serial.read();

      if ( c != '\r' && i < 15 ) // assuming "Carriage Return" is chosen in the Serial monitor as the line ending character
      {
        input[i++] = c;
      }
      else
      {
        input[i] = '\0';
        i = 0;

        long number = atol( input );
        pan.moveTo(number);
        Serial.print("Pan is: ");
        Serial.println(pan.currentPosition());
      }  //Set the pan servo position to the value of the second command byte received from the serial port.
    }
    //If the character is not the pan or tilt servo ID, it is ignored.
    

  }
