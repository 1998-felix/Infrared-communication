
 
// Include IR Remote Library by Ken Shirriff
#include <IRremote.h>
 
// Define sensor pin
bool state;
float speeed;
const int RECV_PIN = 4;
 
// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;

 
void setup(){
  // Serial Monitor @ 9600 baud
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);
  // Enable the IR Receiver
  irrecv.enableIRIn();
}
 
void loop(){
 if (irrecv.decode(&results)){
    Serial.println(results.value, HEX);
        switch (results.value){
            case 2297893604 : 
              Serial.println("1");
              speeed=255/5;
              break;
            case 735147844 : 
              Serial.println("2"); 
              speeed=255/4;
              break;
            case 2155809525 : 
              Serial.println("3"); 
              speeed=255/3;
              break;
            case 2155866135 : 
              Serial.println("4"); 
              speeed=255/2;
              break;
            case 2155833495  : 
              Serial.println("5"); 
              speeed=255;
              break;

          
          }
 }
 if (irrecv.decode(&results)){
    // Print Code in HEX
        Serial.println(results.value, HEX);
        if(results.value==2155836045){
        analogWrite(8,speeed);
        digitalWrite(9,LOW);}
        irrecv.resume();
        }
   
         if (irrecv.decode(&results)){
    // Print Code in HEX
        Serial.println(results.value, HEX);
        if(results.value==2155819725){
        digitalWrite(8,LOW);
        digitalWrite(9,speeed);}
        irrecv.resume();
      }
      
      
       
     
     
 
 }
