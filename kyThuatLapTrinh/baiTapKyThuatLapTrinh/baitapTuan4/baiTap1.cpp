#include <stdio.h>
#include <string.h>

// 1. Định nghĩa cấu trúc Sinhvien
struct Sinhvien {
    char MSSV[10];
    char Hoten[50];
    float Diemtk;
    char Lop[10];
};

// 2. Hàm nhập danh sách sinh viên
void NhapDSSV(struct Sinhvien sv[], int n) {
    for(int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i+1);
        printf("Nhap MSSV: ");
        scanf("%s", sv[i].MSSV);
        fflush(stdin);  // Xóa bộ nhớ đệm
        printf("Nhap Ho ten: ");
        gets(sv[i].Hoten);
        printf("Nhap Diem tong ket: ");
        scanf("%f", &sv[i].Diemtk);
        fflush(stdin);
        printf("Nhap Lop: ");
        scanf("%s", sv[i].Lop);
    }
}

// 3. Hàm xuất danh sách sinh viên
void XuatDSSV(struct Sinhvien sv[], int n) {
    printf("\nDanh sach sinh vien:\n");
    printf("%-10s %-20s %-10s %-10s\n", "MSSV", "Ho ten", "Diem TK", "Lop");
    for(int i = 0; i < n; i++) {
        printf("%-10s %-20s %-10.2f %-10s\n", 
               sv[i].MSSV, 
               sv[i].Hoten, 
               sv[i].Diemtk, 
               sv[i].Lop);
    }
}

// 4. Hàm sắp xếp theo MSSV
void SapXepTheoMSSV(struct Sinhvien sv[], int n) {
    struct Sinhvien temp;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(strcmp(sv[i].MSSV, sv[j].MSSV) > 0) {
                temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp theo điểm tổng kết
void SapXepTheoDiem(struct Sinhvien sv[], int n) {
    struct Sinhvien temp;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(sv[i].Diemtk < sv[j].Diemtk) {
                temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}

// 5. Hàm tìm kiếm theo MSSV
void TimKiemTheoMSSV(struct Sinhvien sv[], int n, char searchMSSV[]) {
    int found = 0;
    printf("\nKet qua tim kiem:\n");
    printf("%-10s %-20s %-10s %-10s\n", "MSSV", "Ho ten", "Diem TK", "Lop");
    
    for(int i = 0; i < n; i++) {
        if(strcmp(sv[i].MSSV, searchMSSV) == 0) {
            printf("%-10s %-20s %-10.2f %-10s\n", 
                   sv[i].MSSV, 
                   sv[i].Hoten, 
                   sv[i].Diemtk, 
                   sv[i].Lop);
            found = 1;
        }
    }
    if(!found) {
        printf("Khong tim thay sinh vien voi MSSV %s\n", searchMSSV);
    }
}

int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    fflush(stdin);
    
    struct Sinhvien sv[n];
    
    // Gọi các hàm
    NhapDSSV(sv, n);
    
    printf("\nDanh sach truoc khi sap xep: ");
    XuatDSSV(sv, n);
    printf("\n---------------------------------------------------------");
    // Sắp xếp theo MSSV
    SapXepTheoMSSV(sv, n);
    printf("\nDanh sach sau khi sap xep theo MSSV: ");
    XuatDSSV(sv, n);
    printf("\n---------------------------------------------------------");
    // Sắp xếp theo điểm
    SapXepTheoDiem(sv, n);
    printf("\nDanh sach sau khi sap xep theo diem tong ket: ");
    XuatDSSV(sv, n);
    printf("\n---------------------------------------------------------");
    // Tìm kiếm
    char searchMSSV[10];
    printf("\nNhap MSSV can tim: ");
    scanf("%s", searchMSSV);
    TimKiemTheoMSSV(sv, n, searchMSSV);
    
}
