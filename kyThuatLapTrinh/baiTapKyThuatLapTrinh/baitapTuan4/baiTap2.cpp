#include <stdio.h>
#include "stdlib.h"
#include <string.h>

// 1. Định nghĩa cấu trúc Sách
struct Sach {
    char TenSach[100];
    int NamXB;
    double Gia;
};

// 2. Hàm nhập danh sách sách
void nhapDanhSach(struct Sach ds[], int n) {
    printf("Nhap thong tin %d cuon sach:\n", n);
    for(int i = 0; i < n; i++) {
        printf("\nCuon sach thu %d:\n", i+1);
        
        printf("Ten sach: ");
        getchar(); // Xóa ký tự xuống dòng còn sót lại
        fgets(ds[i].TenSach, 100, stdin);
        ds[i].TenSach[strcspn(ds[i].TenSach, "\n")] = 0; // Xóa ký tự xuống dòng
        
        printf("Nam xuat ban: ");
        scanf("%d", &ds[i].NamXB);
        
        printf("Gia thanh: ");
        scanf("%lf", &ds[i].Gia);
    }
}

// 3. Hàm xuất danh sách sách
void xuatDanhSach(struct Sach ds[], int n) {
    printf("\nDanh sach sach:\n");
    printf("STT\tTen Sach\t\tNam XB\tGia Thanh\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%-20s\t%d\t%.2lf\n", 
               i+1, 
               ds[i].TenSach, 
               ds[i].NamXB, 
               ds[i].Gia);
    }
}

// 4. Hàm sắp xếp theo Tên sách (tăng dần)
void sapXepTheoTen(struct Sach ds[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(strcmp(ds[i].TenSach, ds[j].TenSach) > 0) {
                struct Sach temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp theo Giá thành (giảm dần)
void sapXepTheoGia(struct Sach ds[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(ds[i].Gia < ds[j].Gia) {
                struct Sach temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

// 5. Hàm tìm kiếm theo Tên sách
void timKiemTheoTen(struct Sach ds[], int n, char ten[]) {
    int found = 0;
    printf("\nKet qua tim kiem cho '%s':\n", ten);
    printf("STT\tTen Sach\t\tNam XB\tGia Thanh\n");
    
    for(int i = 0; i < n; i++) {
        if(strstr(ds[i].TenSach, ten) != NULL) {
            printf("%d\t%-20s\t%d\t%.2lf\n", 
                   i+1, 
                   ds[i].TenSach, 
                   ds[i].NamXB, 
                   ds[i].Gia);
            found = 1;
        }
    }
    
    if(!found) {
        printf("Khong tim thay sach nao co ten chua '%s'\n", ten);
    }
}

int main() {
    int n;
    printf("Nhap so luong sach: ");
    scanf("%d", &n);
    
    if(n <= 0 || n > 100) {
        printf("So luong sach khong hop le!\n");
        return 1;
    }
    
    struct Sach ds[100]; // Tối đa 100 cuốn sách
    
    // Nhập danh sách
    nhapDanhSach(ds, n);
    
    // Xuất danh sách ban đầu
    printf("\nDanh sach vua nhap:\n");
    xuatDanhSach(ds, n);
    
    // Sắp xếp theo tên sách
    sapXepTheoTen(ds, n);
    printf("\nDanh sach sau khi sap xep theo ten:\n");
    xuatDanhSach(ds, n);
    
    // Sắp xếp theo giá
    sapXepTheoGia(ds, n);
    printf("\nDanh sach sau khi sap xep theo gia giam dan:\n");
    xuatDanhSach(ds, n);
    
    // Tìm kiếm sách
    char tenTim[100];
    printf("\nNhap ten sach can tim: ");
    getchar(); // Xóa ký tự xuống dòng còn sót lại
    fgets(tenTim, 100, stdin);
    tenTim[strcspn(tenTim, "\n")] = 0; // Xóa ký tự xuống dòng
    timKiemTheoTen(ds, n, tenTim);
    
    return 0;
}