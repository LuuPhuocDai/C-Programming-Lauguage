#include "stdio.h"

int binhPhuong(int, int);

int main(){
	int n, i, t = 0;
	printf("enter n: " );
	scanf("%d", &n);
	
	for(i = 1; i <= n; i++){
		t = t + binhPhuong(i, i);
		printf("t = %d", t);
	}

}


int binhPhuong(int a, int b){
	int i, s = 1;
	for(i = 1; i <= b; i++ ){
		s = s*a;// thay i vi khi goi ham nay a = i ;
	}
	return s;
}
