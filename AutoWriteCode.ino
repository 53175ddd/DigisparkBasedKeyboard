#include <DigiKeyboard.h>

char* Text_1 = "Replace this text";  //When you press SW1, keyboard types this text:
char* Text_2 = "Replace this text";  //When you press SW2, keyboard types this text:

byte Pin0_old_data = 1;
byte Pin2_old_data = 1;
byte Pin0_new_data = 1;
byte Pin2_new_data = 1;

void setup() {
  pinMode(0, INPUT);
  pinMode(2, INPUT);
}

void loop() {
  if (Pin0_old_data == 1 && Pin0_new_data == 0){                  //If pin pressed now and didn't pressed at last step:
    DigiKeyboard.println(Text_1);
  }

  if (Pin2_old_data == 1 && Pin2_new_data == 0){                  //If pin pressed now and didn't pressed at last step:
    DigiKeyboard.println(Text_2);
  }

  Pin0_old_data = Pin0_new_data;                                  //Move the number from old_data to new_data:
  Pin2_old_data = Pin2_new_data;

  Pin0_new_data = digitalRead(0);                                 //Read I/O pin and set the new_data:
  Pin2_new_data = digitalRead(2);                                 //0 = pressed, 1 = open:

  DigiKeyboard.sendKeyStroke(0);                                  //Send dummy data:
  
  delay(50);
}
