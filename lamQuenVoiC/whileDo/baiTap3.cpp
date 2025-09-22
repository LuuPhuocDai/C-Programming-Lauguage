#include "stdio.h"

int main(){
	int i = 0, n = 255;
	
	while(i <= n){
		if(i % 16 == 0){
			printf("\n");
		}
		printf("%x ", i);
		i++;
	}
	
	
}
