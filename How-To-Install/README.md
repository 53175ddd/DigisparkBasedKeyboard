# DigiKeyboardのファームウェア変更方法

<h3><div align="right">最終更新：2022/07/20</div></h3>

このドキュメントではBoothで販売中の自作キーボード、「DigiKeyboard」（DigisparkBasedKeyboard）のファームウェアを変更する方法を説明しています。長いので以後本キーボードとします  
不明点・誤字・質問等ございましたらDMにてお寄せ下さい。こちらからどうぞ→[DMリンク](https://www.twitter.com/messages/compose?recipient_id=1358261719701721088)

> **Note**｜**注意**  
> **Windows 10の使用を前提としています。その他の環境（Mac, Linux等）に関しては未検証であることをご了承ください**
> **Windows 11に関しては、ほとんど同じ操作で問題ありませんが、一部異なる場合があります。必要に応じて読み替えてお進みいただけると幸いです**  

## 目次

既に終わっている箇所は読み飛ばしてください

- [Arduino IDE（開発環境）の準備](#arduino-ide開発環境の準備)
- [ボードマネージャの追加](#ボードマネージャの追加)
- [ドライバのインストール](#ドライバのインストール)
- [ファームウェアの作成・書き込み](#ファームウェアの作成書き込み)

## Arduino IDE（開発環境）の準備

本キーボードはArduino IDEでファームウェアの更新を行うことができます。言い換えれば、ファームウェアの更新にArduino IDEが必要なためそれをインストールする必要があります

[こちらのリンク](https://www.arduino.cc/en/software)を開き、「Downloads」の項目の右側の濃い緑色の部分にある「DOWNLOAD OPTIONS」の中からそれぞれの環境に合うものを選択します。ここでは「Windows ZIP file」を選択しています

<div align="center"><img src="./img/01.png" width="75%" border=4></div>

すると以下のページに飛びます。「JUST DOWNLOAD」をクリックするとZIPファイルがダウンロードされます

<div align="center"><img src="./img/02.png" width="75%" border=4></div>

Explorerからダウンロードフォルダを開くと、｛arduino-1.8.19-windows.zip｝のようなものがダウンロードされているはずですのでこれを展開します。おすすめは分かりやすいフォルダに展開することです。今回はデスクトップに展開します

<div align="center"><img src="./img/03.png" width="75%" border=4></div>

<div align="center"><img src="./img/04.png" width="75%" border=4></div>

展開先を`C:\Users\User\Desktop\Arduino`にするとデスクトップのArduinoというフォルダに展開されるようになります。`User`の部分はお使いのPCで使用しているユーザーネームですので各自読み替えてお進みください

<div align="center"><img src="./img/05.png" width="75%" border=4></div>

開くとこのようになっていると思います。このままだとファイル階層が無駄に深くなってしまっているのですべて選択して切り取り（ctrl + X）し、一つ上のフォルダにペースト（ctrl + V）するなどして移動させます

<div align="center"><img src="./img/06.png" width="75%" border=4></div>

あるいはこのようにすべて選択してドラッグ＆ドラッグでも可能です

<div align="center"><img src="./img/07.png" width="75%" border=4></div>

移動後はこうなっていると思います。選択され青くハイライトされているフォルダは空になっているはずです。不要なので削除してしまって構いません（むしろ削除することをおすすめします）

Arduino IDEの導入はこれで終わりです  
インストール形式ではないため不要になった場合はフォルダごと削除するだけで完了します。また、PCを買い替えた場合でもこのフォルダをコピーするだけで問題ありませんが、後述するドライバはインストール形式のため都度インストールする必要があります

## ボードマネージャの追加

続いてボードマネージャを追加します

<div align="center"><img src="./img/08.png" width="75%" border=4></div>

`arduino.exe`を起動してください。`.exe`（拡張子）が表示されていない場合はエクスプローラ上部のタブの「表示」を開き、赤線を引いた項目にチェックを入れてください

<div align="center"><img src="./img/09.png" width="75%" border=4></div>

IDEを起動すると、このような画面が出てきます

<div align="center"><img src="./img/10.png" width="75%" border=4></div>

[ファイル]タブから環境設定を開き、

<div align="center"><img src="./img/11.png" width="75%" border=4></div>

「追加のボードマネージャのURL」の項目（赤線部分）に以下のリンクをコピペしてください

```
http://digistump.com/package_digistump_index.json
```

<div align="center"><img src="./img/12.png" width="75%" border=4></div>

[OK]を押して閉じます

<div align="center"><img src="./img/13.png" width="75%" border=4></div>

[ツール]->[ボード]->[ボードマネージャ]と進んでボードマネージャを開き、

<div align="center"><img src="./img/14.png" width="75%" border=4></div>

出てきたウィンドウの検索欄に「Digispark」と入力し、出てきたものをインストールします

<div align="center"><img src="./img/15.png" width="75%" border=4></div>

[INSTALLED]と出ればインストール完了です

<div align="center"><img src="./img/16.png" width="75%" border=4></div>

[ツール]->[ボード]->[Digistump AVR Boards]->[Digispark (Default - 16.5mhz)]を選択できればボードマネージャのインストールは終わりです。IDEは終了して構いません

## ドライバのインストール

[https://github.com/digistump/DigistumpArduino/raw/master/tools/micronucleus-2.0a4-win.zip](https://github.com/digistump/DigistumpArduino/raw/master/tools/micronucleus-2.0a4-win.zip)からzipファイルをダウンロードし、同様の手順で展開し、ファイル場所を移動させます  
展開先は[/Desktop/Arduino/Driver]にしています

<div align="center"><img src="./img/17.png" width="75%" border=4></div>

<div align="center"><img src="./img/18.png" width="75%" border=4></div>

<div align="center"><img src="./img/19.png" width="75%" border=4></div>

次に、[DPinst64.exe]を起動します。32bit環境の場合はその上の[DPinst.exe]を起動してください

<div align="center"><img src="./img/20.png" width="75%" border=4></div>

インストールウィザードが立ち上がります。画面の指示に従って進めてください

<div align="center"><img src="./img/21.png" width="75%" border=4></div>

基本的に[次へ(N)]->[完了]で終わると思います

問題なく終了したらウィザードが終了します。これで終わりです

## ファームウェアの作成・書き込み

Arduino IDEを再度起動し、再び[ファイル]タブから環境設定を開いて以下の赤線で示したところを変更します。これはあくまでも任意ですが、この通りしておくことをお勧めします

<div align="center"><img src="./img/22.png" width="75%" border=4></div>

続いて、[Firmware.ino](./../../Firmware/Firmware.ino)の中身をすべてコピペします。お好みの名前で保存しておきましょう
また、赤線で示した部分、21行目がオレンジ色になっていることを確認してください

<div align="center"><img src="./img/23.png" width="75%" border=4></div>

12行目のコメントの指示通りに`char Text_1[] = "Text_1";`と`char Text_2[] = "Text_2";`を変更します。文字は任意です

例：

```cpp
char Text_1[] = "Hello Arduino";
char Text_2[] = "Hello Digispark";
```

最後に改行させたい（＝Enterキーを打たせたい）場合は17行目をコメント解除してください。`//`を消すことで解除できます

ここまででファームウェアの作成は完了です。赤矢印で示したボタンをクリックするとコンパイルが始まります

<div align="center"><img src="./img/24.png" width="75%" border=4></div>

以下の通りの表示が出てきたら、本キーボード上に[SW1]と書かれているスイッチを押しながらUSBポートに挿入してください。挿したらスイッチを話しても大丈夫です

<div align="center"><img src="./img/25.JPG" width="75%" border=4></div>

ボードへの書き込みが完了したら、いったん抜いて挿しなおし、メモ帳などで動作テストを行ってください。問題なく書き込めていれば[SW1]を押すと[Text_1]に設定したテキストが、[SW2]を押すと[Text_2]に設定したテキストがキーボード入力されます

<div align="center"><img src="./img/26.png" width="75%" border=4></div>

これですべての操作が終了しました。お疲れさまでした  
登録する文字列を変えたい場合は[ファームウェアの作成・書き込み](#ファームウェアの作成書き込み)から行ってください
