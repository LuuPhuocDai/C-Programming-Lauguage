#include "stdio.h"

main(){
	int sao;
	printf("nhap so luong sao (sao <= 3): ");
	scanf("%d", &sao);
	
	switch(sao){
		case 1 :
			printf("*");
			break;
		case 2 :
			printf("**");
			break;
		case 3 :
			printf("***");
			break;
		default :
			printf("so sao qua muc quy dinh hoac khong du");
	}
}
