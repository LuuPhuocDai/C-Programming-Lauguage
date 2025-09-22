#include "stdio.h"
#include "math.h"
// tinh can bac lan n;
int main(){
	float n, a, i = 1, s = 0;
	printf("enter n, a: ");
	scanf("%f%f", &n, &a);
	
	while(i <= n){
		s = sqrt(a + s);
		i++;
		
	}
	printf("tong = %.3f", s);
}
