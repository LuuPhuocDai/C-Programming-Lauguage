#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SinhVien {
    char mssv[20];
    char hoTen[100];
    float diem;
    struct SinhVien* next;
} SinhVien;

// H�m th�m sinh vi�n v�o danh s�ch
void themSV(SinhVien** head) {
    SinhVien* newSV = (SinhVien*)malloc(sizeof(SinhVien));
    printf("Nhap MSSV: ");
    scanf("%s", newSV->mssv);
    printf("Nhap ho ten: ");
    getchar(); // �? b? qua k� t? newline
    fgets(newSV->hoTen, 100, stdin);
    printf("Nhap diem: ");
    scanf("%f", &newSV->diem);

    newSV->next = *head;
    *head = newSV;
}

// H�m hi?n th? danh s�ch sinh vi�n
void hienthi(SinhVien* head) {
    SinhVien* temp = head;
    while (temp != NULL) {
        printf("MSSV: %s\n", temp->mssv);
        printf("Ho Ten: %s", temp->hoTen); // Ho t�n c� th? c� k� t? xu?ng d�ng
        printf("Diem: %.2f\n", temp->diem);
        temp = temp->next;
    }
}

// H�m t�ch danh s�ch sinh vi�n
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

// H�m s?p x?p danh s�ch theo di?m
void sapxepTheoDiem(SinhVien* head) {
    if (head == NULL || head->next == NULL) return;

    for (SinhVien* i = head; i != NULL; i = i->next) {
        for (SinhVien* j = i->next; j != NULL; j = j->next) {
            if (i->diem > j->diem) {
                // Ho�n d?i d? li?u gi?a i v� j
                SinhVien temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}

// H�m ghi danh s�ch ra file
void ghifile_txt(SinhVien* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    SinhVien* temp = head;
    while (temp != NULL) {
        fprintf(file, "MSSV: %s\n", temp->mssv);
        fprintf(file, "Ho Ten: %s", temp->hoTen); // Ho t�n c� th? c� k� t? xu?ng d�ng
        fprintf(file, "Diem: %.2f\n", temp->diem);
        temp = temp->next;
    }

    fclose(file);
}

// H�m t�nh t? l? d?t/kh�ng d?t
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

// H�m d?m s? lu?ng sinh vi�n trong danh s�ch
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

    // Th�m sinh vi�n v�o danh s�ch
    printf("Nhap danh sach sinh vien:\n");
    themSV(&head);
    themSV(&head);
    themSV(&head);

    // T�ch danh s�ch th�nh sinh vi�n d?t v� kh�ng d?t
    tachDanhSach(head, &dat, &khongdat);

    // S?p x?p danh s�ch theo di?m
    sapxepTheoDiem(dat);
    sapxepTheoDiem(khongdat);

    // T�nh t? l? v� in ra
    int tong = demSinhVien(head);
    tinhTyLe(dat, khongdat, tong);

    // Ghi k?t qu? ra file
    ghifile_txt(dat, "dat.txt");
    ghifile_txt(khongdat, "khongdat.txt");

    // Hi?n th? danh s�ch
    printf("\nDanh sach sinh vien dat:\n");
    hienthi(dat);
    printf("\nDanh sach sinh vien khong dat:\n");
    hienthi(khongdat);

    return 0;
}

