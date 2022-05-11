/*
 * このファームウェアはマルチバイト対応版です
 * 最新版はこちらのリンクからどうぞ↓
 * https://github.com/Nch-MOSFET/DigisparkBasedKeyboard/edit/main/latest/firm/firm.ino
 * 変更があり次第公開していきますが、動作に問題がない場合書き換える必要はありません。
 * また、このコードをもとにご自身で機能拡張をしていただいても構いません。ご自由にご利用ください
 * その際、変更したコードを公開しても良いという場合、本コードを公開しているリポジトリ(https://github.com/Nch-MOSFET/DigisparkBasedKeyboard)
 * にて公開させていただきたいのでご連絡をいただければ幸いです。TwitterのDM(@Nch_MOSFET)またはGitHubのプルリクエストという形でお願いします
 * コードの訂正・最適化等はプルリクエストにてお願いします。こちらで検証の上問題がなければ採用いたします
 */

// この下にある波括弧の中に配列化した文字列を追記して使用してください
// 下のリンク先のページで文字列から配列を作成できます 
// https://apps.cubes.life/apps/ZwklXPjl01
uint16_t Text_1[] = {};
uint16_t Text_2[] = {};

// 自動で改行させたい場合は下の行をコメント解除してください
//#define ENDENTER_TRUE

// 「U~」と入力される場合は下の行をコメント解除してください
//#define USKEYBOARD

//----------------ここから下は変更不要----------------:

#include <DigiKeyboard.h>

#define Text_1_Bytes 2
#define Text_2_Bytes 2

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

  if ((pinStat & 0b10101010) == 0b10000000){
    for (uint8_t i = 0; i < (sizeof(Text_1) / Text_1_Bytes); i++) {
#ifdef USKEYBOARD
      DigiKeyboard.print("U:");
#else
      DigiKeyboard.print("U+");
#endif
      DigiKeyboard.print(Text_1[i], HEX);
      DigiKeyboard.println("  ");
    }
#ifdef ENDENTER_TRUE
    DigiKeyboard.println();
#endif
  }
  
  if ((pinStat & 0b01010101) == 0b01000000){
    for (uint8_t i = 0; i < (sizeof(Text_2) / Text_2_Bytes); i++) {
#ifdef USKEYBOARD
      DigiKeyboard.print("U:");
#else
      DigiKeyboard.print("U+");
#endif
      DigiKeyboard.print(Text_2[i], HEX);
      DigiKeyboard.println("  ");
    }
#ifdef ENDENTER_TRUE
    DigiKeyboard.println();
#endif
  }

  DigiKeyboard.sendKeyStroke(0);

  DigiKeyboard.delay(10);
}
