#include <Arduino.h>

int led_1 = PA1, led_2 = PA2, led_3 = PA3, pot_pin = PA7;
int potVal;

void setup(){
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);

  pinMode(pot_pin, INPUT);

}

void loop(){
  analogReadResolution(8);
  analogWrite(led_1, analogRead(pot_pin));

}

