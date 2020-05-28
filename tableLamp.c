/**
 * Author: Eduardo Athayde
 * Date: May 2020
 * Purpose: Use a button to switch the LED on or off
 * Language: C
 */

#include <wiringPi.h>
#include <stdio.h>

#define ledPin 0    //GPIO 17
#define buttonPin 1 //GPIO 18

int ledState = LOW;         //Current state of the LED
int buttonState = HIGH;     //Current state of the Button
int lastButtonState = HIGH; //Last status of the button
long lastChangeTime;        //Time of the last change of button status
long captureTime = 50;      //Stable time for button state
int reading;

int main(void) {

  puts("Starting application");

  wiringPiSetup();

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  pullUpDnControl(buttonPin, PUD_UP); //pull up to high level
  
  while (1) {
    reading = digitalRead(buttonPin); // Read the state of the button
    
    if(reading != lastButtonState) {
      lastChangeTime = millis();
    }

    // If the state of the button change lasts longer the time set
    // it means the button state is effective changed rather than a buffering
    if (millis() - lastChangeTime > captureTime) {
      // if button state is changed, update data
      if (reading != buttonState) {
        buttonState = reading;
        
        // If the state is LOW, it means the action is pressing
        if (buttonState == LOW) {
          puts("Button is pressed!\n");
          ledState = !ledState; // Reverse the LED state
          
          if (ledState) {
            puts("Turn ON  light.");
          } else {
            puts("Turn OFF light.");
          }

          //if the state is HIGH, it measn the action is releaseing
        } else {
          puts("Button is releaseing!");
        }
      } 
    }
    
    digitalWrite(ledPin, ledState);
    lastButtonState = reading;
  }

  return 0;
}
