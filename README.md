# DigisparkBasedKeyboard について

![](https://s2.booth.pm/9e9f8732-63c1-40af-8dce-9f3f849a0641/i/3342532/3e789ed9-e795-4617-9c9d-abfac0a62aef_base_resized.jpg)
[販売ページ](https://nch-mosfet.booth.pm/items/3342532)

## ディレクトリ構造

- [archives](./archives)
  - 過去バージョンのファームウェアを保存しています
- [bootloader](./bootloader)
  - 使用しているブートローダのデータです
- [latest](./latest)
  - 最新版ファームウェアはこちら
- [multiBytes](./multiBytes)
  - マルチバイト文字（ひらがな、カタカナ、漢字等）対応バージョンです。[README.md](./multiBytes/README.md)を良くお読みの上でご使用下さい
- [ordered](./ordered)
  - 依頼を頂いたものに関するコードはこちら

## ハードウェア仕様

実装されている2つのスイッチ、「SW1」と「SW2」はそれぞれプルアップ抵抗を介して「PB0」と「PB2」に接続されています  
このキーボードはコントローラ部分にDigisparkマイコンを使用しているため「Digispark（表示名：DigiKey）」として認識されます  
PCに接続する際は金色の端子が4本並んでいるところをUSB-A端子に挿入します  

## ソフトウェア仕様

`digitalRead();` 関数を用いて各スイッチの状態を取得し、一つ前のデータと比較して「押された瞬間」にそのスイッチに割り当てられている文字列を`DigiKeyboard.print();` 関数で出力します  
PC側に`Google 日本語入力` を導入することでマルチバイト文字まで拡張することも可能です  
