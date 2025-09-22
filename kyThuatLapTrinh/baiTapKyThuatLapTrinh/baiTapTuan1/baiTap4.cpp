#include "stdio.h"
#include "math.h" 

int main() {
    int n, i, j;
    float matrix[100][100], max, TichNhoNhat, sum = 0;             
    float colProd[100]; // mang chua tich cua tung cot     
    int TamGiacTren = 1, TamGiacDuoi = 1;

    
    printf("Nhap kich thuoc ma tran (n x n): ");// nhap kich thuoc cua ma tran
    scanf("%d", &n);


    printf("Nhap ma tran:\n");// nhap ma tran
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("matrix[%d][%d] = ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }

    
    for (i = 0; i < n; i++) {// tinh tong ma tran
        for (j = 0; j < n; j++) {
            sum += matrix[i][j];
        }
    }

    max = matrix[0][0];// tim gia tri lon nhat cua matr
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }


    for (j = 0; j < n; j++) {// tinh tich cac phan tu cua tung cot cua ma tran 
        colProd[j] = 1; 
        for (i = 0; i < n; i++) {
            colProd[j] *= matrix[i][j];
        }
    }

    TichNhoNhat = colProd[0];// tim cot co tich nho nhatt
    for (j = 1; j < n; j++) {
        if (colProd[j] < TichNhoNhat) {
            TichNhoNhat = colProd[j];
        }
    }

    // kiem tra ma tran tam giac
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i < j && matrix[i][j] != 0) { // Ktra mtr tren
                TamGiacTren = 0;
            }
            if (i > j && matrix[i][j] != 0) { // ktra matr duoi
                TamGiacDuoi = 0;
            }
        }
    }

    // in kqua
    printf("\ntong cac phan tu trong ma tran : %.2f", sum);
    printf("\ngia tri lon nhat trong ma tran: %.2f", max);
    printf("\ntinh cac phan tu cua tung cot:\n");
    for (j = 0; j < n; j++) {
        printf("cot %d: %.2f\n", j + 1, colProd[j]);
    }

    printf("\ntich nho nhat trong cac cot: %.2f", TichNhoNhat);

    if (TamGiacTren) {
        printf("\nMa tran la ma tran tam giac tren.");
    } else if (TamGiacDuoi) {
        printf("\nMa tran la ma tran tam giac duoi.");
    } else {
        printf("\nMa tran khong phai la ma tran tam giac.");
    }

    
}

