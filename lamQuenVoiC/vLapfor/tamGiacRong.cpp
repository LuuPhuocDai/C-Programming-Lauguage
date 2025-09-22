#include "stdio.h"

main(){
	int i, j, c, k;
	
	printf("nhap c: ");
	scanf("%d", &c);
	
	for(i = 0; i < c; i++){
		for(j = 1; j < c - i; j++){
		    printf(" ");
		}
		for(k = 1; k <= 2 * i + 1; k++){
		    if(i < c - 1){
		    	if(k == 1 || k == 2 * i + 1)
			       printf("*");
			    else
			       printf(" ");   
		    }
			else 
			   printf("*");
			}
			printf("\n");	
		}
	}

