
int pinTrigger = 7;
int pinEcho = 8;
int buzzerPin = 3;
int numTones =7;
int tones[]= {261,349,392,440,392,330,-10};

long Zeit;
int Abstand;
boolean AlarmOn, last_state;

void setup(){
  AlarmOn = false;
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(buzzerPin,OUTPUT);
  analogWrite(buzzerPin,255);
  noTone(buzzerPin);
  Serial.begin(9600);
}

void loop(){

// start the ultrasonic sensor:
digitalWrite(pinTrigger,LOW);
delay(5);
digitalWrite(pinTrigger,HIGH);
delay(10);
digitalWrite(pinTrigger,LOW);
Zeit = pulseIn(pinEcho,HIGH); // Zeit hin und zurück
Zeit = Zeit/2;
// Abstand = Zeit * Geschwindigkeit
Abstand = int((Zeit*0.0343)); // Schallgeschwindigkeit @20°C
Serial.print("Abstand(cm): ");
Serial.println(Abstand);

if (Abstand < 16)//fals der Abstand kleiner asl 16cm ist, wird der Alarm angeschaltet
 { 
  AlarmOn = true;
 }
else
  AlarmOn = false;

if((AlarmOn)&&(last_state!= AlarmOn)){
  //makeSound(50);
  melodyBuzzer();
}
noTone(buzzerPin);
last_state = AlarmOn;
delay(500);
}

void makeSound(int freqNum)
{
  for(int i =0;i<10;i++){
  analogWrite(buzzerPin, 0);
  delay(freqNum);
  analogWrite(buzzerPin, 255);
  delay(freqNum);
  }
 }
void melodyBuzzer()
 {
  for (int i=0;i<numTones;i++){
  tone(buzzerPin, tones[i]);
  delay(100);
  }
  noTone(buzzerPin);
 }
 
