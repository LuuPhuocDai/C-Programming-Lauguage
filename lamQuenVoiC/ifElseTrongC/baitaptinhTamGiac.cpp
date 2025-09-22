#include "stdio.h"
#include "math.h"

main(){
	float a, b, c, p, s;
	printf("nhap 3 canh tam giac a b c: ");
	scanf("%f%f%f", &a, &b, &c);
	
	p = (a+b+c)/2;
	
	if ( (a+b>c) && (a+c>b) && (b+c>a) ){
		s = sqrt(p*(p-a)*(p-b)*(p-c));
		printf("dien tich la %f.02", s);
		
	}
	else {
		printf("tam giac khong ton tai");
	}
}
