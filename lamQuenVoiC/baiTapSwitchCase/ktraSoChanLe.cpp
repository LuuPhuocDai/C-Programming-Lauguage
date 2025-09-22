#include "stdio.h"

main(){
	int number;
	printf(" Enter Number: ");
	scanf("%d", &number);
	
	switch(number % 2){
		case 0:
			printf(" %d is even number", number);// so chan
			break;
		case 1:
			printf("%d is odd number", number);// so le
		
	}
}
