# 2SW-2LED バージョン

DigiKeyboardに使用するスイッチを変更し、表面実装のLEDを追加したバージョンです。  
Boothにて依頼を受け作成しました

# 使用方法

[Driver.ino](./Driver/Driver.ino)をダウンロードしてファームウェアファイルと同じディレクトリに保存し、Arduino IDEでファームウェアを開きます  

`void loop() {}`の中の任意の場所に実行したい関数を追記して使用してください。使用可能な関数と使い方は以下をご覧ください

# 追加される関数

赤色LEDを指定したい場合は`RED_LED`を、緑色LEDを指定したい場合は`GREEN_LED`を`var`の部分に入力してください

- `LED_Test(var)`
  - `var`で指定された回数LEDのトグルとフラッシュを行います。0 ~ 65535の範囲で指定してください
- `LED_Toggle(var)`
  - `var`で指定されたLEDをトグルします。点灯していた場合は消灯し、消灯していた場合は点灯します
- `LED_ON(var)`
  - `var`で指定されたLEDを点灯させます
- `LED_OFF(var)`
  - `var`で指定されたLEDを消灯させます

# サンプルコード

約1秒ごとに緑色LEDをトグルします

```cpp
#include <DigiKeyboard.h>

uint8_t counter;

/*
 * 前部分省略
 * このコードはv-1.7に準拠しています
 */

void loop() {
  if(counter >= 40) {
    LED_Toggle(GREEN_LED);
    counter = 0;
  }

  mainRoutine();
  DigiKeyboard.delay(25);
}
/*
 * 以後省略
 */
```

# 基板プレビュー

![image](https://user-images.githubusercontent.com/91242561/180484413-6d5b2b4a-6502-4aed-8835-03e84b62e1b4.png)

