#include <DigiKeyboard.h>

uint8_t Pin0_old_data = 1;
uint8_t Pin2_old_data = 1;
uint8_t Pin0_new_data = 1;
uint8_t Pin2_new_data = 1;

void setup() {
  pinMode(0, INPUT);
  pinMode(2, INPUT);
}

void loop() {
  if (Pin0_old_data == 1 && Pin0_new_data == 0){
    DigiKeyboard.println(F("Text_1"));
  }

  if (Pin2_old_data == 1 && Pin2_new_data == 0){
    DigiKeyboard.println(F("Text_2"));
  }

  Pin0_old_data = Pin0_new_data;
  Pin2_old_data = Pin2_new_data;

  Pin0_new_data = digitalRead(0);   
  Pin2_new_data = digitalRead(2); 

  DigiKeyboard.sendKeyStroke(0);

  delay(50);
}
