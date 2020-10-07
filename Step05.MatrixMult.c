#include <stdio.h>
#include <math.h>
#include <time.h>

#define XSIZE 700
#define YSIZE 700

int main(void) {

  int x[XSIZE][YSIZE];
  int y[XSIZE][YSIZE];
  int z[XSIZE][YSIZE];

  int i, j, k;
  
  int r;

  clock_t begin, end;

  double time_spent;


  /* Initialize y matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      y[i][j] = i + j;
    }
  }


  /* Initialize z matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
	z[i][j] = i + j;
    }
  }

  begin = clock();
 

  /* Do matrix multiply */
  /* INSERT CODE HERE. */
	for(i=0; i<XSIZE; i=i+4){
		for(j=0;j<XSIZE; j=j+4){

			int var1 = 0;
			int var2 = 0;
			int var3 = 0;
			int var4 = 0;
			int var5 = 0;
			int var6 = 0;
			int var7 = 0;
			int var8 = 0;
			int var9 = 0;
			int var10 = 0;
			int var11 = 0;
			int var12 = 0;
			int var13 = 0;
			int var14 = 0;
			int var15 = 0;
			int var16 = 0;

			for(k=0; k<YSIZE; ++k){
				var1 = var1 + y[i][k] * z[k][j] ; 
				var3 = var3 + y[i][k] * z[k][j+1] ; 
				var2 = var2 + y[i+1][k] * z[k][j] ; 
				var4 = var4 + y[i+1][k] * z[k][j+1] ;
				
				
				var5 = var5 + y[i][k] * z[k][j+2] ; 
				var6 = var6 + y[i][k] * z[k][j+3] ; 
				var7 = var7 + y[i+1][k] * z[k][j+2] ; 
				var8 = var8 + y[i+1][k] * z[k][j+3] ; 
				 
				var9 = var9 + y[i+2][k] * z[k][j] ; 
				var10 = var10 + y[i+3][k] * z[k][j] ; 
				var11 = var11 + y[i+2][k] * z[k][j+1] ; 
				var12 = var12 + y[i+3][k] * z[k][j+1] ; 

				var13 = var13 + y[i+2][k] * z[k][j+2] ; 
				var14 = var14 + y[i+3][k] * z[k][j+2] ; 
				var15 = var15 + y[i+2][k] * z[k][j+3] ; 
				var16 = var16 + y[i+3][k] * z[k][j+3] ;
				 
			}
			
			x[i][j] = var1;
			x[i+1][j] = var2;
			x[i][j+1] = var3;
			x[i+1][j+1] = var4;
			x[i][j+2] = var5;
			x[i][j+3] = var6;
			x[i+1][j+2] = var7;
			x[i+1][j+3] = var8;
			x[i+2][j] = var9;
			x[i+3][j] = var10;
			x[i+2][j+1] = var11;
			x[i+3][j+1] = var12;
			x[i+2][j+2] = var13;
			x[i+3][j+2] = var14;
			x[i+2][j+3] = var15;
			x[i+3][j+3] = var16;
		}
	}

	/** PRINTING 
	printf("\n\nProduct: \n");
	for(k=0; k<XSIZE; ++k){
		for(i=0; i < XSIZE; ++i){
			printf("%d  ", x[k][i]);
		}
		printf("\n");
	} 
	**/

  end = clock();

  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  
  printf("Time Spent on MM is:  %lf\n", time_spent);
}
