#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct giaCanh {
    char tenBa[50];
    char tenMe[50];
    int tuoiBa;
    int tuoiMe;
    char ngheNghiepBa[60];
    char ngheNghiepMe[60];
};

struct dsHocSinh {
    char ten[30];
    char truong[40];
    int lop;
    struct giaCanh *ttCaNhan;
};

int main() {
    int n;
    printf("Nhap so luong hoc sinh: ");
    scanf("%d", &n);
    getchar(); // Xóa '\n' sau scanf

    struct dsHocSinh *hS = (struct dsHocSinh *)malloc(n * sizeof(struct dsHocSinh));

    for (int i = 0; i < n; i++) {
        hS[i].ttCaNhan = (struct giaCanh *)malloc(sizeof(struct giaCanh));

        printf("\nHoc sinh thu %d\n", i + 1);

        printf("Nhap ten hoc sinh: ");
        fgets(hS[i].ten, sizeof(hS[i].ten), stdin);
        hS[i].ten[strcspn(hS[i].ten, "\n")] = 0;

        printf("Nhap ten truong: ");
        fgets(hS[i].truong, sizeof(hS[i].truong), stdin);
        hS[i].truong[strcspn(hS[i].truong, "\n")] = 0;

        printf("Nhap lop: ");
        scanf("%d", &hS[i].lop);
        getchar();

        printf("Nhap ten ba: ");
        fgets(hS[i].ttCaNhan->tenBa, sizeof(hS[i].ttCaNhan->tenBa), stdin);
        hS[i].ttCaNhan->tenBa[strcspn(hS[i].ttCaNhan->tenBa, "\n")] = 0;

        printf("Nhap tuoi ba: ");
        scanf("%d", &hS[i].ttCaNhan->tuoiBa);
        getchar();

        printf("Nhap nghe nghiep ba: ");
        fgets(hS[i].ttCaNhan->ngheNghiepBa, sizeof(hS[i].ttCaNhan->ngheNghiepBa), stdin);
        hS[i].ttCaNhan->ngheNghiepBa[strcspn(hS[i].ttCaNhan->ngheNghiepBa, "\n")] = 0;

        printf("Nhap ten me: ");
        fgets(hS[i].ttCaNhan->tenMe, sizeof(hS[i].ttCaNhan->tenMe), stdin);
        hS[i].ttCaNhan->tenMe[strcspn(hS[i].ttCaNhan->tenMe, "\n")] = 0;

        printf("Nhap tuoi me: ");
        scanf("%d", &hS[i].ttCaNhan->tuoiMe);
        getchar();

        printf("Nhap nghe nghiep me: ");
        fgets(hS[i].ttCaNhan->ngheNghiepMe, sizeof(hS[i].ttCaNhan->ngheNghiepMe), stdin);
        hS[i].ttCaNhan->ngheNghiepMe[strcspn(hS[i].ttCaNhan->ngheNghiepMe, "\n")] = 0;
    }

    printf("\n========== DANH SACH HOC SINH ==========\n");
    for (int i = 0; i < n; i++) {
        printf("\nHoc sinh thu %d", i + 1);
        printf("\nTen: %s", hS[i].ten);
        printf("\nTruong: %s", hS[i].truong);
        printf("\nLop: %d", hS[i].lop);

        printf("\n-- Thong tin gia dinh --");
        printf("\nTen ba: %s", hS[i].ttCaNhan->tenBa);
        printf("\nTuoi ba: %d", hS[i].ttCaNhan->tuoiBa);
        printf("\nNghe nghiep ba: %s", hS[i].ttCaNhan->ngheNghiepBa);

        printf("\nTen me: %s", hS[i].ttCaNhan->tenMe);
        printf("\nTuoi me: %d", hS[i].ttCaNhan->tuoiMe);
        printf("\nNghe nghiep me: %s", hS[i].ttCaNhan->ngheNghiepMe);
        printf("\n-------------------------------\n");
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < n; i++) {
        free(hS[i].ttCaNhan); // Giải phóng mỗi ttCaNhan
    }
    free(hS); // Giải phóng danh sách học sinh

    return 0;
}
