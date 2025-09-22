#include "stdio.h"
#include "math.h"
int ktSoAm(int);
int soChinhPhuong(int);
int ktSoNT(int );

int ktSoAm(int t){
	if( t < 0){
		return 4;// la cac phan tu co so am trong mang
	}
	else{
		return 5;
	}
}

int ktSoNT(int m){
	int i; 
	for(i = 2; i<=m/2; i++){
		if(m % i == 0 ){
			return 2;// kh phai la so nguyen to
		}
	}
	return 3;// la so nguyen to
}

int soChinhPhuong(int n){
	int x;
	x = sqrt(n);
	if(x*x == n){
		return 1;// la so chinh phuong
	}else{
		return 0;// khong phai la so chinh phuong
	}
}

int main(){
	int n, i, a[101], b[101], dem = 0, dem1 = 0, dem2 = 0, dem3 = 0;
	int sum = 0;
	float tbc;
	int max , min, am ;
	
	printf("nhap phan tu n: ");
	scanf("%d", &n);
	for(i = 0; i<n;i++){
		printf("A[%d] = ", i);
		scanf("%d", &a[i]);
	}
	printf("cac phan tu vua nhap vao la: ");
	for(i = 0; i<n;i++){
		printf("%d ", a[i]);
	}
	for(i = 0; i<n;i++){
		if(i % 2 == 0 && a[i] % 2 == 1 ){
			sum += a[i];
			dem++;
		}
	}
	tbc = (float)sum / (float)dem;
	printf("\ntrung binh cong cua so le o vi tri chan la: %.2f", tbc);
	// gia tri max min trong mang
	max = a[0];
	for(i = 0; i<n;i++){
		if(a[i] > max){
			max = a[i];
		}
		else{
			min = a[i];
		}
	}
	printf("\ngia tri lon nhat trong mang la: %d", max);
	printf("\ngia tri nho nhat trong mang la: %d", min);
	// tim so chinh phuong trong mang
	for(i = 0; i<n; i++){
		if(soChinhPhuong(a[i]) == 1){
			dem1++;
		}
	}
	printf("\nso chinh phuong trong mang la: %d", dem1);
	printf("\nbao gom: ");
	for(i = 0; i<n; i++){
		if(soChinhPhuong(a[i]) == 1){
			printf("%d ", a[i]);
		}
	}
	// ktr so nguyen to trong mang 
	for(i = 0; i<=n; i++){
		if(ktSoNT(a[i]) == 3){
			dem2++;
		}
	}
	printf("\ncac so nguyen to trong mang la: %d ", dem2);
	printf("\nbao gom: ");
	for(i = 0; i<=n; i++){
		if(ktSoNT(a[i]) == 3){
			printf("%d ", a[i]);
	    }
    }
}