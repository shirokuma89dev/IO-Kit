# IO-Kit

![](img/Logo.png)

Arduinoのピン操作を快適に。煩わしい記述は必要ありません。

## 概要

Arduinoでピンの入出力時に、このような悩みはありませんか？

- まとめてHIGHにしたいのにいちいちdigitalWriteするのは面倒！
- ピンを用途ごとにオブジェクト配列で管理したい！
- setup()がpinModeの嵐で読みにくい！

そんな悩みを解決するのがIO-Kitです。

例えばIO-Kit.hを行の最初にincludeするだけで、

``` cpp
#define LED 13

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, HIGH);
  delay(500);
}
```

あの彼女の顔より見たLチカプログラムも…

``` cpp
#include <IO-Kit.h>

digitalOut LED = 13;

void setup() {}

void loop() {
  LED = !LED;
  delay(500);
}

```

この通り！※1
## お知らせ

現在開発中です。リリース次第、またTwitterでお知らせしますので[しろくま＠胡瓜のTwitter](https://twitter.com/robokichi41)をぜひ確認してね！

※1 現在段階にあり、今後仕様が変更となる可能性があります。