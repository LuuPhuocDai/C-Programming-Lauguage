#include <stdio.h>
#include <stdlib.h>

// Hàm nhập dãy số thực
int Nhap(float **a) {
    int n;
    printf("Nhap so phan tu cua day: ");
    scanf("%d", &n);
    while (n <= 0) {
        printf("So phan tu phai lon hon 0. Nhap lai: ");
        scanf("%d", &n);
    }
    
    // Cấp phát bộ nhớ động
    *a = (float *)malloc(n * sizeof(float));
    if (*a == NULL) {
        printf("Khong the cap phat bo nho!\n");
        return 0;
    }
    
    printf("Nhap %d so thuc:\n", n);
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%f", &(*a)[i]);
    }
    return n;
}

// Hàm tìm max của các phần tử dương
int MaxDuong(int n, float *a, float *max) {
    int found = 0;
    *max = 0;
    
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            if (!found || a[i] > *max) {
                *max = a[i];
                found = 1;
            }
        }
    }
    return found;
}

// Hàm kiểm tra tính chất Fibonacci
int Fibo(int n, float *a) {
    if (n < 3) return 0; // Cần ít nhất 3 phần tử để kiểm tra
    
    for (int i = 2; i < n; i++) {
        // Kiểm tra với sai số nhỏ để xử lý số thực
        if (a[i] != a[i-1] + a[i-2]) {
            return 0;
        }
    }
    return 1;
}

// Hàm xuất dãy
void Xuat(int n, float *a) {
    printf("Day so: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");
}

// Hàm menu
int Menu() {
    int choice;
    printf("\n===== MENU =====\n");
    printf("1. Nhap day\n");
    printf("2. Xuat day\n");
    printf("3. Tim max duong\n");
    printf("4. Kiem tra tinh Fibonacci\n");
    printf("5. Thoat\n");
    printf("Chon: ");
    scanf("%d", &choice);
    return (choice >= 1 && choice <= 5) ? choice : 0;
}

int main() {
    float *a = NULL;
    int n = 0;
    float max;
    int choice;
    
    while (1) {
        choice = Menu();
        if (choice == 0) {
            printf("Lua chon khong hop le! Vui long chon lai.\n");
            continue;
        }
        
        switch (choice) {
            case 1: // Nhập dãy
                if (a != NULL) free(a);
                n = Nhap(&a);
                if (n == 0) {
                    printf("Nhap day that bai!\n");
                } else {
                    printf("Nhap day thanh cong!\n");
                }
                break;
                
            case 2: // Xuất dãy
                if (a == NULL || n == 0) {
                    printf("Chua nhap day!\n");
                } else {
                    Xuat(n, a);
                }
                break;
                
            case 3: // Tìm max dương
                if (a == NULL || n == 0) {
                    printf("Chua nhap day!\n");
                } else {
                    if (MaxDuong(n, a, &max)) {
                        printf("Gia tri duong lon nhat: %.2f\n", max);
                    } else {
                        printf("Khong co so duong trong day!\n");
                    }
                }
                break;
                
            case 4: // Kiểm tra Fibonacci
                if (a == NULL || n == 0) {
                    printf("Chua nhap day!\n");
                } else {
                    if (Fibo(n, a)) {
                        printf("Day co tinh chat Fibonacci.\n");
                    } else {
                        printf("Day khong co tinh chat Fibonacci.\n");
                    }
                }
                break;
                
            case 5: // Thoát
                if (a != NULL) free(a); 
                printf("Tam biet!\n");
                return 0;
        }
    }
    
    return 0;
}