#include <Arduino.h>
uint32_t count, potVal, pwm_in = 0;
unsigned long prevMicros = 0;
int u_pin = PA0, v_pin = PA1, w_pin = PA2;
int pwm_p1 = PA3, pwm_p2 = PA4, pwm_p3 = PA5;
int pot_pin = PA7;

void setup(){
  pinMode(u_pin, OUTPUT);
  pinMode(v_pin, OUTPUT);
  pinMode(w_pin, OUTPUT);

  pinMode(pwm_p1, INPUT);
  pinMode(pwm_p2, INPUT);
  pinMode(pwm_p3, INPUT);

  pinMode(pot_pin, INPUT);

  Serial.begin(115200);
  
}

void loop(){
  analogReadResolution(12);
  

  Serial.print("U: ");
  Serial.print(analogRead(u_pin));
  Serial.print(" V: ");
  Serial.println(analogRead(u_pin) * 3300 / 4095);

  Serial.print("V: ");
  Serial.print(analogRead(v_pin));
  Serial.print(" V: ");
  Serial.println(analogRead(v_pin) * 3300 / 4095);

  Serial.print("W: ");
  Serial.print(analogRead(w_pin));
  Serial.print(" V: ");
  Serial.println(analogRead(w_pin) * 3300 / 4095);

  Serial.println();
  delay(400);

}

