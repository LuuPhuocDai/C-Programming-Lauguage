#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

// khoi tao struct

struct noiSong{// noi song cua struct nhan vien
	int soDuong;
	char tenDuong[40];
	char phuong[30];
	char pho[30];
};

struct nhanVien{
	char ten[30];
	int tuoi;
	struct noiSong diaChi;
};

// ham nhap
void inPutFct(struct nhanVien nv[], int n){
	for(int i = 0; i < n; i++){
		printf("nhan vien thu %d", i + 1);
		getchar();// xoa ky tu xuong dong con sot lai
		
		// nhap ten nhan vien
		printf("\nnhap ten nhan vien: ");
		fgets(nv[i].ten, sizeof(nv[i].ten), stdin);
		nv[i].ten[strcspn(nv[i].ten, "\n")] = 0;// xoa ki tu xuong dong khi dung fgets
		
		// nhap tuoi nhan vien
		printf("nhap so tuoi nhan vien: ");
		scanf("%d", &nv[i].tuoi);
		getchar();
		
		// nhap dia chi nhan vien
		printf("=nhap dia chi=");
		
		// nhap so duong
		printf("\nSo duong: ");
		scanf("%d", &nv[i].diaChi.soDuong);
		getchar();	
		
		// nhap ten duong
		printf("nhap ten duong: ");
		fgets(nv[i].diaChi.tenDuong, sizeof(nv[i].diaChi.tenDuong), stdin);
		nv[i].diaChi.tenDuong[strcspn(nv[i].diaChi.tenDuong, "\n")] = 0;
		
		// nhap ten phuong 
		printf("nhap ten phuong/huyen: ");
		fgets(nv[i].diaChi.phuong, sizeof(nv[i].diaChi.phuong), stdin);
		nv[i].diaChi.phuong[strcspn(nv[i].diaChi.phuong, "\n")] = 0;
		
		// nhap ten thanh pho
		printf("nhap ten thanh pho or tinh: ");
		fgets(nv[i].diaChi.pho, sizeof(nv[i].diaChi.pho), stdin);
		nv[i].diaChi.pho[strcspn(nv[i].diaChi.pho, "\n")] = 0;
		printf("\n");
	}
}

// ham xuat
void outPutFct(struct nhanVien nv[], int n){
	printf("\n============================ danh sach nhan vien ============================\n");
	printf("STT\tTen nhan Vien\tTuoi Nhan Vien\tDia Chi cua Nhan Vien\n");
	for(int i = 0; i < n; i++){
		printf("%d\t%-20s\t%d\tDuong %d %s, %s, %s\n", i + 1,
		                            nv[i].ten, 
									nv[i].tuoi,
									nv[i].diaChi.soDuong,
									nv[i].diaChi.tenDuong,
									nv[i].diaChi.phuong,
									nv[i].diaChi.pho);
	}
}

// ham chuyen doi chu cai dau cua ho va ten thanh chu hoa
void inHoaChuDau(char ten[]){
	int i;
	int len = strlen(ten);
	for(i = 0; i < len; i++){
		// doi in hoa ki tu dau  va sau dau cach
		if(i == 0 || ten[i - 1] == ' '){
			ten[i] = toupper(ten[i]);// in hoa
		}
		else{
			ten[i] = tolower(ten[i]);
		}
	}
}
	
int main(){
	int n;
	struct nhanVien nv[100];
	printf("nhap so luong nhan vien: ");
	scanf("%d", &n);
	
	// nhap thong tin nhan vien
	inPutFct(nv, n);
	
	//in hoa chu cai dau 
	for(int i = 0; i < n; i++){
		inHoaChuDau(nv[i].ten);
		inHoaChuDau(nv[i].diaChi.tenDuong);
		inHoaChuDau(nv[i].diaChi.phuong);
		inHoaChuDau(nv[i].diaChi.pho);
	}
	
	// xuat thong tin nhan vien
	outPutFct(nv, n);
	
	
	
	
	
	
	
	return 0;
}
