#include "stdio.h"
#define pi 3.14


// bien toan cuc, int n la sai het cho cac bien;

/*
int n;

int amDuong();
int chanLe();

int amDuong(){
	if(n >= 0)
	printf("%d la so duong", n);
	else 
	printf("%d la so am", n);
}
int chanLe(){
	if(n % 2 == 0)
	printf("%d la so chan", n);
	else 
	printf("%d la so le", n);
}

int main(){
	printf("nhap n: ");
	scanf("%d", &n);
	
	amDuong();
	printf("\n");
	chanLe();
}  */

/*
float  s, r;

int dthcau();
int dthtron();

int dthcau(){
	s = 4*pi*r*r;
	printf("S = %.2f", s); 
}
int dthtron(){
	s = 2*pi*r*r;
	printf("S = %.2f", s);
}

int main(){
	printf("nhap ban kinh r: ");
	scanf("%f", &r);
	dthcau();
	printf("\n");
	dthtron();   */

	

// hoac dung define vd;
#define dthcau(r)(4*pi*r*r)
#define tdt(x, y)(x+y)
int x, y;
float r;
int main(){
	printf("nhap r: ");
	scanf("%f", &r);
	printf("\ns = %.2f", dthcau(r));
	
	printf("\nnhap x, y: ");
	scanf("%d%d", &x, &y);
	printf("s = %d\n", tdt(x, y));
}











