/**
 * Author: Eduardo Athayde
 * Date: Jun 2020
 * Purpose: Operates a RGBLED
 * Language: C
 */

#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>
#include <stdlib.h>


#define ledPinRed   0
#define ledPinGreen 1
#define ledPinBlue  2

void setupLedPin(void) {
  softPwmCreate(ledPinRed,   0, 100); //Create SoftPWM pin for red
  softPwmCreate(ledPinBlue,  0, 100); //Create SoftPWM pin for blue
}

void setLedColour(int red, int blue) {
  softPwmWrite(ledPinRed,   red); //Set the duty cycle
  softPwmWrite(ledPinBlue,  blue);
}

int main(void) {
  int red, blue;
  puts("Program starting. Press CTRL + C to quit");

  wiringPiSetup(); //Initialise wiringPi
  setupLedPin();

  while(1) {
    if(red) {
      red = 0;
      blue = 100;
    } else {
      red = 100;
      blue = 0;
    }
    setLedColour(red, blue);
    delay(300);
  }
  return 0;
}

