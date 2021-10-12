#include <DigiKeyboard.h>

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
    DigiKeyboard.println(F("Text_1"));                            //Set the text. Replace "Text_1" to the other word what you want to use:
  }

  if (Pin2_old_data == 1 && Pin2_new_data == 0){                  //If pin pressed now and didn't pressed at last step:
    DigiKeyboard.println(F("Text_2"));                            //Set the text. Replace "Text_2" to the other word what you want to use:
  }

  Pin0_old_data = Pin0_new_data;                                  //Move the number from old_data to new_data:
  Pin2_old_data = Pin2_new_data;

  Pin0_new_data = digitalRead(0);                                 //Read I/O pin and set the new_data:
  Pin2_new_data = digitalRead(2);                                 //0 = pressed, 1 = open:

  DigiKeyboard.sendKeyStroke(0);                                  //Send dummy data:
  
  delay(50);
}
