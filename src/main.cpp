// format Serial
// u, v, w, v_u, v_v, v_w, pot_val
// u = HIGH/LOW
// v = HIGH/LOW
// w = HIGH/LOW
// v_x = adc voltage

#include <Arduino.h>
uint32_t count, potVal, pwm_in = 0;
unsigned long prevMicros = 0;

int pwm_p1 = PA3, pwm_p2 = PA4, pwm_p3 = PA5;
int pot_pin = PA7;

int pot_val;

int he_pin[3] = {PA0, PA1, PA2};

float he_V[3];
byte he_bin[3];
float sensorTrigerVal = 200.0;


void setup(){
  for(int i = 0; i < 3; i++){
    pinMode(he_pin[i], OUTPUT);
  }

  pinMode(pwm_p1, INPUT);
  pinMode(pwm_p2, INPUT);
  pinMode(pwm_p3, INPUT);

  pinMode(pot_pin, INPUT);

  Serial.begin(115200);
  
}

void loop(){
  analogReadResolution(12);
  pot_val = map(analogRead(pot_pin), 0, 4095, 10, 1000);
  
  for(int i = 0; i < 3; i++){
    he_V[i] = float(analogRead(he_pin[i]) * 3300.0 / 4095.0);

    if(he_V[i] > sensorTrigerVal){
      he_bin[i] = 1;
    }else{
      he_bin[i] = 0;
    }

  }

  for(int i = 0; i < 3; i++){
    Serial.print(he_bin[i]);
    Serial.print(", ");
  }

  for(int i = 0; i < 3; i++){
    Serial.print(he_V[i]);
    Serial.print(", ");
  }

  Serial.print(pot_val);
  Serial.print(", ");
  
  Serial.println();
  delay(pot_val);

}

