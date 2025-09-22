#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. Xây dựng cấu trúc SanPham
struct SanPham {
    char TenSP[50];
    int NamSX;
    double Gia;
};

// 2. Hàm nhập danh sách sản phẩm
void nhapDanhSach(struct SanPham *ds, int n) {
    printf("Nhap thong tin cho %d san pham:\n", n);
    for(int i = 0; i < n; i++) {
        printf("\nSan pham %d:\n", i + 1);
        printf("Ten san pham: ");
        getchar(); // Xóa ký tự xuống dòng còn sót lại từ lần nhập trước
        fgets(ds[i].TenSP, 50, stdin);
        ds[i].TenSP[strcspn(ds[i].TenSP, "\n")] = 0; // Xóa ký tự xuống dòng
        
        printf("Nam san xuat: ");
        scanf("%d", &ds[i].NamSX);
        printf("Gia ban: ");
        scanf("%lf", &ds[i].Gia);
    }
}

// 3. Hàm xuất danh sách
void xuatDanhSach(struct SanPham *ds, int n) {
    printf("\nDanh sach san pham:\n");
    printf("%-20s %-15s %-15s\n", "Ten SP", "Nam SX", "Gia");
    printf("------------------------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%-20s %-15d %-15.2lf\n", ds[i].TenSP, ds[i].NamSX, ds[i].Gia);
    }
}

// 4. Hàm sắp xếp theo tên sản phẩm (bubble sort)
void sapXepTheoTen(struct SanPham *ds, int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(strcmp(ds[j].TenSP, ds[j+1].TenSP) > 0) {
                // Hoán đổi
                struct SanPham temp = ds[j];
                ds[j] = ds[j+1];
                ds[j+1] = temp;
            }
        }
    }
}

// 5. Hàm tìm kiếm theo tên sản phẩm
void timKiemTheoTen(struct SanPham *ds, int n, char *tenTim) {
    int found = 0;
    printf("\nKet qua tim kiem cho '%s':\n", tenTim);
    printf("%-20s %-15s %-15s\n", "Ten SP", "Nam SX", "Gia");
    printf("------------------------------------------------\n");
    
    for(int i = 0; i < n; i++) {
        if(strstr(ds[i].TenSP, tenTim) != NULL) {
            printf("%-20s %-15d %-15.2lf\n", ds[i].TenSP, ds[i].NamSX, ds[i].Gia);
            found = 1;
        }
    }
    if(!found) {
        printf("Khong tim thay san pham nao co ten chua '%s'\n", tenTim);
    }
}

int main() {
    int n;
    printf("Nhap so luong san pham: ");
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("So luong san pham phai lon hon 0!\n");
        return 1;
    }
    
    // Cấp phát động mảng
    struct SanPham *ds = (struct SanPham*)malloc(n * sizeof(struct SanPham));
    if(ds == NULL) {
        printf("Khong du bo nho de cap phat!\n");
        return 1;
    }
    
    // Gọi các hàm
    nhapDanhSach(ds, n);
    printf("\nDanh sach truoc khi sap xep:\n");
    xuatDanhSach(ds, n);
    
    sapXepTheoTen(ds, n);
    printf("\nDanh sach sau khi sap xep theo ten:\n");
    xuatDanhSach(ds, n);
    
    char tenTim[50];
    printf("\nNhap ten san pham can tim: ");
    getchar(); // Xóa ký tự xuống dòng còn sót lại
    fgets(tenTim, 50, stdin);
    tenTim[strcspn(tenTim, "\n")] = 0; // Xóa ký tự xuống dòng
    timKiemTheoTen(ds, n, tenTim);
    
    // Giải phóng bộ nhớ
    free(ds);
    
    return 0;
}