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


 // printf("\n\n Z Matrix:\n");
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
	
		for(k=0; k<YSIZE; ++k){
			x[i][j] = x[i][j] + y[i][k] * z[k][j] ; 
			x[i][j+1] = x[i][j+1] + y[i][k] * z[k][j+1] ; 
			x[i+1][j] = x[i+1][j] + y[i+1][k] * z[k][j] ; 
			x[i+1][j+1] = x[i+1][j+1] + y[i+1][k] * z[k][j+1] ; 
		}
	}
	}

	/** PRINT PRODUCT
	for(k=0; k<XSIZE; ++k){
		for(i=0; i < XSIZE; ++i){
		}
	} **/

  end = clock();

  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  
  printf("Time Spent on MM is:  %lf\n", time_spent);
}
