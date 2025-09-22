#include "stdio.h"
#include "stdlib.h"
int main(){
	
	double **pa;
	int i, j, m, n;
	
	printf("nhap so hang(m) va so cot(n): ");
	scanf("%d%d", &m, &n);
	
	pa = (double **)malloc(m * sizeof(double));
	
	for(i = 0; i < m; i++){
		pa[i] = (double *)malloc(n * sizeof(double));
		for(j = 0; j < n; j++){
			printf("a[%d][%d] = ", i, j);
			scanf("%lf", &pa[i][j]);
		}
	}
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%-5.2lf", pa[i][j] );
		}
		printf("\n");
	}
}
