# ibus-mio

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
* cmake + make バージョン
1. cd ../
2. mkdir kisaragi
3. cd kisaragi
4. cmake ../ibus-mio
5. ccmake . #configure相当の何か。必要に応じて。今はいらない
6. make
7. make settingbuild
8. make install

* cmake + ninja バージョン
1. cd ../
2. mkdir kisaragi
3. cd kisaragi
4. cmake ../ibus-mio
5. ninja

### running

ビルド、インストール後に
```
ibus restart
ibus list-engine | grep mio
ibus engine ibus-mio
```

### debug running

ビルド、インストール後に
`vim /usr/share/ibus/component/mio.xml`で編集。
`<exec>/usr/libexec/ibus-engine-mio</exec>`の行を`<exec></exec>`として保存
```
ibus restart
ibus list-engine | grep mio
/usr/libexec/ibus-engine-mio
ibus engine ibus-mio
```

## verify

現コミットにおいて動作確認済み。process-key-event、setup、cmake等
