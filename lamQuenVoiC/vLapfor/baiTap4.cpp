#include <stdio.h>

int main(){
	int a, b, ucln, i, tg;
	
	printf("Nhap vao a va b: ");
	scanf("%d%d", &a, &b);
	
	if(a > b){
		tg = a;
		a = b;
		b = tg;
	}
	
	for(i = a; i >= 1; i--){
		if(a % i == 0 && b % i == 0){
			ucln = i;
			break;
		}
	}
	printf("Uoc chung lon nhat cua %d va %d la %d ", a, b, ucln);
	printf("\nBoi chung nho nhat cua %d va %d la %d", a, b, a * b / ucln);
	
}

