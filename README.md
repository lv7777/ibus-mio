# ibus-levena

このプロジェクトは[ibus-katari](https://github.com/WhiteHawk-taka/katari)にインスパイアされて作られました。

主にibus-katariのテスト機能の実装とかに使います。

# compile

`gcc levena.c $(pkg-config ibus-1.0 --cflags --libs)`

そのうちでかくなったらMakefile書くかもしれません。

# usage

1. `cp ./levena.xml /usr/share/ibus/component/`

ibusにibus-levenaを認識させる。

2. `ibus restart`

xmlコンポーネント(levena.xml)を読み込ませるためにibusの再起動

3. `ibus list-engine | grep levena`

ibusにibus-levenaが登録されていることを確認。

4. `./a.out`

別のターミナルにてIME(ibus-levena)側の起動。
起動後はibusからの入力待ちとなりターミナルが帰ってきませんが閉じないで下さい。
閉じるとIME(ibus-levena)が終わってしまいます。

5. `ibus engine ibus-levena`

ibus-levenaを現在のIMEとして使用する。
使用後は入力が効かず、キーボードイベントがすべてIMEが起動しているウインドウに出力されるため、**マウスしか使用できない**ため留意してください。
終了したい場合、ibus-levenaが起動しているウインドウを閉じれば
ibusがデフォルトのIMEに自動で切り替わるはずです。

# documents

本imeの目的の一つとしてibus-imeの挙動の説明があり、またibusの挙動関連についてのドキュメントがあまり存在していないため、詳細なドキュメント整備を心がけています。
分かり難い部分がございましたらissueを頂けると幸いです。

# author

lv7777
