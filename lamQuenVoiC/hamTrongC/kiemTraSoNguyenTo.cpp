#include "stdio.h"
#include "stdbool.h"

void kt(int);
void kt(int n){
	int i;
	bool kt = true;
	for(i = 2; i <= n/2; i++){
		if(n % i == 0){
			kt = false;
			break;
		}
	}
	if(kt)
	printf("%d la so nguyen to", n);
	else 
	printf("%d kh phai la so nguyen to", n);
}

int main(){
	int n;
	printf("enter n: ");
	scanf("%d", &n);
	kt(n);
}
