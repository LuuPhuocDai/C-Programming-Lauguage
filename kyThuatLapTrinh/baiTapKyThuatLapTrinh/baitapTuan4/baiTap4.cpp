#include <stdio.h>
#include <string.h>

// 1. Định nghĩa cấu trúc Benhnhan
struct Benhnhan {
    char TenBN[50];
    char NS[11]; // Định dạng ngày sinh: dd/mm/yyyy
    char Tinhtrang[50];
};

// 2. Hàm nhập danh sách bệnh nhân
void nhapDanhSach(struct Benhnhan ds[], int n) {
    for(int i = 0; i < n; i++) {
        printf("\nNhap thong tin benh nhan thu %d:\n", i + 1);
        printf("Ten benh nhan: ");
        fflush(stdin); // Xóa bộ đệm
        gets(ds[i].TenBN);
        printf("Ngay sinh (dd/mm/yyyy): ");
        gets(ds[i].NS);
        printf("Tinh trang: ");
        gets(ds[i].Tinhtrang);
    }
}

// 3. Hàm xuất danh sách bệnh nhân
void xuatDanhSach(struct Benhnhan ds[], int n) {
    printf("\nDanh sach benh nhan:\n");
    printf("%-20s%-15s%-20s\n", "Ten BN", "Ngay sinh", "Tinh trang");
    for(int i = 0; i < n; i++) {
        printf("%-20s%-15s%-20s\n", ds[i].TenBN, ds[i].NS, ds[i].Tinhtrang);
    }
}

// 4. Hàm sắp xếp danh sách theo tên bệnh nhân (sử dụng thuật toán nổi bọt)
void sapXepTheoTen(struct Benhnhan ds[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(strcmp(ds[j].TenBN, ds[j+1].TenBN) > 0) {
                // Hoán đổi vị trí
                struct Benhnhan temp = ds[j];
                ds[j] = ds[j+1];
                ds[j+1] = temp;
            }
        }
    }
}

// 5. Hàm tìm kiếm bệnh nhân theo tên
void timKiemTheoTen(struct Benhnhan ds[], int n, char ten[]) {
    int found = 0;
    printf("\nKet qua tim kiem cho '%s':\n", ten);
    printf("%-20s%-15s%-20s\n", "Ten BN", "Ngay sinh", "Tinh trang");
    
    for(int i = 0; i < n; i++) {
        if(strstr(ds[i].TenBN, ten) != NULL) { // Tìm chuỗi con
            printf("%-20s%-15s%-20s\n", ds[i].TenBN, ds[i].NS, ds[i].Tinhtrang);
            found = 1;
        }
    }
    
    if(!found) {
        printf("Khong tim thay benh nhan nao co ten chua '%s'\n", ten);
    }
}

int main() {
    int n;
    printf("Nhap so luong benh nhan: ");
    scanf("%d", &n);
    
    struct Benhnhan ds[n];
    
    // Gọi các hàm theo yêu cầu
    nhapDanhSach(ds, n);
    printf("\nDanh sach vua nhap:");
    xuatDanhSach(ds, n);
    
    sapXepTheoTen(ds, n);
    printf("\nDanh sach sau khi sap xep theo ten:");
    xuatDanhSach(ds, n);
    
    char tenTim[50];
    printf("\nNhap ten benh nhan can tim: ");
    fflush(stdin);
    gets(tenTim);
    timKiemTheoTen(ds, n, tenTim);
    
}