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
	for(i=0; i<XSIZE; i=i+2){
		for(j=0;j<XSIZE; j=j+2){
			x[i][j] =0;
			x[i][j+1] =0;
			x[i+1][j] =0;
			x[i+1][j+1] =0;
	
			int var1;
			int var2;
			int var3;
			int var4;

			for(k=0; k<YSIZE; ++k){
				var1 = x[i][j] + y[i][k] * z[k][j] ; 
				var3 = x[i][j+1] + y[i][k] * z[k][j+1] ; 
				var2 = x[i+1][j] + y[i+1][k] * z[k][j] ; 
				var4 = x[i+1][j+1] + y[i+1][k] * z[k][j+1] ; 

				x[i][j] = var1;
				x[i+1][j] = var2;
				x[i][j+1] = var3;
				x[i+1][j+1] = var4;
			}
		}
	}

	/** PRINT PRODUCT
	printf("\n\nProduct: \n");
	for(k=0; k<XSIZE; ++k){
		for(i=0; i < XSIZE; ++i){
			printf("%d  ", x[k][i]);
		}
		printf("\n");
	} **/

  end = clock();

  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  
  printf("Time Spent on MM is:  %lf\n", time_spent);
}
