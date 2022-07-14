/*
 * このファームウェアはマルチバイト対応版v-1.0です
 * 最新版はこちらのリンクからどうぞ↓
 * https://github.com/Nch-MOSFET/DigisparkBasedKeyboard/blob/main/multiBytes/multiBytes.ino
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

//Pro Microを使用する場合はコメント解除してください。Digisparkを使用する場合はこのままで大丈夫です
//#define Pro_Micro

// 自動で改行させたい場合は下の行をコメント解除してください
//#define EndEnter_True

// 「U~」と入力される場合は下の行をコメント解除してください
//#define US_Keyboard

//----------------ここから下は変更不要----------------:

#ifdef Pro_Micro
 #include <Keyboard.h>
#else
 #include <DigiKeyboard.h>
#endif

#define Text_1_Bytes 2
#define Text_2_Bytes 2

#ifdef Pro_Micro
 #define SW1 2
 #define SW2 3
#else
 #define SW1 0
 #define SW2 2
#endif

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
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
}

void loop() {
  pinStat = (pinStat << 2) + (digitalRead(SW1) << 1) + digitalRead(SW2);

  if ((pinStat & 0b10101010) == 0b10000000){
    KeyOut_SW1();
  }
  
  if ((pinStat & 0b01010101) == 0b01000000){
    KeyOut_SW2();
  }
#ifdef Pro_Micro
  delay(10);
#else
  DigiKeyboard.delay(10);
#endif
}

#ifdef Pro_Micro
#define KEYBOARD_REPORT_ID 2

void sendKeyPush(uint8_t code, bool shift) {
  KeyReport keys;
  keys.keys[0] = 0;
  keys.keys[1] = 0;
  keys.keys[2] = 0;
  keys.keys[3] = 0;
  keys.keys[4] = 0;
  keys.keys[5] = 0;
  keys.modifiers = 0x00;
  if (shift) {
    keys.modifiers = 0x02;
    HID().SendReport(KEYBOARD_REPORT_ID, &keys, sizeof(KeyReport));
  }
  keys.keys[0] = code;
  HID().SendReport(KEYBOARD_REPORT_ID, &keys, sizeof(KeyReport));
  keys.keys[0] = 0;
  HID().SendReport(KEYBOARD_REPORT_ID, &keys, sizeof(KeyReport));
  if (shift) {
    keys.modifiers = 0;
    HID().SendReport(KEYBOARD_REPORT_ID, &keys, sizeof(KeyReport));
  }
}

#define KEY_0 0x27
#define KEY_1 0x1e
#define KEY_2 0x1f
#define KEY_3 0x20
#define KEY_4 0x21
#define KEY_5 0x22
#define KEY_6 0x23
#define KEY_7 0x24
#define KEY_8 0x25
#define KEY_9 0x26

#define KEY_A 0x04
#define KEY_B 0x05
#define KEY_C 0x06
#define KEY_D 0x07
#define KEY_E 0x08
#define KEY_F 0x09
#define KEY_U 0x18
#define KEY_EQUAL 0x2e
#define KEY_SEMICOLON 0x33
#define KEY_SPC 0x2c
#define KEY_ENT 0x28

void sendHex(int16_t in) {
  static const uint8_t codes[] = {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7,
                                  KEY_8, KEY_9, KEY_A, KEY_B, KEY_C, KEY_D, KEY_E, KEY_F};
  static const bool shifts[] = {false, false, false, false, false, false, false, false,
                                false, false,  true,  true,  true,  true,  true, true};
  for (int i = 0; i < 4; i++) {
    byte f = (in >> ((3 - i) * 4)) & 0xf;
    sendKeyPush(codes[f], shifts[f]);
  }
}

void KeyOut_SW1() {
  for(byte i = 0; i < (sizeof(Text_1) / Text_1_Bytes); i++){
    sendKeyPush(KEY_U, true);
    sendKeyPush(KEY_SEMICOLON, true);
    sendHex(Text_1[i]);
    sendKeyPush(KEY_SPC, false);
    sendKeyPush(KEY_SPC, false);
    sendKeyPush(KEY_ENT, false);
  }
#ifdef EndEnter_True
    sendKeyPush(KEY_ENT, false);
#endif
}

void KeyOut_SW2() {
  for(byte i = 0; i < (sizeof(Text_2) / Text_2_Bytes); i++){
    sendKeyPush(KEY_U, true);
    sendKeyPush(KEY_SEMICOLON, true);
    sendHex(Text_2[i]);
    sendKeyPush(KEY_SPC, false);
    sendKeyPush(KEY_SPC, false);
    sendKeyPush(KEY_ENT, false);
    }
#ifdef EndEnter_True
    sendKeyPush(KEY_ENT, false);
#endif
}

#else

void KeyOut_SW1() {
  for (uint8_t i = 0; i < (sizeof(Text_1) / Text_1_Bytes); i++) {
    DigiKeyboard.sendKeyStroke(0);
#ifdef US_Keyboard
    DigiKeyboard.print("U:");
#else
    DigiKeyboard.print("U+");
#endif
    DigiKeyboard.print(Text_1[i], HEX);
    DigiKeyboard.println("  ");
  }
#ifdef EndEnter_True
  DigiKeyboard.println();
#endif
}

void KeyOut_SW2() {
  for (uint8_t i = 0; i < (sizeof(Text_2) / Text_2_Bytes); i++) {
    DigiKeyboard.sendKeyStroke(0);
#ifdef US_Keyboard
    DigiKeyboard.print("U:");
#else
    DigiKeyboard.print("U+");
#endif
    DigiKeyboard.print(Text_2[i], HEX);
    DigiKeyboard.println("  ");
  }
#ifdef EndEnter_True
  DigiKeyboard.println();
#endif
}

#endif
