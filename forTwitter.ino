#include <DigiKeyboard.h>

byte Pin0_old_data = 1;
byte Pin2_old_data = 1;
byte Pin0_new_data = 1;
byte Pin2_new_data = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(0, INPUT);
  pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Pin0_old_data = Pin0_new_data;
  Pin2_old_data = Pin2_new_data;

  Pin0_new_data = digitalRead(0);
  Pin2_new_data = digitalRead(2);

  if (Pin0_old_data == 1 && Pin0_new_data == 0){
    COY();
  }

  if (Pin2_old_data == 1 && Pin2_new_data == 0){
    STT();
  }
  DigiKeyboard.sendKeyStroke(0);
  delay(50);
}

void COY(){
  DigiKeyboard.sendKeyStroke(KEY_C);
  DigiKeyboard.sendKeyStroke(KEY_Y);
  DigiKeyboard.sendKeyStroke(KEY_O);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(50);
  DigiKeyboard.print("wwww");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_O);
  DigiKeyboard.sendKeyStroke(KEY_M);
  DigiKeyboard.sendKeyStroke(KEY_A);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(50);
  DigiKeyboard.print("wwwwwwwww");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_Y);
  DigiKeyboard.sendKeyStroke(KEY_U);
  DigiKeyboard.sendKeyStroke(KEY_U);
  DigiKeyboard.sendKeyStroke(KEY_M);
  DigiKeyboard.sendKeyStroke(KEY_E);
  DigiKeyboard.sendKeyStroke(KEY_I);
  DigiKeyboard.sendKeyStroke(KEY_J);
  DigiKeyboard.sendKeyStroke(KEY_I);
  DigiKeyboard.sendKeyStroke(KEY_N);
  DigiKeyboard.sendKeyStroke(KEY_SPACE);
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_J);
  DigiKeyboard.sendKeyStroke(KEY_A);
  DigiKeyboard.sendKeyStroke(KEY_N);
  DigiKeyboard.sendKeyStroke(KEY_N);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(50);
  DigiKeyboard.print("wwwwwwwwwwww");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void STT(){
  DigiKeyboard.sendKeyStroke(KEY_S);
  DigiKeyboard.sendKeyStroke(KEY_O);
  DigiKeyboard.sendKeyStroke(KEY_R);
  DigiKeyboard.sendKeyStroke(KEY_E);
  DigiKeyboard.sendKeyStroke(KEY_N);
  DigiKeyboard.sendKeyStroke(KEY_A);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(50);
  DigiKeyboard.print("wwwwwwwwwwww");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_T);
  DigiKeyboard.sendKeyStroke(KEY_U);
  DigiKeyboard.sendKeyStroke(KEY_U);
  DigiKeyboard.sendKeyStroke(KEY_T);
  DigiKeyboard.sendKeyStroke(KEY_I);
  DigiKeyboard.sendKeyStroke(KEY_SPACE);
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_T);
  DigiKeyboard.sendKeyStroke(KEY_O);
  DigiKeyboard.sendKeyStroke(KEY_M);
  DigiKeyboard.sendKeyStroke(KEY_A);
  DigiKeyboard.sendKeyStroke(KEY_R);
  DigiKeyboard.sendKeyStroke(KEY_A);
  DigiKeyboard.sendKeyStroke(KEY_N);
  DigiKeyboard.sendKeyStroke(KEY_N);
  DigiKeyboard.sendKeyStroke(KEY_SPACE);
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(50);
  DigiKeyboard.print("wwwwwwwwwwwwwwwwwww");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}
