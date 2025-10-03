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

//variables
const int freq = 555;
const int pChA = 0;
const int pChB = 2;
const int res = 8;
int dCyc = 255;
int info[6+5];

void setup() {
  //pin setup
  pinMode(m01, OUTPUT);
  pinMode(m02, OUTPUT);
  pinMode(m03, OUTPUT);
  pinMode(m04, OUTPUT);
  pinMode(eA, OUTPUT);
  pinMode(eB, OUTPUT);

  //pwm channel settings
  ledcAttachChannel(eA, freq, res, pChA);
  ledcAttachChannel(eB, freq, res, pChB);

  //Bth setup
  BT.begin("Lithium pain in the ass.");
}

void loop() {
  if (BT.available() > 0){ //format (forward down left right powa)
    String Arbuff = BT.readString();
    string buff(Arbuff.c_str(), Arbuff.length());
    istringstream inp (buff);
    int s;
    for (int i = 0; i < 5; i++) {
      inp >> s;
      info[i] = s;
    }
    dCyc = info[4];

    //on commands
    if (info[0] == 1 && info[1] != 1){
      ledcWrite(eA, (dCyc*4/5));
      ledcWrite(eB, (dCyc*4/5));
      digitalWrite(m01, HIGH);
      digitalWrite(m03, HIGH);
    }
    if (info[1] == 1 && info[0] != 0){
      ledcWrite(eA, (dCyc*4/5));
      ledcWrite(eB, (dCyc*4/5));
      digitalWrite(m02, HIGH);
      digitalWrite(m04, HIGH);
    }
    if (info[2] == 1 && (info[0] != 1 || info[1] != 1)){
      ledcWrite(eA, (dCyc*4/5));
      ledcWrite(eB, (dCyc*4/5));
      digitalWrite(m02, HIGH);
      digitalWrite(m03, HIGH);
    }
    if (info[3] == 1 && (info[0] != 1 || info[1] != 1)){
      ledcWrite(eA, (dCyc*4/5));
      ledcWrite(eB, (dCyc*4/5));
      digitalWrite(m01, HIGH);
      digitalWrite(m04, HIGH);
    }
    if (info[2] == 1 && (info[0] == 1 || info[1] == 1)){
      ledcWrite(eB, (dCyc));
    }
    if (info[3] == 1 && (info[0] == 1 || info[1] == 1)){
      ledcWrite(eA, (dCyc));
    }

    //off commands
    if (info[0] == 0){
      digitalWrite(m01, LOW);
      digitalWrite(m03, LOW);
    }
    if (info[1] == 0){
      digitalWrite(m02, LOW);
      digitalWrite(m04, LOW);
    }
    if (info[2] == 0){
      digitalWrite(m01, LOW);
      digitalWrite(m04, LOW);
    }
    if (info[3] == 0){
      digitalWrite(m02, LOW);
      digitalWrite(m03, LOW);
    }
  }
}
