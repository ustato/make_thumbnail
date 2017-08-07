/* 画像処理に用いるデータ構造 */
/* 2次元以上の配列は、x,y,z -> [z][y][x] に並べること */
/*   配列データの部分的な共用や x 方向優先処理に対して有効 */

typedef struct {  /* 画像データに関するデータ構造 */
  /* 画像配列は [色指定][Y座標][X座標] の順に整列 */
  Uchar source[COLORNUM][MAXHEIGHT][MAXWIDTH];  /* 元画像が入る配列 */
  Uchar results[COLORNUM][MAXHEIGHT][MAXWIDTH]; /* 処理結果が入る配列 */
  Uchar cwork[COLORNUM][MAXHEIGHT][MAXWIDTH];   /* 中間処理で使う配列 */
  double work[COLORNUM][MAXHEIGHT][MAXWIDTH];   /* 中間処理で使う配列 */
  int width;           /* 画像の幅 */
  int height;          /* 画像の高さ */
  unsigned int color_depth;     /* 色の深さ */
  unsigned int used_color;      /* 画像の色数 */
} imgdata;
