#include "stdio.h"
#include "stdlib.h"

// a. Hàm cấp phát bộ nhớ động
void CapPhat1(int n, int ***a) {
    *a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        (*a)[i] = (int *)malloc(n * sizeof(int));
    }
}

// b. Hàm giải phóng bộ nhớ
void XoaBN(int n, int **a) {
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
}

// c. Nhập ma trận
void Nhap(int *n, int ***a) {
    printf("Nhap cap cua ma tran vuong n: ");
    scanf("%d", n);
    CapPhat1(*n, a);
    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &((*a)[i][j]));
        }
    }
}

// d. Xuất ma trận
void Xuat(int n, int **a) {
    printf("Ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
}

// e. Kiểm tra đối xứng qua đường chéo phụ
int DoiXungPhu(int n, int **a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[n - 1 - j][n - 1 - i]) {
                return 0; // Không đối xứng
            }
        }
    }
    return 1; // Đối xứng
}

// f. Liệt kê các hàng có tổng max
void LietKe(int n, int **a) {
    int maxSum = -2147483648;
    int *sums = (int *)malloc(n * sizeof(int));

    // Tính tổng từng hàng và tìm max
    for (int i = 0; i < n; i++) {
        sums[i] = 0;
        for (int j = 0; j < n; j++) {
            sums[i] += a[i][j];
        }
        if (sums[i] > maxSum) {
            maxSum = sums[i];
        }
    }

    // In ra các hàng có tổng bằng max
    printf("Cac hang co tong lon nhat (%d):\n", maxSum);
    for (int i = 0; i < n; i++) {
        if (sums[i] == maxSum) {
            for (int j = 0; j < n; j++) {
                printf("%5d", a[i][j]);
            }
            printf("\n");
        }
    }

    free(sums);
}

// g. Menu
int Menu() {
    int chon;
    printf("\n===== MENU =====\n");
    printf("1. Nhap ma tran\n");
    printf("2. Xuat ma tran\n");
    printf("3. Kiem tra doi xung qua duong cheo phu\n");
    printf("4. Liet ke cac hang co tong lon nhat\n");
    printf("5. Thoat\n");
    printf("Chon: ");
    scanf("%d", &chon);
    return chon;
}

// main
int main() {
    int n = 0;
    int **a = NULL;
    int chon;

    do {
        chon = Menu();
        switch (chon) {
            case 1:
                if (a != NULL) {
                    XoaBN(n, a);
                }
                Nhap(&n, &a);
                break;
            case 2:
                if (a != NULL) {
                    Xuat(n, a);
                } else {
                    printf("Chua nhap ma tran.\n");
                }
                break;
            case 3:
                if (a != NULL) {
                    if (DoiXungPhu(n, a)) {
                        printf("Ma tran doi xung qua duong cheo phu.\n");
                    } else {
                        printf("Ma tran KHONG doi xung qua duong cheo phu.\n");
                    }
                } else {
                    printf("Chua nhap ma tran.\n");
                }
                break;
            case 4:
                if (a != NULL) {
                    LietKe(n, a);
                } else {
                    printf("Chua nhap ma tran.\n");
                }
                break;
            case 5:
                if (a != NULL) {
                    XoaBN(n, a);
                }
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (chon != 5);

    return 0;
}
