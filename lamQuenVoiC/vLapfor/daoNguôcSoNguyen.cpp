#include "stdio.h"
main(){
	int n,i;
	printf("nhap n: ");
	scanf("%d", &n);
	
	for(; n > 0; n /= 10){
		printf("%d", n % 10);
	}
}
