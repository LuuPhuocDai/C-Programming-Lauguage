//in ra bang cuu
#include <stdio.h>
#include <math.h>

main(){
	int i, j;
	
	for(i = 2; i < 10; i++){
		for(j = 2; j < 10; j++){
			printf("%c %d x %d = %2d", 179, j, i, i * j);
		}
		printf("%c\n", 179);
	}
} 
