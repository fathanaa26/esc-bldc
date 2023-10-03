#include <Arduino.h>

int led_1 = PA1, led_2 = PA2, led_3 = PA3, pot_pin = PA5;
int potVal;

void setup(){
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);

  pinMode(pot_pin, INPUT);

}

void loop(){
  potVal = map(analogRead(pot_pin), 0, 1023, 0, 255);
  analogWrite(led_1, potVal);

}

