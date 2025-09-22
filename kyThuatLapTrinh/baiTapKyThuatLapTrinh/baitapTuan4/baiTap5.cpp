#include <stdio.h>
#include <string.h>

// Định nghĩa cấu trúc Ngày
struct Ngay {
    int ngay;
    int thang;
    int nam;
};

// Định nghĩa cấu trúc Giờ
struct Gio {
    int gio;
    int phut;
};

// 1. Định nghĩa cấu trúc Chuyenbay
struct Chuyenbay {
    char maCB[6];      // 5 ký tự + 1 cho ký tự null
    struct Ngay ngayBay;
    struct Gio gioBay;
    char noiDi[21];    // 20 ký tự + 1 cho ký tự null
    char noiDen[21];   // 20 ký tự + 1 cho ký tự null
};

// 2. Hàm nhập danh sách chuyến bay
void nhapDanhSach(struct Chuyenbay ds[], int n) {
    for(int i = 0; i < n; i++) {
        printf("\nNhap thong tin chuyen bay thu %d:\n", i + 1);
        printf("Ma chuyen bay (toi da 5 ky tu): ");
        fflush(stdin);
        gets(ds[i].maCB);
        
        printf("Ngay bay (ngay thang nam): ");
        scanf("%d %d %d", &ds[i].ngayBay.ngay, &ds[i].ngayBay.thang, &ds[i].ngayBay.nam);
        
        printf("Gio bay (gio phut): ");
        scanf("%d %d", &ds[i].gioBay.gio, &ds[i].gioBay.phut);
        
        printf("Noi di (toi da 20 ky tu): ");
        fflush(stdin);
        gets(ds[i].noiDi);
        
        printf("Noi den (toi da 20 ky tu): ");
        gets(ds[i].noiDen);
    }
}

// 3. Hàm xuất danh sách chuyến bay
void xuatDanhSach(struct Chuyenbay ds[], int n) {
    printf("\nDanh sach chuyen bay:\n");
    printf("%-10s%-15s%-10s%-20s%-20s\n", "Ma CB", "Ngay bay", "Gio bay", "Noi di", "Noi den");
    for(int i = 0; i < n; i++) {
        printf("%-10s%02d/%02d/%-7d%02d:%02d%-15s%-20s%-20s\n", 
               ds[i].maCB,
               ds[i].ngayBay.ngay, ds[i].ngayBay.thang, ds[i].ngayBay.nam,
               ds[i].gioBay.gio, ds[i].gioBay.phut,
               "", ds[i].noiDi, ds[i].noiDen);
    }
}

// 4. Hàm sắp xếp danh sách theo mã chuyến bay
void sapXepTheoMa(struct Chuyenbay ds[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(strcmp(ds[j].maCB, ds[j+1].maCB) > 0) {
                struct Chuyenbay temp = ds[j];
                ds[j] = ds[j+1];
                ds[j+1] = temp;
            }
        }
    }
}

// 5. Hàm tìm kiếm chuyến bay theo mã
void timKiemTheoMa(struct Chuyenbay ds[], int n, char ma[]) {
    int found = 0;
    printf("\nKet qua tim kiem cho ma '%s':\n", ma);
    printf("%-10s%-15s%-10s%-20s%-20s\n", "Ma CB", "Ngay bay", "Gio bay", "Noi di", "Noi den");
    
    for(int i = 0; i < n; i++) {
        if(strcmp(ds[i].maCB, ma) == 0) {
            printf("%-10s%02d/%02d/%-7d%02d:%02d%-15s%-20s%-20s\n", 
                   ds[i].maCB,
                   ds[i].ngayBay.ngay, ds[i].ngayBay.thang, ds[i].ngayBay.nam,
                   ds[i].gioBay.gio, ds[i].gioBay.phut,
                   "", ds[i].noiDi, ds[i].noiDen);
            found = 1;
        }
    }
    
    if(!found) {
        printf("Khong tim thay chuyen bay co ma '%s'\n", ma);
    }
}

int main() {
    int n;
    printf("Nhap so luong chuyen bay: ");
    scanf("%d", &n);
    
    struct Chuyenbay ds[n];
    
    // Gọi các hàm theo yêu cầu
    nhapDanhSach(ds, n);
    printf("\nDanh sach vua nhap:");
    xuatDanhSach(ds, n);
    
    sapXepTheoMa(ds, n);
    printf("\nDanh sach sau khi sap xep theo ma chuyen bay:");
    xuatDanhSach(ds, n);
    
    char maTim[6];
    printf("\nNhap ma chuyen bay can tim: ");
    fflush(stdin);
    gets(maTim);
    timKiemTheoMa(ds, n, maTim);
    
}