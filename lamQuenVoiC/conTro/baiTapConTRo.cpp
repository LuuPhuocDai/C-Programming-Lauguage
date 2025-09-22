#include "stdio.h"
#include "limits.h"
#include "stdlib.h"

// ham max
int hamMax(int *a, int n){
	int max = a[0];
	for(int i = 1; i < n; i++){
		if(*(a + i) > max ){
			max = *(a + i);
		}
	}
	return max;
}
// ham min
int hamMin(int *a, int n){
	int min = a[0];
	for(int i = 1; i < n; i++){
		if(*(a + i) < min ){
			min = *(a + i);
		}
	}
	return min;
}
// ham nhap
void hamNhap(int *a, int n){
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", a + i);
	}
}
// ham xuat
void hamXuat(int *a, int n){
	for(int i = 0; i < n; i++){
		printf("%d ", *(a + i));
		if((i + 1) % 10 == 0){
           printf("\n");
        }
	}
}
// ham sap xep tang dan
void sapXepTangDan(int *a, int n){
	int kgian = 0;
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-1-i; j++){
			if(*(a + j) > *(a + j + 1)){
				kgian = *(a + j);
				*(a + j) = *(a + j + 1);
				*(a + j + 1) = kgian;
			}
		}
	}
}
// ham sap xep giam dan
void sapXepGiamDan(int *a, int n){
	int banDau = 0;
	for(int i = 1; i < n; i++){
		banDau = *(a + i);
		int j = i - 1;
		while(j >= 0 && banDau > *(a + j)){
			*(a + j + 1) = *(a + j);
			j--;
		}
		*(a + j + 1) = banDau;
	}
}
// ham duyet tat ca so duong 
void hamDuong(int *a, int n){
	printf("\nso duong trong mang la: ");
	for(int i = 0; i < n; i++){
		if(*(a + i) > 0){
			printf("%d ", *(a + i));
		}
	}
}
// ham tim so lap lai nhieu nhat
void TimCacPhanTuLapLaiNhieuNhat(int *a, int n){
	int dem = 1, max = 1;
	int demphanTuTrung = 0;
	int ketQua[100];
	
	sapXepTangDan(a, n);
	for(int i = 1; i < n; i++){
		if(*(a + i) == *(a + i - 1)){
			dem++;
		}
		else{
			if(dem > max){
				max = dem;
				ketQua[0] = *(a + i - 1);
				demphanTuTrung = 1;
			}
			else if(dem == max){
				ketQua[demphanTuTrung++] = *(a + i - 1);
			}
			dem = 1;
			}
		}
	if(dem > max){
		max = dem;
		ketQua[0] = *(a + n - 1);
		demphanTuTrung = 1;
	}
	else if(dem == max){
		ketQua[demphanTuTrung++] = *(a + n - 1);
	}
	if(max < 2){
		printf("\nkhong co phan tu nao trung nhau trong mang");
	}
	else{
		printf("\nco %d phan tu xuat hien nhieu nhat la phan tu (xuat hien %d lan): ",demphanTuTrung, max);
		for(int i = 0; i < demphanTuTrung; i++){
			printf("%d ", ketQua[i]);
		}
	}
}
// ham tim kiem phan tu trong mang
int timKim(int *a, int n, int soCanTim){
	for(int i = 0; i < n; i++){
		if(*(a + i) == soCanTim){
			return i;
		}
	}
	return -1;
}
	

int main(){
	int *a, n;
	printf("nhap n: ");
	scanf("%d", &n);
	
	a = (int *)malloc(n * sizeof(int));	
	
	hamNhap(a, n);
	printf("mang ban vua nhap vao la: \n");
	hamXuat(a, n);
	
	printf("\ngia tri lon nhat trong mang la %d", hamMax(a, n));
	printf("\ngia tri nho nhat trong mang la %d", hamMin(a, n));
	
	printf("\nsap xep tang dan: ");
	sapXepTangDan(a, n);
	hamXuat(a, n);
	
	printf("\nsap xep giam dan: ");
	sapXepGiamDan(a, n);
	hamXuat(a, n);
	
	hamDuong(a, n);
	
	TimCacPhanTuLapLaiNhieuNhat(a, n);
	
	
	
	return 0;
}
