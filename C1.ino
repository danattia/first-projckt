#define trigpin 12 
#define echopin 11 
#define ledPing 3
long duration;
int distance;
bool was=false;
void setup() {
  // put your setup code here, to run once:
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
pinMode(ledPing,OUTPUT);
Serial.begin(9600);
}
float maxLenInMicroSec=100 * 2 / 0.034;
void loop() {
  
  // put your main code here, to run repeatedly:
sendTrig();
duration = pulseIn(echopin, HIGH,maxLenInMicroSec);
distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
 
 if (distance<=19 && distance>0){
  
    digitalWrite(ledPing,HIGH);
  }
 if(distance==21 || distance==0){
  
  
    digitalWrite(ledPing,LOW);
  
  }
   
      
}
void sendTrig(){
  digitalWrite(trigpin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigpin,HIGH);
   delayMicroseconds(10);
   digitalWrite(trigpin,LOW);
   
}
