#include "stdio.h"
int soTruoc = 1, soSau = 1, soN, n, i;
int fibonacci(int n){
	
	printf("%d %d ", soTruoc, soSau);
	for(i = 3; i <= n; i++){
		soN = soTruoc + soSau;
		printf("%d ", soN );
		soTruoc = soSau;
		soSau = soN;
	}
}
int main(){
	printf("nhap n: ");
	scanf("%d", &n);
	fibonacci(n);
}
