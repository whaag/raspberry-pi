/**
 * Author: Eduardo Athayde
 * Date: Jun 2020
 * Purpose: Operates a RGBLED
 * Language: C
 */

#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>


#define ledPinRed   0
#define ledPinGreen 1
#define ledPinBlue  2

void setupLedPin(void) {
  softPwmCreate(ledPinRed,   0, 100); //Create SoftPWM pin for red
  softPwmCreate(ledPinGreen, 0, 100); //Create SoftPWM pin for green
  softPwmCreate(ledPinBlue,  0, 100); //Create SoftPWM pin for blue
}

void setLedColour(int red, int green, int blue) {
  softPwmWrite(ledPinRed,   red); //Set the duty cycle
  softPwmWrite(ledPinGreen, green); //Set the duty cycle
  softPwmWrite(ledPinBlue,  blue);
}

int main(void) {
  int red, green, blue;
  puts("Program starting. Press CTRL + C to quit");

  wiringPiSetup(); //Initialise wiringPi
  setupLedPin();

  return 0;
}

