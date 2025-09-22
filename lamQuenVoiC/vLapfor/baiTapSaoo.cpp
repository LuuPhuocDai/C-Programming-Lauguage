#include "stdio.h"

main(){
	int i, j, a, b;
	
	printf("nhap a va b: ");
	scanf("%d%d", &a, &b);
	
	for(i = 1; i <= a; i++){
		for(j = 1; j <= b; j++){
			if(i == 1 || i == a){
				printf("*");
			}
			else {
				if(j == 1 || j == b){
					printf("*");
				}
				else 
				printf(" ");
			}
		}
		printf("\n");
	}
}
