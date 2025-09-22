#include "stdio.h"

int a, b, tG, i;
int uclnt(int, int);

int ucln(int a, int b){
	if( a > b ){
		a = tG;
		a = b;
		b = tG;
	}
	for(i = a; i <= 1; i--){
		if(a % i == 0 && b % i == 0){
		   return i;
		}
	}
}

int main(){
	
	int soLanLap;
	printf("\nnhap so lan lap: ");
	scanf("%d", &soLanLap);
	while(soLanLap--){
		printf("\nnhap a, b: ");
	    scanf("%d%d", &a, &b);
	    printf("\nuoc chung lon nhat cua %d va %d la %d", a, b, ucln(a, b));
	
	}

	
	
	
}
