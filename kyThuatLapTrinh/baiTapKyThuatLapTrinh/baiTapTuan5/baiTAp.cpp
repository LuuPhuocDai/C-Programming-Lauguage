#include <stdio.h>
#include <stdlib.h>

// Định nghĩa struct phân số
typedef struct {
    int tu;    // Tử số
    int mau;   // Mẫu số
} PhanSo;

// Hàm tính UCLN
int UCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Hàm tính BCNN
int BCNN(int a, int b) {
    return abs(a * b) / UCLN(a, b);
}

// Hàm rút gọn phân số
void rutGon(PhanSo *ps) {
    int ucln = UCLN(ps->tu, ps->mau);
    ps->tu /= ucln;
    ps->mau /= ucln;
    if (ps->mau < 0) {
        ps->tu = -ps->tu;
        ps->mau = -ps->mau;
    }
}

// 1. Nhập phân số
void nhapPhanSo(PhanSo *ps) {
    printf("Nhap tu so: ");
    scanf("%d", &ps->tu);
    do {
        printf("Nhap mau so (khac 0): ");
        scanf("%d", &ps->mau);
    } while (ps->mau == 0);
}

// Nhập dãy phân số
void nhapDayPhanSo(PhanSo *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nNhap phan so thu %d:\n", i + 1);
        nhapPhanSo(&arr[i]);
    }
}

// 2. In phân số
void inPhanSo(PhanSo ps) {
    printf("%d/%d", ps.tu, ps.mau);
}

// In dãy phân số
void inDayPhanSo(PhanSo *arr, int n) {
    for (int i = 0; i < n; i++) {
        inPhanSo(arr[i]);
        printf("  ");
    }
    printf("\n");
}

// 6. Cộng 2 phân số
PhanSo congPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketqua;
    ketqua.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    ketqua.mau = ps1.mau * ps2.mau;
    rutGon(&ketqua);
    return ketqua;
}

// 7. Trừ 2 phân số
PhanSo truPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketqua;
    ketqua.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    ketqua.mau = ps1.mau * ps2.mau;
    rutGon(&ketqua);
    return ketqua;
}

// 8. Nhân 2 phân số
PhanSo nhanPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketqua;
    ketqua.tu = ps1.tu * ps2.tu;
    ketqua.mau = ps1.mau * ps2.mau;
    rutGon(&ketqua);
    return ketqua;
}

// 9. Chia 2 phân số
PhanSo chiaPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketqua;
    ketqua.tu = ps1.tu * ps2.mau;
    ketqua.mau = ps1.mau * ps2.tu;
    rutGon(&ketqua);
    return ketqua;
}

// 10. So sánh 2 phân số (trả về -1 nếu ps1 < ps2, 0 nếu ps1 = ps2, 1 nếu ps1 > ps2)
int soSanhPhanSo(PhanSo ps1, PhanSo ps2) {
    int tich1 = ps1.tu * ps2.mau;
    int tich2 = ps2.tu * ps1.mau;
    if (tich1 < tich2) return -1;
    if (tich1 > tich2) return 1;
    return 0;
}

// 11. Tìm phân số lớn nhất
PhanSo timMax(PhanSo *arr, int n) {
    PhanSo max = arr[0];
    for (int i = 1; i < n; i++) {
        if (soSanhPhanSo(arr[i], max) == 1) {
            max = arr[i];
        }
    }
    return max;
}

// 12. Tìm kiếm phân số
int timPhanSo(PhanSo *arr, int n, PhanSo x) {
    for (int i = 0; i < n; i++) {
        if (soSanhPhanSo(arr[i], x) == 0) {
            return i;
        }
    }
    return -1;
}

// 13. Sắp xếp dãy phân số (tăng dần)
void sapXep(PhanSo *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (soSanhPhanSo(arr[i], arr[j]) == 1) {
                PhanSo temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// 14. Tính tổng dãy phân số
PhanSo tongDayPhanSo(PhanSo *arr, int n) {
    PhanSo tong = arr[0];
    for (int i = 1; i < n; i++) {
        tong = congPhanSo(tong, arr[i]);
    }
    return tong;
}

int main() {
    int n;
    printf("Nhap so luong phan so: ");
    scanf("%d", &n);
    
    // Cấp phát động mảng phân số
    PhanSo *arr = (PhanSo*)malloc(n * sizeof(PhanSo));
    
    // 1. Nhập dãy phân số
    nhapDayPhanSo(arr, n);
    
    // 2. In dãy phân số
    printf("\nDay phan so: ");
    inDayPhanSo(arr, n);
    
    // 3. UCLN của phân số đầu tiên
    printf("\nUCLN cua phan so dau tien: %d\n", UCLN(arr[0].tu, arr[0].mau));
    
    // 4. BCNN của 2 phân số đầu tiên
    if (n >= 2) {
        printf("BCNN cua 2 phan so dau tien: %d\n", BCNN(arr[0].mau, arr[1].mau));
    }
    
    // 5. Rút gọn phân số đầu tiên
    printf("Phan so dau tien sau khi rut gon: ");
    rutGon(&arr[0]);
    inPhanSo(arr[0]);
    printf("\n");
    
    // 6-9. Các phép toán
    if (n >= 2) {
        printf("Cong 2 phan so dau: ");
        inPhanSo(congPhanSo(arr[0], arr[1]));
        printf("\nTru 2 phan so dau: ");
        inPhanSo(truPhanSo(arr[0], arr[1]));
        printf("\nNhan 2 phan so dau: ");
        inPhanSo(nhanPhanSo(arr[0], arr[1]));
        printf("\nChia 2 phan so dau: ");
        inPhanSo(chiaPhanSo(arr[0], arr[1]));
        printf("\n");
    }
    
    // 11. Tìm max
    printf("Phan so lon nhat: ");
    inPhanSo(timMax(arr, n));
    printf("\n");
    
    // 13. Sắp xếp
    sapXep(arr, n);
    printf("Day sau khi sap xep: ");
    inDayPhanSo(arr, n);
    
    // 14. Tổng dãy
    printf("Tong day phan so: ");
    inPhanSo(tongDayPhanSo(arr, n));
    printf("\n");
    
    free(arr);
    return 0;
}