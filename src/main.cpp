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

      digitalWrite(in_high_u, HIGH);
      digitalWrite(in_low_u, LOW);

      digitalWrite(in_high_v, LOW);
      digitalWrite(in_low_v, LOW);

      digitalWrite(in_high_w, HIGH);
      digitalWrite(in_low_w, LOW);

      // Serial.println("FASE 1");

      delay(10);

      digitalWrite(in_high_u, LOW);
      digitalWrite(in_low_u, HIGH);

      digitalWrite(in_high_v, HIGH);
      digitalWrite(in_low_v, LOW);

      digitalWrite(in_high_w, LOW);
      digitalWrite(in_low_w, LOW);

      // Serial.println("FASE 2");

      delay(10);

      digitalWrite(in_high_u, LOW);
      digitalWrite(in_low_u, HIGH);

      digitalWrite(in_high_v, LOW);
      digitalWrite(in_low_v, LOW);

      digitalWrite(in_high_w, HIGH);
      digitalWrite(in_low_w, LOW);

      // Serial.println("FASE 3");

      delay(10);

      digitalWrite(in_high_u, LOW);
      digitalWrite(in_low_u, LOW);

      digitalWrite(in_high_v, LOW);
      digitalWrite(in_low_v, LOW);

      digitalWrite(in_high_w, HIGH);
      digitalWrite(in_low_w, LOW);

      // Serial.println("FASE 4");

      delay(10);

      digitalWrite(in_high_u, HIGH);
      digitalWrite(in_low_u, LOW);

      digitalWrite(in_high_v, LOW);
      digitalWrite(in_low_v, HIGH);

      digitalWrite(in_high_w, LOW);
      digitalWrite(in_low_w, LOW);

      // Serial.println("FASE 5");

      delay(10);

      digitalWrite(in_high_u, LOW);
      digitalWrite(in_low_u, LOW);

      digitalWrite(in_high_v, LOW);
      digitalWrite(in_low_v, LOW);

      digitalWrite(in_high_w, HIGH);
      digitalWrite(in_low_w, LOW);

      // Serial.println("FASE 6");
      delay(10);
  
}