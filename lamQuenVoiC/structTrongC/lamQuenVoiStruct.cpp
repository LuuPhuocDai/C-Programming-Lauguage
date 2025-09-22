#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(){
	int n;
	struct giaCanh{
		char tenBa[50];
		char tenMe[50];
		int tuoiBa;
		int tuoiMe;
		char ngheNghiepBa[60];
		char ngheNghiepMe[60];
	};
	struct dsHocSinh{
		char ten[30];
		char truong[40];
		int lop;
		struct giaCanh *ttCaNhan;
	};
	struct dsHocSinh *hS;
	
	printf("nhap so luong danh sach hoc sinh: ");
	scanf("%d", &n);
	getchar();
	
	hS = (struct dsHocSinh*)malloc(n*sizeof(struct dsHocSinh));
	
	for(int i = 0; i < n; i++){
		
		hS[i].ttCaNhan = (struct giaCanh*)malloc(sizeof(struct giaCanh));
		
		printf("hoc sinh thu %d", i + 1);
		
		printf("\nnhap ten hoc sinh: ");
		fgets(hS[i].ten, sizeof(hS[i].ten), stdin);
		hS[i].ten[strcspn(hS[i].ten, "\n")] = 0;
		
		printf("nhap ten truong: ");
		fgets(hS[i].truong, sizeof(hS[i].truong), stdin);
		hS[i].truong[strcspn(hS[i].truong, "\n")] = 0;
		
		printf("nhap lop: ");
		scanf("%d", &hS[i].lop);
		getchar();
		
		printf("=nhap thong tin ca nhan=");
		
		printf("\nnhap ten ba: ");
		fgets(hS[i].ttCaNhan->tenBa, sizeof(hS[i].ttCaNhan->tenBa), stdin);
		hS[i].ttCaNhan->tenBa[strcspn(hS[i].ttCaNhan->tenBa, "\n")] = 0;
		
		printf("nhap so tuoi cua ba: ");
		scanf("%d", &hS[i].ttCaNhan->tuoiBa);
		getchar();
		
		printf("nhap nghe nghiep cua ba: ");
		fgets(hS[i].ttCaNhan->ngheNghiepBa, sizeof(hS[i].ttCaNhan->ngheNghiepBa), stdin);
		hS[i].ttCaNhan->ngheNghiepBa[strcspn(hS[i].ttCaNhan->ngheNghiepBa, "\n")] = 0;
		
		
		printf("\nnhap ten Me: ");
		fgets(hS[i].ttCaNhan->tenMe, sizeof(hS[i].ttCaNhan->tenMe), stdin);
		hS[i].ttCaNhan->tenMe[strcspn(hS[i].ttCaNhan->tenMe, "\n")] = 0;
		
		printf("nhap so tuoi cua Me: ");
		scanf("%d", &hS[i].ttCaNhan->tuoiMe);
		getchar();
		
		printf("nhap nghe nghiep cua Me: ");
		fgets(hS[i].ttCaNhan->ngheNghiepMe, sizeof(hS[i].ttCaNhan->ngheNghiepMe), stdin);
		hS[i].ttCaNhan->ngheNghiepMe[strcspn(hS[i].ttCaNhan->ngheNghiepMe, "\n")] = 0;
		
	}
	printf("\n========danh sach hoc sinh===========\n");
	
	for(int i = 0; i < n; i++){
		printf("hoc sinh thu %d", i + 1);
		printf("\nten hoc sinh: %s", hS[i].ten);
		printf("\ntruong: %s ", hS[i].truong);
		printf("\nlop: %d", hS[i].lop);
		printf("\n--thong tin ca nhan--\n");
	
		printf("ten ba: %s",hS[i].ttCaNhan->tenBa);
		printf("\nso tuoi cua ba: %d ", hS[i].ttCaNhan->tuoiBa);
		printf("\nnghe nghiep cua ba: %s", hS[i].ttCaNhan->ngheNghiepBa);
			
	    printf("\nten Me: %s",hS[i].ttCaNhan->tenMe);
		printf("\nso tuoi cua Me: %d ", hS[i].ttCaNhan->tuoiMe);
		printf("\nnghe nghiep cua Me: %s", hS[i].ttCaNhan->ngheNghiepMe);
		printf("\n-------------------------------------------------------------\n");
	}
	
	
	
	return 0;
}
