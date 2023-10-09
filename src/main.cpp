#include <Arduino.h>
#include "main.h"

const int hes_u_pin = PB1, hes_v_pin = PB0, hes_w_pin = PA7;
const int in_high_u = PA0,in_low_u = PA1, in_high_v = PA2, in_low_v = PA3, in_high_w = PA4, in_low_w = PA5;
unsigned long prevMicros = 0;
const int hes_triggerVal = 200; 
int potVal;


  
  

void setup(){
  pinMode(hes_u_pin, INPUT);
  pinMode(hes_v_pin, INPUT);
  pinMode(hes_w_pin, INPUT);

  pinMode(in_high_u, OUTPUT);
  pinMode(in_low_u, OUTPUT);

  pinMode(in_high_v, OUTPUT);
  pinMode(in_low_v, OUTPUT);

  pinMode(in_high_w, OUTPUT);
  pinMode(in_low_w, OUTPUT);

  pinMode(PA6, INPUT);

  analogReadResolution(12);

  Serial.begin(115200);

}

int u, v ,w;
int du, dv ,dw;

void loop(){
  delayF(1000, PA6);
  

  potVal = map(analogRead(PA6), 0, 4095, 1, 100000);
  unsigned long currMicros = micros();

  if(currMicros - prevMicros >= potVal){

    prevMicros = currMicros;

    u = analogRead(hes_u_pin);
    v = analogRead(hes_v_pin);
    w = analogRead(hes_w_pin);

    if(u > 200){
      du = 1;  
    }else{
      du = 0;
    }
    if(v > 200){
      dv = 1;
    }else{
      dv = 0;
    }
    if(w > 200){
      dw = 1;
    }else{
      dw = 0;
    }
    // Serial.print(du);
    // Serial.print(dv);
    // Serial.println(dw);
  }
    
    if(du == 1 && dv == 0 && dw == 1){ // u 1, v 0 , w 1
      digitalWrite(in_high_u, HIGH);
      digitalWrite(in_low_u, LOW);

      digitalWrite(in_high_v, LOW);
      digitalWrite(in_low_v, LOW);

      digitalWrite(in_high_w, HIGH);
      digitalWrite(in_low_w, LOW);

      // Serial.println("FASE 1");

    }else if((du == 1 && dv == 0 && dw == 0)){ // u 1, v 0, w 0
      digitalWrite(in_high_u, LOW);
      digitalWrite(in_low_u, HIGH);

      digitalWrite(in_high_v, HIGH);
      digitalWrite(in_low_v, LOW);

      digitalWrite(in_high_w, LOW);
      digitalWrite(in_low_w, LOW);

      // Serial.println("FASE 2");

    }else if(du == 1 && dv == 1 && dw == 0){ // u 1, v 1, w 0
      digitalWrite(in_high_u, LOW);
      digitalWrite(in_low_u, HIGH);

      digitalWrite(in_high_v, LOW);
      digitalWrite(in_low_v, LOW);

      digitalWrite(in_high_w, HIGH);
      digitalWrite(in_low_w, LOW);

      // Serial.println("FASE 3");

    }else if(du == 0 && dv == 1 && dw == 0){ // u 0, v 1, w 0
      digitalWrite(in_high_u, LOW);
      digitalWrite(in_low_u, LOW);

      digitalWrite(in_high_v, LOW);
      digitalWrite(in_low_v, LOW);

      digitalWrite(in_high_w, HIGH);
      digitalWrite(in_low_w, LOW);

      // Serial.println("FASE 4");

    }else if(du == 0 && dv == 1 && dw == 1){ // u 0, v 1, w 1
      digitalWrite(in_high_u, HIGH);
      digitalWrite(in_low_u, LOW);

      digitalWrite(in_high_v, LOW);
      digitalWrite(in_low_v, HIGH);

      digitalWrite(in_high_w, LOW);
      digitalWrite(in_low_w, LOW);

      // Serial.println("FASE 5");

    }else if(du == 1 && dv == 0 && dw == 1){ // u 0, v 0, w 1
      digitalWrite(in_high_u, LOW);
      digitalWrite(in_low_u, LOW);

      digitalWrite(in_high_v, LOW);
      digitalWrite(in_low_v, LOW);

      digitalWrite(in_high_w, HIGH);
      digitalWrite(in_low_w, LOW);

      // Serial.println("FASE 6");
    }
  
  
}