#include <stdio.h>
#include <string.h>

// dinh nghia cau truc sinhvien
struct SinhVien {
    char hoTen[50];
    char mssv[10];
    char ngaySinh[11]; 
    char gioiTinh[4];  
    char diaChi[100];
};

int main() {
    // Khai bao bien sinh vien
    struct SinhVien sv;

    // Nhap thong tin sinhvien
    printf("Nhap ho ten: ");
    fgets(sv.hoTen, 50, stdin);
    sv.hoTen[strcspn(sv.hoTen, "\n")] = 0; // xoa ki tu xuong dong

    printf("Nhap MSSV: ");
    fgets(sv.mssv, 10, stdin);
    sv.mssv[strcspn(sv.mssv, "\n")] = 0;

    printf("Nhap ngay sinh (dd/mm/yyyy): ");
    fgets(sv.ngaySinh, 11, stdin);
    sv.ngaySinh[strcspn(sv.ngaySinh, "\n")] = 0;

    printf("Nhap gioi tinh (Nam/Nu): ");
    fgets(sv.gioiTinh, 4, stdin);
    sv.gioiTinh[strcspn(sv.gioiTinh, "\n")] = 0;

    printf("Nhap dia chi: ");
    fgets(sv.diaChi, 100, stdin);
    sv.diaChi[strcspn(sv.diaChi, "\n")] = 0;

    // In thong tin sinhvien
    printf("\n=== Thong tin sinh vien ===\n");
    printf("Ho ten: %s\n", sv.hoTen);
    printf("MSSV: %s\n", sv.mssv);
    printf("Ngay sinh: %s\n", sv.ngaySinh);
    printf("Gioi tinh: %s\n", sv.gioiTinh);
    printf("Dia chi: %s\n", sv.diaChi);

    
}
