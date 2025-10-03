#include "BluetoothSerial.h"
#include <bits/stdc++.h>
#define m01 16
#define m02 17
#define m03 18
#define m04 19
#define eA 4
#define eB 5
BluetoothSerial BT;
using namespace std;

const int freq = 555;
const int pChA = 0;
const int pChB = 2;
const int res = 8;
int dCyc = 255;
int info[6+5];

void setup() {
  //pin setup
  pinOutput(m01, OUTPUT);
  pinOutput(m02, OUTPUT);
  pinOutput(m03, OUTPUT);
  pinOutput(m04, OUTPUT);
  pinOutput(eA, OUTPUT);
  pinOutput(eB, OUTPUT);

  //pwm channel settings
  ledcAttachChannel(eA, freq, res, pChA);
  ledcAttachChannel(eB, freq, res, pChB);

  //Bth setup
  BT.begin("Lithium pain in the ass.");
}

void loop() {
  if (BT.avalible() > 0){
    String inp = BT.read()
    string buff = (inp.c_str(), inp.length());
    istringstream iss (buff);
    int s;
    for (int i = 0; i < 5; i++){
      iss >> s;
      info[i] = s;
    }

    // on commands (i'll add later)
    // off commands
  }
}
