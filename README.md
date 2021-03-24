# IO-Kit by しろくま＠胡瓜

![](img/Logo.png)

Arduinoのピン操作を快適に。煩わしい記述は必要ありません。

## 概要

Arduinoでピンの入出力時に、このような悩みはありませんか？

- まとめてHIGHにしたいのにいちいちdigitalWriteするのは面倒！
- ピンを用途ごとにオブジェクト配列で管理したい！
- setup()がpinModeの嵐で読みにくい！

そんな悩みを解決するのがIO-Kitです。

## DOWNLOAD

GitHubのリリースからどうぞ。最新バージョンは0.1です。

## 使用方法

1. まずライブラリをリリースから最新版をダウンロードし、解凍します。
2. スケッチフォルダないのlibraries内に解凍したフォルダごと配置します。
   
## 説明

### #include <IO-Kit.h>

このライブラリを使うためには必ず以下のようにヘッダーファイルを読み込む必要があります。全てはここから始まります。

``` cpp
#include <IO-Kit.h>
```

### 出力

#### Output 名前 = `ピン番号`;

出力に設定したい``ピン番号``とそのピンの今後の`呼び名`を記述してください。

``` cpp
#include <IO-Kit.h>

Output LED = 13;

void setup(){}

// 以下省略
```

> **上級編**:オブジェクト配列を使ってこのように定義することもできます。
> ```cpp 
> Output LED[] = {12, 13};
> ```

#### HIGHとLOWの切り替え

digitalWriteと同等のことを行うには、`呼び名 = 値;`で設定することができます。

``` cpp
#include <IO-Kit.h>

Output LED = 13;

void setup(){}

void loop(){
  LED = HIGH;
  delay(500);
  LED = LOW;
  delay(500);
}
```

> **上級編**:一気にこんな感じで設定もできます
> ```cpp 
> LED1 = LED2 = HIGH;
> ```

#### PWM出力

analogWriteと同等のことを行うには`呼び名 = 値(float)`で行うことができます。値は0.0から1.0の間で割合を指定してください。

``` cpp
LED = 0.5;  //50%でPWMが出力されます
```

ただし0.0と1.0が指定された場合はPWM出力は行われません。また、PWMに対応していないピンは0.5を境としてHIGHまたはLOWのいずれかが出力されます。

> **Note**:感のいい人はさっきのHIGHとLOWの切り替えと構文が全く同じであることに気づいたかもしれません。僕たちはPWMかそうじゃないかなんて気にする必要がないのです。そんなものは機械に任せて僕たち人間は創造的なコードを書くことに専念しましょう。

また、標準のanalogWriteと同じように0から255の整数で指定したい場合もあるでしょう。その場合は、

``` cpp
LED <<= 128;  //  analogWrite(`ピン番号`, 128);と同等です
```

と記述することもできます。

> **上級編**:もちろんこういう記述も可能です。
> ```cpp 
> LED1 = LED2 = 0.5;
> LED1 <<= LED2 <<= 130;
> ```
>
> またこの場合の「<<-」は、`呼び名` = `呼び名` << 値ではないことに注意してください。これは<<=演算子がオーバーロードされているためです。

#### 状況の確認

このLEDってHIGHにしたっけ？それともLOWのままだっけ？とプログラムを書いているときになるかもしれません。その場合は`呼び名`をただの変数みたいに扱ってあげてください。

これはデバッグの時にも大変有効です。例えばあなたがモータードライバの状況をパソコンで見たい時に`Serial.println(呼び名);`とすることで表示させることができます。

また、これによりHIGHとLOWという単語を一度も使わずにLチカのプログラムを組むこともできます。

``` cpp
#include <IO-Kit.h>

Output LED = 13;

void setup(){}

void loop(){
  LED = !LED; //裏返す
  delay(500);
}
```

さらに、そのピンがPWM出力をしていた場合も同様の文で確かめることができます。例えば50%で出力をしていた場合、0.5が返ってきます。

``` cpp
LED = 0.5; //50%で出力される
Serial.println(LED); //0.5が返ってくる
```

ただし、あなたがプログラムの途中に突然digitalWriteやanalogWriteに浮気してしまった場合、予想異なる値が返ってくることがあります。これは過去に`LED = HIGH;`などとした時のログを遡って単純に返すという実装になっているためです。三角関係の対岸で起きたことなど知るはずがありません。

> **上級者編**:過去に設定した値と返ってくる値が必ずしも**一致するとは限りません**。これははPWM出力は裏では0から255の**256段階で出力されている**ためです。例えば、
> ```cpp
> LED = 0.5000000001
> ```
> としたとしてもなんの意味も無さないでしょう。
> 
> また、PWMに対応していないピンに過去に誤って`呼び名 <<= 値;`や`呼び名 = 少数`としてしまった場合でも、返ってくるのはそこで設定した値（=HIGHまたはLOWとは限らない）であることに注意してください。
> 
> また、返ってくる値を0.0から1.0ではなく0から255で確認したい場合もあるかもしれません。その場合は
> ```cpp
> 呼び名.raw()
> ```
> としてください。またPWM出力中でなかった場合は0か255が返ってきます。

### 入力

#### Input 名前 = ピン番号;

入力に設定したい`ピン番号`とそのピンの今後の呼び名を記述してください。

``` cpp
#include <IO-Kit.h>

Input SWITCH = 2;

void setup(){}

// 以下省略
```

内部プルアップを有効にしたいときは、

``` cpp
#include <IO-Kit.h>

Input SWITCH(2, PULLUP);

void setup(){}

// 以下省略
```

としてください。デフォルトではプルアップ抵抗は無効ですが、無効であること（=開放されていること）を明示したい場合は以下のように記述することもできます。（最初の例と動作は完全に同一です。）

``` cpp
#include <IO-Kit.h>

Input SWITCH(2, OPEN);

void setup(){}

// 以下省略
```

> **上級編**:オブジェクト配列を使ってこのように定義することもできます。
> ```cpp 
> Input SWTICH[] = {2, 3};
> ```
> こんなのもありです。
> ```cpp
> Input SWITCH[] = {Input(2, OPEN), Input(3,PULLUP)};

#### デジタル入力

単純に`呼び名`だけでただの変数みたいな感じで扱ってあげてください。例えばSWTCHの値を読み取ってaという変数に格納したい場合は、

``` cpp
int a = SWITCH;
```

とするだけで自動的に裏でdigitalReadが走ります。

> **Note**:返り値はboolです。

#### アナログ入力

`呼び名.analog()`としてください。値は0.0から1.0の小数で返ってきます。こんな感じです。

``` cpp
float a = Sensor.analog();
```

ただし、小数ではなく0から1023で値を見たい時もあるかもしれません。その場合は`呼び名.raw()`を使ってください。返り値はintです。

## もっと詳しく

このREADMEを画面が焼きつくほどじっくり見ても、まだ気になるところがあればお気軽に[僕のTwitter](https://twitter.com/robokichi41)にDMを飛ばしてください。