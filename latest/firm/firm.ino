#include <DigiKeyboard.h>

//押されている状態、放されている状態での入力ピンの状態を定義:
#define Pressed  0
#define Released 1

//各スイッチが接続されているピンをスイッチ名として定義:
#define SW1 0
#define SW2 2

//ピンの状態を保存する変数を定義:
uint8_t stat = 0b11111111;

void setup() {
  //各スイッチに接続されているピンを入力に設定:
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
}

void loop() {
  //データをシフトしつつ代入して更新:
  stat = stat << 1;
  stat = stat + digitalRead(SW1);
  stat = stat << 1;
  stat = stat + digitalRead(SW2);

  //スイッチが押された瞬間の処理:
  if(stat & 0b00001010 == 0b00001000){
    DigiKeyboard.print("Text_1");
  }
  if(stat & 0b00000101 == 0b00000100){
    DigiKeyboard.print("Text_2");
  }

  delay(50);
}
