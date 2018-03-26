# ibus-mio

**オタクはすぐに恋した2次元の女の子の名前を使うな**

スペシャルサンクス：
* しゅぷれ〜むキャンディ 佐久間弓音さん
* オトメ＊ドメイン       大垣ひなたちゃん
* オトメ＊ドメイン       飛鳥湊くん

## about

設定画面、lint系、ci、modan buildtool、設定画面、imeと連動したpwdmgr、apiを叩いてcandidate window、mecabで要素解析、mozcの要素解析を取り入れる。

# author

lv7777

# modan buildtools
cmake+ninja

apt-get install ninja-build cmake cmake-curses-gui

cmake...makefileを作成する
ccmake...configureみたいなやつ。依存性とかを設定する。
ninja...実際のbuild担当

### cmakeをビルドする時はプロジェクトの外側にconfigure相当のファイルを作らなければいけない
プロジェクト内部に作るのは非推奨となっている(いくら変更管理してるとはいえプロジェクトの内部汚くなる可能性あるし)
cd ../
mkdir kisaragi
cd kisaragi
cmake ../ibus-mio
ccmake . #configure相当の何か。必要に応じて。今はいらない
make