#include "stdio.h"
main(){
	int n, s, i;
	
	for(i = 0; i <= n; i++){
		printf("nhap n: ");
	    scanf("%d", &n);
	    
	    if( n <= 0){
	    	continue;
		}
		else{
			for(i = 1; i < n; i++){
				if(n % i == 0){
					s += i;
				}
			}
		}
	}
	if(s == n){
		printf("%d la so hoan hao",n);
	}
	else{
	    printf("%d kh phai la so hoan hao",n);
	}
}
