#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SinhVien {
    char mssv[20];
    char hoTen[100];
    float diem;
    struct SinhVien* next;
} SinhVien;

// Hàm thêm sinh viên vào danh sách
void themSV(SinhVien** head) {
    SinhVien* newSV = (SinhVien*)malloc(sizeof(SinhVien));
    printf("Nhap MSSV: ");
    scanf("%s", newSV->mssv);
    printf("Nhap ho ten: ");
    getchar(); // Ð? b? qua ký t? newline
    fgets(newSV->hoTen, 100, stdin);
    printf("Nhap diem: ");
    scanf("%f", &newSV->diem);

    newSV->next = *head;
    *head = newSV;
}

// Hàm hi?n th? danh sách sinh viên
void hienthi(SinhVien* head) {
    SinhVien* temp = head;
    while (temp != NULL) {
        printf("MSSV: %s\n", temp->mssv);
        printf("Ho Ten: %s", temp->hoTen); // Ho tên có th? có ký t? xu?ng dòng
        printf("Diem: %.2f\n", temp->diem);
        temp = temp->next;
    }
}

// Hàm tách danh sách sinh viên
void tachDanhSach(SinhVien* head, SinhVien** dat, SinhVien** khongdat) {
    SinhVien* temp = head;
    while (temp != NULL) {
        SinhVien* newSV = (SinhVien*)malloc(sizeof(SinhVien));
        strcpy(newSV->mssv, temp->mssv);
        strcpy(newSV->hoTen, temp->hoTen);
        newSV->diem = temp->diem;
        newSV->next = NULL;

        if (temp->diem < 5.0) {
            newSV->next = *khongdat;
            *khongdat = newSV;
        } else {
            newSV->next = *dat;
            *dat = newSV;
        }
        temp = temp->next;
    }
}

// Hàm s?p x?p danh sách theo di?m
void sapxepTheoDiem(SinhVien* head) {
    if (head == NULL || head->next == NULL) return;

    for (SinhVien* i = head; i != NULL; i = i->next) {
        for (SinhVien* j = i->next; j != NULL; j = j->next) {
            if (i->diem > j->diem) {
                // Hoán d?i d? li?u gi?a i và j
                SinhVien temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}

// Hàm ghi danh sách ra file
void ghifile_txt(SinhVien* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    SinhVien* temp = head;
    while (temp != NULL) {
        fprintf(file, "MSSV: %s\n", temp->mssv);
        fprintf(file, "Ho Ten: %s", temp->hoTen); // Ho tên có th? có ký t? xu?ng dòng
        fprintf(file, "Diem: %.2f\n", temp->diem);
        temp = temp->next;
    }

    fclose(file);
}

// Hàm tính t? l? d?t/không d?t
void tinhTyLe(SinhVien* dat, SinhVien* khongdat, int tong) {
    int datCount = 0, khongdatCount = 0;
    SinhVien* temp = dat;
    while (temp != NULL) {
        datCount++;
        temp = temp->next;
    }

    temp = khongdat;
    while (temp != NULL) {
        khongdatCount++;
        temp = temp->next;
    }

    float tyLeDat = (float)datCount / tong * 100.0;
    float tyLeKhongDat = (float)khongdatCount / tong * 100.0;

    printf("Ty le sinh vien dat: %.2f%%\n", tyLeDat);
    printf("Ty le sinh vien khong dat: %.2f%%\n", tyLeKhongDat);
}

// Hàm d?m s? lu?ng sinh viên trong danh sách
int demSinhVien(SinhVien* head) {
    int count = 0;
    SinhVien* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    SinhVien* head = NULL;
    SinhVien* dat = NULL;
    SinhVien* khongdat = NULL;

    // Thêm sinh viên vào danh sách
    printf("Nhap danh sach sinh vien:\n");
    themSV(&head);
    themSV(&head);
    themSV(&head);

    // Tách danh sách thành sinh viên d?t và không d?t
    tachDanhSach(head, &dat, &khongdat);

    // S?p x?p danh sách theo di?m
    sapxepTheoDiem(dat);
    sapxepTheoDiem(khongdat);

    // Tính t? l? và in ra
    int tong = demSinhVien(head);
    tinhTyLe(dat, khongdat, tong);

    // Ghi k?t qu? ra file
    ghifile_txt(dat, "dat.txt");
    ghifile_txt(khongdat, "khongdat.txt");

    // Hi?n th? danh sách
    printf("\nDanh sach sinh vien dat:\n");
    hienthi(dat);
    printf("\nDanh sach sinh vien khong dat:\n");
    hienthi(khongdat);

    return 0;
}

