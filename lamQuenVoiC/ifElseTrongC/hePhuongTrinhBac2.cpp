#include "stdio.h"
#include "math.h"

main (){
	float a, b, c, delta, x1, x2;
	printf("nhap  a b c:  ");
	scanf("%f%f%f", &a, &b, &c);
	
	if ( a == 0 && b == 0){
		if ( c == 0){
			printf("hpt vsn");
		}
		else {
			printf("hpt vn");
		}
		
	}
	else if (a == 0 && b != 0){
		printf("ngiem pt la: %.2f", -c/b);
		
	}
	else {
		delta = b*b - 4 * a * c;
		if (delta > 0){
			x1 = (-b + sqrt(delta))/(2 * a); 
			x2 = (-b - sqrt(delta))/(2 * a);
			
			printf("x1 = %.2f ", x1);
			printf("\nx2 = %.2f ", x2); 

		}
		else if (delta == 0){
			printf("x1 = x2 = %.2f",-b/(2*a));
		}
		else {
		    printf("pt bac 2 vn");
		}
	}
	
	
}
