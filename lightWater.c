/**
 * Author: Eduardo Athayde
 * Date: May 2020
 * Purpose: Make a water lamp using a LED bar 
 * Language: C
 */

#include <wiringPi.h>
#include <stdio.h>


#define ledCount 10
int pins[ledCount] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void main(void) {
  
  puts("Starting program.");

  wiringPiSetup();

  for (int i = 0; i < ledCount; i++) { // Set pinMode for all LED pins to OUTPUT
    pinMode(pins[i], OUTPUT);
  }

  while(1) {
    for (int i = 0; i < ledCount; i++) { // move LED ON from left to right
      digitalWrite(pins[i], LOW);
      delay(100);
      digitalWrite(pins[i], HIGH);
    }

    for (int i = ledCount - 1; i > -1; i--) { // move LED ON from right to left
      digitalWrite(pins[i], LOW);
      delay(100);
      digitalWrite(pins[i], HIGH);
    }
  }
}

