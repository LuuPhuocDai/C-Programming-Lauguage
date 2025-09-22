#include "stdio.h"

main(){
	int a = 8, i, j;
	
	for(i = 1; i <= a; i++){
		for(j = 1; j <= a; j++){
			if(i % 2 == j % 2){
				printf(" %c",179);
			}
			else {
				printf("#%c",179);
			}
		}
		printf("\n");
	}
}
