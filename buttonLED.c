/**
 * Author: Eduardo Athayde
 * Date: May 2020
 * Purpose: Use a button to control the LED                  
 * Language: C
 */

#include <wiringPi.h>
#include <stdio.h>

#define ledPin    0 // GPIO17
#define buttonPin 1 // GPIO18

void main(void) {
  puts("Starting application");

  wiringPiSetup();

  pinMode(ledPin, OUTPUT); // Set ledPin to output
  pinMode(buttonPin, INPUT); //Set buttonPin to input

  pullUpDnControl(buttonPin, PUD_UP); // pull up to HIGH level

  while(1) {
    if(digitalRead(buttonPin) == LOW) { // button is pressed
      digitalWrite(ledPin, HIGH);       // Make GPIO output HIGH level
      puts("Button is pressed, led turned on >>>"); 
    } else { // button is released
      digitalWrite(ledPin, LOW); // Make GPIO output LOW level
      puts("Button is released, led turned off <<<");
    }
  }
}
