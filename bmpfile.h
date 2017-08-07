extern int readBMPfile(char *fname,imgdata *idata);
/* BMP形式で画像をファイルから読み込む関数 */
/* ( 8bpp, 24bpp, 32bpp に対応 )   */
/* 引数：fname --- 出力ファイル名  */
/* 　　　idata --- 画像データ      */
/* 戻値：1以上 --- 失敗            */
/* 　　　0　　 --- 成功            */

extern int writeBMPfile( char *fname,imgdata *idata);
/* BMP形式 (24bpp) で画像をファイルに書き込む関数 */
/* 引数：fname --- 出力ファイル名  */
/*       idata --- 画像データ      */
/* 戻値：1以上 --- 失敗            */
/* 　　　0　　 --- 成功            */

extern void add_dotname(char *fname, char *dotname);
/* ファイルネームに拡張子を付加する関数 */
/*   引数：fname   ファイル名     */
/*         dotname 付加する拡張子 */
/*   戻値：なし                   */
/*   注意：fname に dotname で指定した拡張子がついている場合は何もしない */
