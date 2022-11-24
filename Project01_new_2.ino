#include <TimerOne.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(7,8);//Rx Tx

int ECG_pin = 0;
int Beat_pin = 1;

void setup(){
  Serial.begin(9600);
  BTSerial.begin(9600);

  Timer1.initialize(1000);//before is 2000(try i set it to 1000)
  Timer1.attachInterrupt(AnalogAD);
  Timer1.start();
}

void AnalogAD(){
  int reading0 = analogRead(ECG_pin);
  int reading1 = analogRead(Beat_pin);

  float Voltage0 = (float)reading0 /1023*5*500;
  float Voltage1 = (float)reading1 /1023*5*500;

  Serial.print(Voltage0, 3);

  BTSerial.print(Voltage0, 3);
}

void loop(){

}