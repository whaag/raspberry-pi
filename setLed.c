/**
 * Author: Eduardo Athayde
 * Date: May 2020
 * Purpose: set the LED at position 0 (GPIO_17) to ON or OFF
 * Language: C
 */

#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <softPwm.h>


#define SHORT_HELP "-h"
#define LONG_HELP "--help"
#define ON "on"
#define OFF "off"
#define ledPin 0


void performAction(const char *argument);
void throwError();
void setLed(unsigned int mode);

void main(int argc, char *args[]) {
  
  if (2 == argc) {
    performAction(args[1]);
  } else {
    throwError();
  } 
}

void performAction(const char *argument) {
  if (strcmp(SHORT_HELP, argument) == 0 ||  strcmp(LONG_HELP, argument) == 0)  {
    puts("Type `./setLed on` to set the LED on and `./setLed off` to switch it off. -h or --help to show this help");
  } else if (strcmp(ON, argument) == 0) {
    setLed(HIGH);    ;
  } else if (strcmp(OFF, argument) == 0) {
    setLed(LOW);       
  } else {
    throwError();
  }
}

void throwError() {
    puts("That's unacceptable! Type -h for help");
}

void setLed(unsigned int mode) {
    wiringPiSetup(); // initialise wiringPi
    digitalWrite(ledPin, mode); // make GPIO output level HIGH
}
