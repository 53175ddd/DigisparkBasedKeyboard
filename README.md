# DigisparkBasedKeyboard について

<div align="center"><img src="https://s2.booth.pm/9e9f8732-63c1-40af-8dce-9f3f849a0641/i/3342532/3e789ed9-e795-4617-9c9d-abfac0a62aef_base_resized.jpg" alt="DigiKeyboardの写真" width="40%"></div>

## 販売ページリンク

[Booth](https://nch-mosfet.booth.pm/items/3342532)にて販売しています

## ディレクトリ構造

- [Firmware](./Firmware)
  - 最新版ファームウェアはこちら
- [How-To-Install](./How-To-Install)
  - ファームウェアの更新方法を開発環境をインストールするところから記載しています
- [bootloader](./bootloader)
  - 使用しているブートローダのデータです
- [multiBytes](./multiBytes)
  - マルチバイト文字（ひらがな、カタカナ、漢字等）対応バージョンです。[README.md](./multiBytes/README.md)を良くお読みの上でご使用下さい

## ハードウェア仕様

実装されている2つのスイッチ、「SW1」と「SW2」はそれぞれプルアップ抵抗を介して「PB0」と「PB2」に接続されています  
このキーボードはコントローラ部分にDigisparkマイコンを使用しているため「Digispark（表示名：DigiKey）」として認識されます  
PCに接続する際は金色の端子が4本並んでいるところをUSB-A端子に挿入します  

## ソフトウェア仕様

`digitalRead();` 関数を用いて各スイッチの状態を取得し、一つ前のデータと比較して「押された瞬間」にそのスイッチに割り当てられている文字列を`DigiKeyboard.print();` 関数で出力します  
PC側に`Google 日本語入力` を導入することでマルチバイト文字まで拡張することも可能です  

<div align="right"><a href="https://creativecommons.org/licenses/by-sa/3.0/" target="_blank" rel="noopener noreferrer">CC BY-SA 3.0</a></div>
