#include "stdio.h"
// tinh s = (n + 2)! + n!;

int giaoThua(int n){
	int i, s = 1;
    for(i = 2; i <= n; i++){
	   s = s * i;
    }
return s;
}

int main(){
	int i, s, n; 
	printf("enter n: ");
	scanf("%d", &n);
	
	s = giaoThua(n - 2) + giaoThua(n);
	printf("S = %d", s);
}
