#include "stdio.h"
#include "math.h"

int main(){
	float a, i = 1, s = 1, n;
	printf("enter n, a: ");
	scanf("%f%f", &n, &a);
	
	while(i <= n){
		s = s + pow(a, i)/(i + 1);
		i++;
	}
	printf("kq = %.2f", s);
}
