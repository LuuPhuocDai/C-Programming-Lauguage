#include "stdio.h"

main(){
	int number1 = 1, number2 = 1, n, i, numberN;
	printf("Enter n: ");
	scanf("%d", &n);
	
	printf("%d %d ", number1, number2); 
	
	for(i = 3; i <= n;i++){
		numberN = number1 + number2;
		printf("%d ", numberN);
		number1 = number2;
		number2 = numberN;
	}
}
