
#include <SoftwareSerial.h>
 
SoftwareSerial blue(2,3); // bluetooth module connected here 
int Vdata = 0; 
 
void setup(){ 
  pinMode(40, INPUT); // Setup for leads off detection LO +
  pinMode(41, INPUT); // Setup for leads off detection LO -
   Serial.begin(9600); 
   blue.begin(9600); 
   
} 
void loop(){ 
   
  if((digitalRead(40) == 1)||(digitalRead(41) == 1)){
    Serial.println('!');
  }
  else{
    // send the value of analog input 0:
      blue.println(analogRead(A0));
  }
  //Wait for a bit to keep serial data from saturating
  delay(1); 
}