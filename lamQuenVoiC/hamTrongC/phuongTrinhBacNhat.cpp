#include "stdio.h"
float a, b;
int ptbnhat();
int ptbnhat(){
	if( a == 0 && b == 0)
	printf("he phuong trinh vsn");
	else if( a == 0 && b != 0)
	printf("phuong trinh vo nghiem");
	else 
	printf("phuong trinh co nghiem: %.2f", -b/a);
	
}

int main(){
	int soLanChay;
	printf("nhap so lan: ");
	scanf("%d", &soLanChay);
	
	while(soLanChay--){
		printf("\nnhap a, b: ");
      	scanf("%f%f", &a, &b);
	    ptbnhat();
	    printf("\n");
	}
}
