# make_thumbnail
オリジナルのエッジ強調プログラムをC言語で実装した．

#### 実行方法
`in.bmp`を入力画像，`out.bmp`を出力画像として以下を実行する．
現状，bmpfile.oを作らなければならない状態だが，提供する予定は未定．

```shell
gcc make_thumbnail.c bmpfile.o -o make_thumbnail.out
./make_thumbnail.out
```
