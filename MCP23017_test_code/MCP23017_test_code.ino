#include <MCP23017.h>

#include <Wire.h>

/*
Blinks port A7 on the MCP23017 port expander and pin 13 of the arduino
*/

MCP23017 p = MCP23017(B0100000);

// the setup function runs once when you press reset or power the board
void setup() {
  Wire.begin();
  Serial.begin(9600);
  
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  p.pinMode(7, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  p.digitalWrite(7, HIGH);
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  p.digitalWrite(7, LOW);
  delay(1000);              // wait for a second
}