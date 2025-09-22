#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SinhVien {
    char mssv[10];
    char hoten[50];
    float diem;
    struct SinhVien* next;
} SinhVien;

SinhVien* head = NULL;

SinhVien* taoSinhVien(char mssv[], char hoten[], float diem) {
    SinhVien* sv = (SinhVien*)malloc(sizeof(SinhVien));
    if (!sv) {
        printf("Không đủ bộ nhớ!\n");
        exit(1);
    }
    strcpy(sv->mssv, mssv);
    strcpy(sv->hoten, hoten);
    sv->diem = diem;
    sv->next = NULL;
    return sv;
}

void themSinhVien(char mssv[], char hoten[], float diem) {
    SinhVien* sv = taoSinhVien(mssv, hoten, diem);

    if (head == NULL || strcmp(mssv, head->mssv) < 0) {
        sv->next = head;
        head = sv;
        return;
    }

    SinhVien* temp = head;
    while (temp->next != NULL && strcmp(temp->next->mssv, mssv) < 0) {
        temp = temp->next;
    }

    sv->next = temp->next;
    temp->next = sv;
}

void hienThiDanhSach() {
    if (head == NULL) {
        printf("Danh sách rỗng!\n");
        return;
    }

    printf("\n===== DANH SÁCH SINH VIÊN =====\n");
    SinhVien* temp = head;
    while (temp != NULL) {
        printf("MSSV: %-10s | Họ tên: %-30s | Điểm: %.2f\n",
               temp->mssv, temp->hoten, temp->diem);
        temp = temp->next;
    }
}

SinhVien* timTheoMSSV(char mssv[]) {
    SinhVien* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->mssv, mssv) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void xoaSinhVien(char mssv[]) {
    if (head == NULL) return;

    if (strcmp(head->mssv, mssv) == 0) {
        SinhVien* del = head;
        head = head->next;
        free(del);
        printf("Đã xóa sinh viên có MSSV %s.\n", mssv);
        return;
    }

    SinhVien* temp = head;
    while (temp->next != NULL && strcmp(temp->next->mssv, mssv) != 0) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        SinhVien* del = temp->next;
        temp->next = del->next;
        free(del);
        printf("Đã xóa sinh viên có MSSV %s.\n", mssv);
    } else {
        printf("Không tìm thấy sinh viên có MSSV %s.\n", mssv);
    }
}

void capNhatSinhVien(char mssv[]) {
    SinhVien* sv = timTheoMSSV(mssv);
    if (!sv) {
        printf("Không tìm thấy sinh viên.\n");
        return;
    }

    char hoten[50];
    float diem;
    printf("Tên cũ: %s | Nhập tên mới: ", sv->hoten);
    fgets(hoten, sizeof(hoten), stdin);
    hoten[strcspn(hoten, "\n")] = '\0';

    printf("Điểm cũ: %.2f | Nhập điểm mới: ", sv->diem);
    scanf("%f", &diem); getchar();

    strcpy(sv->hoten, hoten);
    sv->diem = diem;
    printf("Đã cập nhật sinh viên MSSV %s.\n", mssv);
}

void timDiemCaoNhat() {
    if (head == NULL) {
        printf("Danh sách rỗng!\n");
        return;
    }

    float max = head->diem;
    SinhVien* temp = head->next;
    while (temp != NULL) {
        if (temp->diem > max)
            max = temp->diem;
        temp = temp->next;
    }

    printf("\nSinh viên có điểm cao nhất (%.2f):\n", max);
    temp = head;
    while (temp != NULL) {
        if (temp->diem == max)
            printf("MSSV: %s | Họ tên: %s\n", temp->mssv, temp->hoten);
        temp = temp->next;
    }
}

void timTheoKhoangDiem(float min, float max) {
    if (head == NULL) {
        printf("Danh sách rỗng!\n");
        return;
    }

    printf("Sinh viên có điểm từ %.2f đến %.2f:\n", min, max);
    SinhVien* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (temp->diem >= min && temp->diem <= max) {
            printf("MSSV: %s | Họ tên: %s | Điểm: %.2f\n", temp->mssv, temp->hoten, temp->diem);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found)
        printf("Không có sinh viên nào trong khoảng này.\n");
}

