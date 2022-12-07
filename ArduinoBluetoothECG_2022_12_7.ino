
#include <TimerOne.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(7,8);//this is the bluetooth: Rx(pin)->7 Tx(pin)->8

int ECG_pin = 0;// ecg pin in analog in A0
int Beat_pin = 1;// beat pin in analog in A1

void setup(){
  //The baud rate is the rate at which information is transferred in a communication channel. 
  //Baud rate is commonly used when discussing electronics that use serial communication. 
  //In the serial port context, "9600 baud" means that the serial port is capable of transferring a maximum of 9600 bits per second
  Serial.begin(9600);//you could tinker on this part change the baud rate
  BTSerial.begin(9600);

  Timer1.initialize(1000);//normal1000 milisecond == 1 second 
  Timer1.attachInterrupt(AnalogAD);// to function analogAD
  Timer1.start();//start the timer
}

void AnalogAD(){
  int reading0 = analogRead(ECG_pin); // read the ecg pin
  int reading1 = analogRead(Beat_pin); // read the beat pin

  float Voltage0 = (float)reading0 /1023*5*500; //converting analog value to digital values
  float Voltage1 = (float)reading1 /1023*5*500;

  //println to send new lines of data dont use print
  Serial.println(Voltage0, 3);//printing the value to the serial monitor
  BTSerial.println(Voltage0, 3);//sending the data thru bluetooth
  
}

void loop(){

}
//link for changing the arduino (refer to step number2)
//https://www.instructables.com/How-to-Change-the-Name-of-HC-06-Bluetooth-Module/

