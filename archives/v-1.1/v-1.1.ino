#include <DigiKeyboard.h>

#define SW1 0
#define SW2 2

#define PULLUP

#ifdef PULLUP
 #define Pressed  0
 #define Released 1
#else
 #define Pressed  1
 #define Released 0
#endif

uint8_t pinStat = 0b11111111 * Released;

void setup() {
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
}

void loop() {
  pinStat = (pinStat << 2) + (digitalRead(SW1) << 1) + digitalRead(SW2);
  
  if ((pinStat & 0b00001010) == 0b00001000){
    DigiKeyboard.println("Text_1");
  }

  if ((pinStat & 0b00000101) == 0b00000100){
    DigiKeyboard.println("Text_2");
  }

  DigiKeyboard.sendKeyStroke(0);

  delay(50);
}
