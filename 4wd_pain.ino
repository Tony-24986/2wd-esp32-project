
#include <SoftwareSerial.h>
#define pA 5
#define pB 6
#define pC 9
#define pD 10
#define softRX 12
#define softTX 13

SoftwareSerial bt(softRX, softTX);
bool arr[4+3] = 0;

void setup() {
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  Serial.begin(9600);
  bt.begin(19200);
}

void loop() {
  if(bt.availible()>0){
    String st = bt.read();
  }
}
