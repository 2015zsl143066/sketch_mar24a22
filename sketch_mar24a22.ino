#include <SoftwareSerial.h>   //Software Serial Port
#define Status 13 // indicate the bluetooth  status.
#define DEBUG_ENABLED  1

void setup() 
{ 
  Serial.begin(9600);
  pinMode(Status, OUTPUT);
  setupBlueToothConnection();
} 
 
void loop() 
{ 
  char recvChar;
  while(1){
    // A1 used as to sense bluetooth  status: low-disconnected, high-connected.
    if(digitalRead(A1)==HIGH){
      digitalWrite(Status, HIGH);
    }else{
      digitalWrite(Status, LOW);
    }
    if(Serial.available()){//eck if there's any data sent from the remote bluetooth shield
      recvChar = Serial.read();
      Serial.print(recvChar);
    //  Serial1.print("receive:");
      Serial.print(recvChar);
    //  Serial1.println();
    }
    if(Serial.available()){//eck if there's any data sent from the local serial terminal, you can add the other applications here
      recvChar  = Serial.read();
      Serial.print(recvChar);
    }
  }
} 
 
void setupBlueToothConnection()
{
  Serial.begin(9600);
  Serial.print("AT+NAMEDFunBTSlave"); //t the bluetooth name as "DFunBTSlave"
  Serial.println();
  delay(2000); // This delay is required.
  Serial.println("The slave bluetooth name is 'DFunBTSlave', now is inquirable!");
  Serial.flush();
}

