#include <DigiKeyboard.h>

//各スイッチが接続されているピンを定義:
#define SW1 0
#define SW2 2

//各スイッチの状態を定義:
#define Pressed  0
#define Released 1

//各スイッチを押したときに入力される文字列の長さを定義:
#define Text1_long 17
#define Text2_long 17

//各スイッチを押したときに入力される文字列を定義, 上限は256文字:
char Text1[Text1_long + 1] = "Replace This Text";
char Text2[Text2_long + 1] = "Replace This Text";

//下位4bitをスイッチの状態保存に割り当て:
uint8_t dataBuffer = 0b00000000;
uint8_t SW_Data    = 0b00001111;

void setup() {
  //接続ピンを入力に設定:
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
}

void loop() {
  //条件に合致する場合キー入力を実行:
  if((SW_Data　| 0b00001000) >> 3 == Released && (SW_Data　| 0b00000010) >> 1 == Pressed) {
    for(uint8_t i = 0; i < Text1_long; i++){
      DigiKeyboard.sendKeyStroke(Text1[i]);
      delay(1);
    }
  }
  if((SW_Data　| 0b00000100) >> 2 == Released && (SW_Data　| 0b00000001) >> 0 == Pressed) {
    for(uint8_t i = 0; i < Text2_long; i++){
      DigiKeyboard.sendKeyStroke(Text2[i]);
      delay(1);
    }
  }

  SW_Data    = (SW_Data & 0b00000011) << 2;
  dataBuffer = digitalRead(SW1) << 1;
  SW_Data    = SW_Data | dataBuffer;
  dataBuffer = digitalRead(SW2);
  SW_Data    = SW_Data | dataBuffer;

  delay(50);
}
