#include "stdio.h"

int thamTri(int, int);
int thamBien(int, int);

int thamTri(int x, int y){
	x += 1;
	y += 1;
}
int thamBien(int *x, int *y){
	*x += 1;
	*y += 1;
}

int main(){
	int x =5 , y =5;
	thamTri(x, y);
	printf("x = %d, y = %d", x, y);
	thamBien(&x, &y);
	printf("\nx = %d, y = %d", x, y);
}
