#include <TimerOne.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(7,8);

int ECG_pin = 0;
int Beat_pin = 1;

void setup(){
  Serial.begin(1200);
  BTSerial.begin(1200);

  Timer1.initialize(2000);
  Timer1.attachInterrupt(AnalogAD);
  Timer1.start();
}

void AnalogAD(){
  int reading0 = analogRead(ECG_pin);
  int reading1 = analogRead(Beat_pin);

  float Voltage0 = (float)reading0 /1023*5*500;
  float Voltage1 = (float)reading1 /1023*5*500;

  // float f_Voltage0 =0;
  // for(int i=0; i<100; i++){
  //   f_Voltage0 += Voltage0;
  //   delayMicroseconds(100);
  // }
  // f_Voltage0 /=100;

  Serial.println(Voltage0, 3);

  BTSerial.print(Voltage0, 3);
}

void loop(){

}