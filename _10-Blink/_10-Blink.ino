/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  Serial.begin(115200);
  pinMode(17, OUTPUT);
  pinMode(4, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("Start");
  digitalWrite(17, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(4, LOW);
  delay(2000);              // wait for a second
  Serial.println("Change");
  digitalWrite(17, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(4, HIGH);
  delay(1000);              // wait for a second
}
