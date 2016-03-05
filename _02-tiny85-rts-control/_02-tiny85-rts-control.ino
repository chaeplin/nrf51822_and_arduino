// BLE400
// 1) to auto reset when uploading.
// 2) to prevent RTS go to LOW while serial is opened. 

#include <avr/interrupt.h>
#include <avr/sleep.h>

#include <SoftwareSerial.h>
const int rx = -1;
const int tx = 3;

int RTS_PIN = 4;
int RESET_PIN = 0;

unsigned long duration;

SoftwareSerial mySerial(rx, tx);

void setup()
{
  pinMode(RTS_PIN, INPUT_PULLUP);
  pinMode(RESET_PIN, OUTPUT);
  digitalWrite(RESET_PIN, HIGH);

    // serial
  pinMode(rx, INPUT);
  pinMode(tx, OUTPUT);
  mySerial.begin(9600);

}

void loop()
{
  duration = pulseIn(RTS_PIN, LOW, 1000000);
  if (duration > 1 ) {
    mySerial.println(duration);
    // reset
    digitalWrite(RESET_PIN, LOW);
    //delayMicroseconds(400);
    delay(500);
    digitalWrite(RESET_PIN, HIGH);
  }
}
