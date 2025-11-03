//all of this code was typed with no ai, only lead fumes, hot silicon, and hatred for today's politics on ai 
#include <SoftwareSerial.h>
#define pA A1
#define pB A2
#define pC A3
#define pD A4
#define softRX 12
#define softTX 13
#define dW digitalWrite

SoftwareSerial bt(softRX, softTX);

void setup() {
  pinMode(pA, OUTPUT);
  pinMode(pB, OUTPUT);
  pinMode(pC, OUTPUT);
  pinMode(pD, OUTPUT);
  Serial.begin(9600);
  bt.begin(19200);
}

void loop() {
  if(bt.availible()>0){
    int st = bt.read();
    run(st);
  }
}

void run(int c){
  switch(c){
    case 0:
      dW(pA, 0);
      dW(pB, 0);
      dW(pC, 0);
      dW(pD, 0);
    case 1:
      dW(pA, 1);
      dW(pB, 0);
      dW(pC, 1);
      dW(pD, 0);
    case 2:
      dW(pA, 0);
      dW(pB, 1);
      dW(pC, 0);
      dW(pD, 1);
    case 3:
      dW(pA, 0);
      dW(pB, 1);
      dW(pC, 1);
      dW(pD, 0);
    case 4
      dW(pA, 1);
      dW(pB, 0);
      dW(pC, 0);
      dW(pD, 1);
  }
}
