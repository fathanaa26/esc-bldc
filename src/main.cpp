// format Serial
// u, v, w, v_u, v_v, v_w, pot_val
// u = HIGH/LOW
// v = HIGH/LOW
// w = HIGH/LOW
// v_x = adc voltage

#include <Arduino.h>
#include <ArduinoJson.h>
unsigned long prevMicros = 0;

int pwm_p0 = PA3, pwm_p1 = PA4, pwm_p2 = PA5;
int pot_pin = PA7;

uint32_t pot_val;

int he_pin[3] = {PA0, PA1, PA2}; // U, V, W

float he_V[3];
byte he_bin[3];
float sensorTrigerVal = 200.0;

// StaticJsonDocument<50> doc;


byte fase = 0;


void setup(){
  for(int i = 0; i < 3; i++){
    pinMode(he_pin[i], OUTPUT);
  }

  pinMode(pwm_p0, OUTPUT); // coil_U
  pinMode(pwm_p1, OUTPUT); // coil_V
  pinMode(pwm_p2, OUTPUT); // coil_W

  digitalWrite(pwm_p0, LOW);
  digitalWrite(pwm_p1, LOW);
  digitalWrite(pwm_p2, LOW);

  pinMode(pot_pin, INPUT);

  Serial.begin(115200);
  
  
}

void loop(){
  analogReadResolution(12);
  pot_val = map(analogRead(pot_pin), 0, 4095, 1, 100000);
  
  for(int i = 0; i < 3; i++){
    he_V[i] = float(analogRead(he_pin[i]) * 3300.0 / 4095.0);

    if(he_V[i] > sensorTrigerVal){
      he_bin[i] = 1;
    }else{
      he_bin[i] = 0;
    }
  }

  if((he_bin[0] && he_bin[2] == 1) && he_bin[1] == 0){
    Serial.println("FASE 1");
  }
  if((he_bin[0] && he_bin[1] == 0) && he_bin[2] == 1){
    Serial.println("FASE 2");
  }
  if((he_bin[1] && he_bin[2] == 1) && he_bin[0] == 0){
    Serial.println("FASE 3");
  }
  if((he_bin[0] && he_bin[2] == 0) && he_bin[1] == 1){
    Serial.println("FASE 4");
  }
  if((he_bin[0] && he_bin[1] == 1) && he_bin[2] == 0){
    Serial.println("FASE 5");
  }
  if((he_bin[1] && he_bin[2] == 0) && he_bin[0] == 1){
    Serial.println("FASE 6");
  }
  
  

  // switch (fase)
  // {
  // case 1:
  //   if((he_bin[0] && he_bin[2] == 1) && he_bin[1] == 0){
  //     fase_1();
  //   }
  // break;

  // case 2:
  //   if((he_bin[0] && he_bin[1] == 0) && he_bin[2] == 1){
  //     fase_2();
  //   }  
  // break;

  // case 3:
  //   if((he_bin[1] && he_bin[2] == 1) && he_bin[0] == 0){
  //     fase_3();
  //   }
  // break;

  // case 4:
  //   if((he_bin[0] && he_bin[2] == 0) && he_bin[1] == 1){
  //     fase_4();
  //   }
  // break;

  // case 5:
  //   if((he_bin[0] && he_bin[1] == 0) && he_bin[2] == 0){
  //     fase_5();
  //   }
  // break;

  // case 6:
  //   if((he_bin[1] && he_bin[2] == 0) && he_bin[0] == 1){
  //     fase_6();
  //   }
  // break;
  
  // }

  // for(int i = 0; i < 3; i++){
  //   Serial.print(he_bin[i]);
  //   Serial.print(", ");
  // }

  // for(int i = 0; i < 3; i++){
  //   Serial.print(he_V[i]);
  //   Serial.print(", ");
  // }

  // if(pot_val >= 100000){
  //   pot_val = pot_val * 10;
  //   delayMicroseconds(pot_val);
  //   Serial.print(pot_val);
  //   Serial.print(", ");
  // }else{
  //   delayMicroseconds(pot_val);
  //   Serial.print(pot_val);
  //   Serial.print(", ");
  // }

  delay(800);
  Serial.println();

}