void ghiFile(const char* filename) {
    FILE* f = fopen(filename, "w");
    if (!f) {
        printf("Không mở được file để ghi!\n");
        return;
    }

    SinhVien* temp = head;
    while (temp != NULL) {
        fprintf(f, "%s;%s;%.2f\n", temp->mssv, temp->hoten, temp->diem);
        temp = temp->next;
    }
    fclose(f);
    printf("Đã ghi dữ liệu ra file %s\n", filename);
}

void docFile(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        printf("Không mở được file để đọc!\n");
        return;
    }

    char line[100], mssv[10], hoten[50];
    float diem;
    while (fgets(line, sizeof(line), f)) {
        if (sscanf(line, "%[^;];%[^;];%f", mssv, hoten, &diem) == 3) {
            themSinhVien(mssv, hoten, diem);
        }
    }

    fclose(f);
    printf("Đã đọc dữ liệu từ file %s\n", filename);
}

void giaiPhongDanhSach() {
    SinhVien* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void menu() {
    int ch;
    char mssv[10], hoten[50];
    float diem, min, max;

    do {
        printf("\n=========== MENU ===========\n");
        printf("1. Thêm sinh viên\n");
        printf("2. Hiển thị danh sách\n");
        printf("3. Tìm theo MSSV\n");
        printf("4. Xóa sinh viên\n");
        printf("5. Cập nhật thông tin\n");
        printf("6. Tìm điểm cao nhất\n");
        printf("7. Tìm theo khoảng điểm\n");
        printf("8. Ghi ra file (sinhvien.txt)\n");
        printf("9. Đọc từ file (sinhvien.txt)\n");
        printf("0. Thoát\n");
        printf("Chọn: ");
        scanf("%d", &ch); getchar();

        switch (ch) {
            case 1:
                printf("Nhập MSSV: "); fgets(mssv, sizeof(mssv), stdin); mssv[strcspn(mssv, "\n")] = '\0';
                printf("Nhập Họ tên: "); fgets(hoten, sizeof(hoten), stdin); hoten[strcspn(hoten, "\n")] = '\0';
                printf("Nhập Điểm: "); scanf("%f", &diem); getchar();
                themSinhVien(mssv, hoten, diem);
                break;
            case 2:
                hienThiDanhSach(); break;
            case 3:
                printf("Nhập MSSV cần tìm: "); fgets(mssv, sizeof(mssv), stdin); mssv[strcspn(mssv, "\n")] = '\0';
                {
                    SinhVien* sv = timTheoMSSV(mssv);
                    if (sv)
                        printf("Tìm thấy: %s | %s | %.2f\n", sv->mssv, sv->hoten, sv->diem);
                    else
                        printf("Không tìm thấy sinh viên.\n");
                }
                break;
            case 4:
                printf("Nhập MSSV cần xóa: "); fgets(mssv, sizeof(mssv), stdin); mssv[strcspn(mssv, "\n")] = '\0';
                xoaSinhVien(mssv);
                break;
            case 5:
                printf("Nhập MSSV cần cập nhật: "); fgets(mssv, sizeof(mssv), stdin); mssv[strcspn(mssv, "\n")] = '\0';
                capNhatSinhVien(mssv);
                break;
            case 6:
                timDiemCaoNhat(); break;
            case 7:
                printf("Nhập khoảng điểm (min max): "); scanf("%f %f", &min, &max); getchar();
                if (min > max) { float t = min; min = max; max = t; }
                timTheoKhoangDiem(min, max);
                break;
            case 8:
                ghiFile("sinhvien.txt"); break;
            case 9:
                docFile("sinhvien.txt"); break;
            case 0:
                giaiPhongDanhSach();
                printf("Đã thoát chương trình.\n"); break;
            default:
                printf("Lựa chọn không hợp lệ!\n");
        }
    } while (ch != 0);
}

int main() {
    menu();
    return 0;
}
