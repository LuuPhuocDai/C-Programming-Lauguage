#include "stdio.h"

main(){
	int i, j, k, c;
	printf("nhap c: ");
	scanf("%d", &c);
	
	for(i = 1; i <= c; i++){
		for(j = 1; j <= i; j++){
			printf("* ");
		}
		printf("\n");
    }
}
