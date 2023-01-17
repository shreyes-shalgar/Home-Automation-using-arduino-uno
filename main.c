#include <SoftwareSerial.h>
const int hot = 2.8; //set hot parameter
//const int cold = 85; //set cold parameter
int LDR = A0; // select the input pin for the LDR
int sensorValue = 0; // variable to store the value coming from the 
sensor
int led = 3;
void setup() {// declare the ledPin as an OUTPUT: 
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  pinMode(A2, INPUT); //temp sensor
  //pinMode(2, OUTPUT); //blue
  //pinMode(3, OUTPUT); //green 
  pinMode(4, OUTPUT); //red 
  Serial.begin(9600);
}
void loop() {
    int sensor = analogRead(A2);
    float voltage = (sensor / 1024.0) * 5.0; 
    float tempC = (voltage - .5) * 100; 
    float tempF = (tempC * 1.8) + 32;
    //Serial.print("\ntemp: ");
    //Serial.print(tempF);

    if (tempF < hot/*cold*/) { //cold
      //digitalWrite(2, HIGH);
      //digitalWrite(3, LOW); 
      digitalWrite(4, LOW);
      //Serial.println(" It's Cold.");
    }

    else if (tempF >= hot) 
    { //hot
      //digitalWrite(2, LOW);
      //digitalWrite(3, LOW); 
      digitalWrite(4, HIGH);
      //Serial.println(" It's Hot.");
    }

    //else 
      { //fine
      //digitalWrite(2, LOW);
      //digitalWrite(3, HIGH);
      //digitalWrite(4, LOW);
      //Serial.println(" It's Fine.");
      //} 
    delay(0);

    sensorValue = analogRead(LDR);
    //Serial.print("\nLDR value: ");
    //Serial.print(sensorValue); 
    if (sensorValue < 80)
      {//Serial.println(" LED light on."); 
      digitalWrite(led,HIGH); 
      delay(1000);}
    else
    {
      digitalWrite(led,LOW); 
      delay(sensorValue);
      }
}
