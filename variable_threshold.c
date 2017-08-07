#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "def.h"
#include "var.h"
#include "bmpfile.h"

#define Zm 255

void quadratic_LUT(double LUT[Zm+1]){
  int i;

  for(i=0; i<=Zm; i++){
    LUT[i] = (i*i)/Zm;
  }
}

void root_convert_LUT(double LUT[Zm+1]){
  int i;

  for(i=0; i<=Zm; i++){
    LUT[i] = sqrt(i*Zm);
  }
}

void sigmoid_convert_LUT(double a, double LUT[Zm+1]){
  int i;
  double x;

  for(i=0; i<=Zm; i++){
    x=(double)i/Zm-0.5;
    x=(double)-7.0*x;
    x=(double)1.0+exp(x);
    LUT[i] = (double)Zm/x;
  }
}

void init_array(int color_distribution[Zm+1]){
  int i;
  
  for(i=0; i<=Zm; i++){
    color_distribution[i]=0;
  }
}

void analysis_distribution(int nm[][Zm+1], int color_distribution[Zm+1]){
  int i,j,cnt;
  int a;
  
  cnt=0;
  for(i=0; i<=Zm; i++){
    cnt+=color_distribution[i];
  }
  for(i=0; i<=Zm; i++){
    printf("distribution=%d\n",color_distribution[i]);
  }
  printf("ave=%d\n",cnt);
}

int main(int argc, char *argv[])
{
  imgdata idata;
  int x, y, i, j;
  int i_tmp, j_tmp;
  int N=7, sum;
  int converted[Zm+1][Zm+1] = {{0}};
  int threshold;
  double sigma;
  char grayscale;
 
  
  // 課題プログラム
  // 　BMPファイルを可変閾値法で二値化するプログラム

  if (argc < 3) printf("使用法：variable_threshold 変換元.bmp 変換先.bmp\n");
  else {
    if (readBMPfile(argv[1], &idata) > 0)
      printf("指定変換元ファイル%sが見つかりません\n",argv[1]);
    else {
    /* 課題１７：可変閾値法で二値化するプログラム */
      for (y = 0; y < idata.height-N; y++){
	for (x = 0; x < idata.width-N; x++){
	  sum = 0;
	  sigma = 0;
	  
	  for (j = 0; j < N; j++){
	    for (i = 0; i < N; i++){
	      sum += idata.source[RED][y+j][x+i];
	    }
	  }
	  threshold = sum/(N*N);
	  
	  for (j = 0; j < N; j++){
	    for (i = 0; i < N; i++){
	      sigma += pow(idata.source[RED][y+j][x+i] - threshold, 2.0);
	    }
	  }
	  sigma /= N*N;

	  printf("sigma=%f\n",sigma);

	  if (sigma >= 1000){
	    for (j = 0; j < N; j++){
	      for (i = 0; i < N; i++){
		if (idata.source[RED][y+j][x+i] < threshold){
		  grayscale = 0;
		}else{
		  grayscale = Zm;
		}

		idata.results[RED][y+j][x+i] = (Uchar)grayscale;
		idata.results[GREEN][y+j][x+i] = (Uchar)grayscale;
		idata.results[BLUE][y+j][x+i] = (Uchar)grayscale;
	      }
	    }
	  }
	}
      }
	
      if (writeBMPfile(argv[2], &idata) > 0)
	printf("変換先ファイル%sに保存できませんでした\n",argv[2]);
    }
  }
}
