#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Định nghĩa cấu trúc Sach
typedef struct {
    char TenSach[100];
    char TacGia[100];
    int NamXuatBan;
} Sach;

// Hàm nhập dãy sách
void Nhap(int *n, Sach *&A) {
    printf("Nhap so cuon sach: ");
    scanf("%d", n);
    
    // Cấp phát bộ nhớ cho mảng sách
    A = (Sach*)malloc((*n) * sizeof(Sach));
    
    // Nhập thông tin các cuốn sách
    for (int i = 0; i < *n; i++) {
        getchar(); // Xóa ký tự newline còn lại trong bộ đệm
        printf("Nhap ten sach thu %d: ", i + 1);
        fgets(A[i].TenSach, 100, stdin);
        A[i].TenSach[strcspn(A[i].TenSach, "\n")] = 0;  // Loại bỏ ký tự newline

        printf("Nhap tac gia sach thu %d: ", i + 1);
        fgets(A[i].TacGia, 100, stdin);
        A[i].TacGia[strcspn(A[i].TacGia, "\n")] = 0;  // Loại bỏ ký tự newline

        printf("Nhap nam xuat ban sach thu %d: ", i + 1);
        scanf("%d", &A[i].NamXuatBan);
    }
}

// Hàm xuất danh sách sách
void Xuat(int n, Sach A[]) {
    for (int i = 0; i < n; i++) {
        printf("Sach thu %d:\n", i + 1);
        printf("Ten Sach: %s\n", A[i].TenSach);
        printf("Tac Gia: %s\n", A[i].TacGia);
        printf("Nam Xuat Ban: %d\n\n", A[i].NamXuatBan);
    }
}

// Hàm đếm số sách của một tác giả
int DemSach(int n, Sach *a) {
    char tacGia[100];
    int count = 0;
    
    getchar();  // Xóa ký tự newline còn lại trong bộ đệm
    printf("Nhap ten tac gia can dem: ");
    fgets(tacGia, 100, stdin);
    tacGia[strcspn(tacGia, "\n")] = 0;  // Loại bỏ ký tự newline

    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].TacGia, tacGia) == 0) {
            count++;
        }
    }
    
    return count;
}

// Hàm thống kê số lượng sách theo năm xuất bản
void Thongke(int n, Sach *a) {
    int *years = (int*)malloc(n * sizeof(int)); // Lưu trữ các năm đã gặp
    int *counts = (int*)malloc(n * sizeof(int)); // Lưu trữ số lượng sách theo từng năm
    int numYears = 0;

    // Đếm số sách theo năm xuất bản
    for (int i = 0; i < n; i++) {
        int year = a[i].NamXuatBan;
        int found = 0;

        // Kiểm tra xem năm này đã xuất hiện chưa
        for (int j = 0; j < numYears; j++) {
            if (years[j] == year) {
                counts[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            years[numYears] = year;
            counts[numYears] = 1;
            numYears++;
        }
    }

    // Xuất kết quả thống kê
    printf("Thong ke so sach theo nam xuat ban:\n");
    for (int i = 0; i < numYears; i++) {
        printf("%d: %d cuon\n", years[i], counts[i]);
    }

    // Giải phóng bộ nhớ
    free(years);
    free(counts);
}

// Hàm menu
int Menu() {
    int choice;
    printf("\nMenu:\n");
    printf("1. Nhap n cuon sach\n");
    printf("2. Xuat n cuon sach\n");
    printf("3. Dem theo tac gia\n");
    printf("4. Thong ke\n");
    printf("5. Thoat\n");
    printf("Nhap lua chon: ");
    scanf("%d", &choice);
    return choice;
}

// Hàm main
int main() {
    Sach *A = NULL;
    int n = 0;
    
    while (1) {
        int choice = Menu();
        
        switch (choice) {
            case 1:
                Nhap(&n, A);
                break;
            case 2:
                if (n > 0) {
                    Xuat(n, A);
                } else {
                    printf("Chua nhap du lieu sach.\n");
                }
                break;
            case 3:
                if (n > 0) {
                    int count = DemSach(n, A);
                    printf("So cuon sach cua tac gia la: %d\n", count);
                } else {
                    printf("Chua nhap du lieu sach.\n");
                }
                break;
            case 4:
                if (n > 0) {
                    Thongke(n, A);
                } else {
                    printf("Chua nhap du lieu sach.\n");
                }
                break;
            case 5:
                free(A);
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }

    return 0;
}
