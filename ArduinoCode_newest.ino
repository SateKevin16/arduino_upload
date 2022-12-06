
#include <TimerOne.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(7,8);//Rx Tx

int ECG_pin = 0;
int Beat_pin = 1;

void setup(){
  Serial.begin(19200);
  BTSerial.begin(19200);

  Timer1.initialize(0.01);//normal(1000) changed
  Timer1.attachInterrupt(AnalogAD);
  Timer1.start();
}

void AnalogAD(){
  int reading0 = analogRead(ECG_pin);
  int reading1 = analogRead(Beat_pin);

  float Voltage0 = (float)reading0 /1023*5*500;
  float Voltage1 = (float)reading1 /1023*5*500;
  //println

  Serial.println(Voltage0, 3);
  BTSerial.println(Voltage0, 3);
}

void loop(){

}
//link for changing the arduino (step number2)
//https://www.instructables.com/How-to-Change-the-Name-of-HC-06-Bluetooth-Module/

