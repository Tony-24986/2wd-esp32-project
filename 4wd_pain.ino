#include <SoftwareSerial.h>
#define pA 5
#define pB 6
#define pC 9
#define pD 10

void setup(){
	Serial.begin(9600);
	pinMode(pA, OUTPUT);
	pinMode(pB, OUTPUT);
	pinMode(pC, OUTPUT);
	pinMode(pD, OUTPUT);
}

void loop(){

}
