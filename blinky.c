/**
 * Author: Eduardo Athayde
 * Date: May 2020
 * Purpose: Blink the LED in a sencon interval
 * Language: C
 */

#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>


#define ledPin 0

void main(void) {
  puts("Program starting. Press CTRL + C to quit");
  
  wiringPiSetup(); // initialise wiringPi

  pinMode(ledPin, OUTPUT); // Set Pin mode
  printf("Using pin %d\n",ledPin);

  while(1) {
    digitalWrite(ledPin, HIGH); // make GPIO output level HIGH
    puts("Led is turn to ON >>>>");
    delay(1000);
    digitalWrite(ledPin, LOW); // make GPIO output level LOW
    puts("Led is turn to OFF >>>>");
    delay(1000);
  }

}

