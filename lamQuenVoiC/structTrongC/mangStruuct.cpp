#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct sinhVien{
	char hoTen[30];
	char lop[20];
	double gpa;
};

typedef struct sinhVien sV;


// ham nhap
void nhap(sV *x){
	// nhap ten sinh vien
	printf("\nnhap ten sinh vien: ");
	fgets(x->hoTen, sizeof(x->hoTen), stdin);
	x->hoTen[strcspn(x->hoTen, "\n")] = 0;
	
	// nhap lop sinh vien
    printf("nhap lop sinh vien: ");
   	fgets(x->lop, sizeof(x->lop), stdin);
   	x->lop[strcspn(x->lop, "\n")] = 0;
   	
   	// nhap diem gpa cua sinh vien
   	printf("nhap diem gpa cua sinh vien: ");
   	scanf("%lf", &x->gpa);
   	getchar();

}
// nhap vaoo danh sach
void nhapDs(sV a[], int n){
	for(int i = 0; i < n; i++){
		printf("\nnhap thong tin sinh vien thu %d", i + 1);
		nhap(&a[i]);
	}
}

// ham xuat 
// 1. tao ham xuat
void xuat(sV *x){
	printf("\n=============================================\n");
	// xuat ten, lop va diem GPA cua sinh vien
	printf("Ho va Ten sinh vien: %s", x->hoTen);
	printf("\nLop Sinh Vien: %s", x->lop);
	printf("\nDiem GPA cua Sinh Vien: %.2lf", x->gpa);
	printf("\n=============================================\n");
}
// 2. xuat danh sach
void xuatDs(sV a[], int n){
	for(int i = 0; i < n; i++){
		printf("\nSinh vien thu %d", i + 1);
		xuat(&a[i]);
	}
}

// ham sap xep diem gpa cua sinh vien theo thu tu giam dan
void sapXepDiemGPA(sV a[], int n){
	int  j, i;
	sV banDau;
	for(i = 1; i < n; i++){
		banDau = a[i];
		j = i - 1;
		
		// su ly bang while
		while(j >=  0 && a[j].gpa > banDau.gpa){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = banDau;
	}
}


int main(){
	sinhVien a[100];
	int n;
	printf("nhap so luong sinh vien: ");
	scanf("%d", &n);
	getchar();
	
	// nhap danh sach sinh vien
	nhapDs(a, n);
	
	// xuat thong tin sinh vien
	xuatDs(a, n);
	
	
	return 0;
}



