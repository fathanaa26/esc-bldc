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


byte fase;


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

void fase_1(){
  if((he_bin[0] && he_bin[2] == 1) && (he_bin[1] == 0)){ // U=1, V=0 , W=1
    digitalWrite(pwm_p0, HIGH); // coil_u HIGH
    digitalWrite(pwm_p1, LOW); // coil_v LOW
  }
}

void fase_2(){
  if((he_bin[0] && he_bin[1] == 0) && (he_bin[2] == 1)){ // U=0, V=0 , W=1
    digitalWrite(pwm_p2, HIGH); // coil_w HIGH
    digitalWrite(pwm_p1, LOW); // coil_v LOW
  }
}

void fase_3(){
  if((he_bin[0] == 1) && (he_bin[1] == 1  && he_bin[2] == 1)){ // U=0, V=1 , W=1
    digitalWrite(pwm_p0, LOW); // coil_v LOW
    digitalWrite(pwm_p2, HIGH); // coil_w HIGH
  }
}

void fase_4(){
  if((he_bin[0] && he_bin[2] == 0) && (he_bin[1] == 1)){ // U=0, V=1, W=0
    digitalWrite(pwm_p1, HIGH); // coil_v HIGH
    digitalWrite(pwm_p0, LOW);// coil_u LOW
  } 
}

void fase_5(){
  if((he_bin[0] && he_bin[2] == 0) && (he_bin[] == 1)){ // U=0, V=1, W=0
    digitalWrite(pwm_p1, HIGH); // coil_v HIGH
    digitalWrite(pwm_p0, HIGH);// coil_u LOW
  } 
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

  for(int i = 0; i < 3; i++){
    Serial.print(he_bin[i]);
    Serial.print(", ");
  }

  for(int i = 0; i < 3; i++){
    Serial.print(he_V[i]);
    Serial.print(", ");
  }

  if(pot_val >= 100000){
    pot_val = pot_val * 10;
    delayMicroseconds(pot_val);
    Serial.print(pot_val);
    Serial.print(", ");
  }else{
    delayMicroseconds(pot_val);
    Serial.print(pot_val);
    Serial.print(", ");
  }
 
  Serial.println();

}

