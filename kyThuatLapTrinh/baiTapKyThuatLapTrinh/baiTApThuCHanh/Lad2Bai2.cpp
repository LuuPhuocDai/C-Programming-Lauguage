#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SinhVien {
    char mssv[20];
    char hoTen[100];
    float diem;
    struct SinhVien* next;
} SinhVien;

// Hàm loại bỏ ký tự '\n' cuối chuỗi
void xoaXuongDong(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n')
        str[len-1] = '\0';
}

// Thêm sinh viên
void themSV(SinhVien** head) {
    SinhVien* newSV = (SinhVien*)malloc(sizeof(SinhVien));
    if (!newSV) {
        printf("Khong du bo nho.\n");
        return;
    }

    printf("Nhap MSSV: ");
    fgets(newSV->mssv, sizeof(newSV->mssv), stdin);
    xoaXuongDong(newSV->mssv);

    printf("Nhap ho ten: ");
    fgets(newSV->hoTen, sizeof(newSV->hoTen), stdin);
    xoaXuongDong(newSV->hoTen);

    printf("Nhap diem: ");
    while (scanf("%f", &newSV->diem) != 1 || newSV->diem < 0 || newSV->diem > 10) {
        printf("Diem khong hop le (0-10). Nhap lai: ");
        while (getchar() != '\n'); // Xóa bộ đệm
    }
    while (getchar() != '\n'); // Xóa '\n' sau scanf

    newSV->next = *head;
    *head = newSV;
}

// Hiển thị danh sách
void hienthi(SinhVien* head) {
    while (head) {
        printf("MSSV: %s\n", head->mssv);
        printf("Ho Ten: %s\n", head->hoTen);
        printf("Diem: %.2f\n", head->diem);
        head = head->next;
    }
}

// Tách danh sách
void tachDanhSach(SinhVien* head, SinhVien** dat, SinhVien** khongdat) {
    while (head) {
        SinhVien* newSV = (SinhVien*)malloc(sizeof(SinhVien));
        *newSV = *head; // Copy toàn bộ nội dung
        newSV->next = NULL;

        if (head->diem < 5.0) {
            newSV->next = *khongdat;
            *khongdat = newSV;
        } else {
            newSV->next = *dat;
            *dat = newSV;
        }

        head = head->next;
    }
}

// Sắp xếp tăng dần theo điểm
void sapxepTheoDiem(SinhVien* head) {
    for (SinhVien* i = head; i && i->next; i = i->next) {
        for (SinhVien* j = i->next; j; j = j->next) {
            if (i->diem > j->diem) {
                // Hoán đổi dữ liệu
                SinhVien temp = *i;
                *i = *j;
                *j = temp;

                // Đảm bảo liên kết không bị sai
                SinhVien* tmpNext = i->next;
                i->next = j->next;
                j->next = tmpNext;

                // Hoán đổi lại node.next sau hoán giá trị
                SinhVien tempNode = *i;
                *i = *j;
                *j = tempNode;
            }
        }
    }
}

// Ghi ra file
void ghifile_txt(SinhVien* head, const char* filename) {
    FILE* f = fopen(filename, "w");
    if (!f) {
        printf("Khong mo duoc file %s\n", filename);
        return;
    }
    while (head) {
        fprintf(f, "MSSV: %s\n", head->mssv);
        fprintf(f, "Ho Ten: %s\n", head->hoTen);
        fprintf(f, "Diem: %.2f\n", head->diem);
        head = head->next;
    }
    fclose(f);
}

// Đếm số lượng sinh viên
int dem(SinhVien* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Tính tỷ lệ
void tinhTyLe(SinhVien* dat, SinhVien* khongdat, int tong) {
    int d = dem(dat);
    int k = dem(khongdat);
    printf("Ty le dat: %.2f%%\n", (float)d / tong * 100);
    printf("Ty le khong dat: %.2f%%\n", (float)k / tong * 100);
}

int main() {
    SinhVien* ds = NULL;
    SinhVien* dat = NULL;
    SinhVien* khongdat = NULL;
    int n;

    printf("Nhap so sinh vien: ");
    scanf("%d", &n);
    while (getchar() != '\n'); // Xóa bộ đệm

    for (int i = 0; i < n; i++) {
        printf("\n== Nhap sinh vien %d ==\n", i + 1);
        themSV(&ds);
    }

    tachDanhSach(ds, &dat, &khongdat);
    sapxepTheoDiem(dat);
    sapxepTheoDiem(khongdat);

    printf("\n-- Danh sach dat --\n");
    hienthi(dat);
    printf("\n-- Danh sach khong dat --\n");
    hienthi(khongdat);

    ghifile_txt(dat, "dat.txt");
    ghifile_txt(khongdat, "khongdat.txt");

    tinhTyLe(dat, khongdat, n);

    return 0;
}
