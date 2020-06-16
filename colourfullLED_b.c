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

  while(1) {
	for (int i = 100; i > -1; i--) {
	  red = i;
	  green = 100;
	  blue = 100;
	  setLedColour(red, green, blue);
	  delay(50);
	}
	delay(1000);
	for (int i = 100; i > -1; i--) {
	  red = 100;
	  green = i;
	  blue = 100;
	  setLedColour(red, green, blue);
	  delay(50);
	}
	delay(1000);
	for (int i = 100; i > -1; i--) {
	  red = 100;
	  green = 100;
	  blue = i;
	  setLedColour(red, green, blue);
	  delay(50);
	}
	delay(1000);

  }
  return 0;
}

