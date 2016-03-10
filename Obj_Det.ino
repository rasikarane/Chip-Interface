#include "Ultrasonic.h"

Ultrasonic ultrasonic (6,7);

const int ledgreen = 13;
const int ledyellow = 12;
const int ledred = 11;
long microsec = 0;
float distanceCM = 0;

int notes[] = {300, 600};

void setup () {
Serial.begin(9600); 

pinMode(ledgreen,OUTPUT); 
pinMode(ledyellow,OUTPUT); 
pinMode(ledred,OUTPUT); 
}

void loop () {
microsec = ultrasonic.timing(); 
distanceCM = ultrasonic.convert(microsec, Ultrasonic::CM); 

ledDistance();

Serial.print(distanceCM);
Serial.println(" cm");
delay(100);

}

void ledDistance() {

digitalWrite(ledgreen,LOW);
digitalWrite(ledyellow,LOW);
digitalWrite(ledred,LOW);

if (distanceCM > 50) {
digitalWrite(ledgreen,HIGH);
noTone (3);
}

if (distanceCM <=50 and distanceCM >= 20) {
digitalWrite(ledyellow,HIGH);
tone (3,notes[0]);
}

if (distanceCM < 20) {
digitalWrite(ledred,HIGH);
tone (3,notes[1]);
}
 
}
