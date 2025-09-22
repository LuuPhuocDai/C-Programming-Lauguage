#include "stdio.h"

main(){
	int i, j, k, c;
	printf("nhap chieu cao: ");
	scanf("%d", &c);
	
	for(i = 0; i < c; i++){
		for(j = 1; j < c - i; j++){
			printf(" ");
		}
		for(k = 1; k <= 2 * i + 1; k++){
			printf("*");
		}
		printf("\n");
	}
}
