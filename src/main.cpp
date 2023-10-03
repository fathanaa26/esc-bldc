#include <Arduino.h>
int count, potVal, pwm_in = 0;

unsigned long prevMicros = 0;

void changePot(){
  Serial.println(potVal);
}

void setup(){
  pinMode(PA0, OUTPUT);
  pinMode(PA1, OUTPUT);
  pinMode(PA2, OUTPUT);
  pinMode(PA7, INPUT);
  attachInterrupt(digitalPinToInterrupt(PA7), changePot, RISING);

  Serial.begin(115200);
}

void loop(){
  potVal = map(analogRead(A7), 0,4095, 0 ,1000000);
  unsigned long currentMicros = micros();

  if(currentMicros - prevMicros >= potVal){
    Serial.print("TEST SERIAL ");
    Serial.println("count");
    prevMicros = currentMicros;
    count++;

    if(count == 1){
      digitalWrite(PA0, HIGH);
      digitalWrite(PA1, LOW);
      digitalWrite(PA3, LOW);
      digitalWrite(PC13, LOW);
    }else if(count == 2){
      digitalWrite(PA0, LOW);
      digitalWrite(PA1, HIGH);
      digitalWrite(PA3, LOW);
      digitalWrite(PC13, LOW);
    }else if(count == 3){
      digitalWrite(PA0, LOW);
      digitalWrite(PA1, LOW);
      digitalWrite(PA3, HIGH);
      digitalWrite(PC13, LOW);
    }else{
      count = 1;
      digitalWrite(PA0, HIGH);
      digitalWrite(PC13, HIGH);
    }
  }
}

