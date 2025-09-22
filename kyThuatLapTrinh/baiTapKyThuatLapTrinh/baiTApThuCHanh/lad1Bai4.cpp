#include "stdio.h"
#include "stdlib.h"

// Định nghĩa cấu trúc Node
typedef struct Node {
    int Item;
    struct Node *Next;
} Node;

// Hàm tạo Node mới
Node* TaoMoi(int x) {
    Node *p = (Node*)malloc(sizeof(Node));
    if (p == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    p->Item = x;
    p->Next = NULL;
    return p;
}

// Hàm thêm vào đầu danh sách
Node* ThemDau(Node *H, int x) {
    Node *p = TaoMoi(x);
    p->Next = H;
    return p;
}

// Hàm thêm vào cuối danh sách
void ThemCuoi(Node **H, int x) {
    Node *p = TaoMoi(x);
    if (*H == NULL) {
        *H = p;
    } else {
        Node *q = *H;
        while (q->Next != NULL)
            q = q->Next;
        q->Next = p;
    }
}

// Hàm tạo danh sách kiểu LIFO (Stack)
void LIFO(Node **H) {
    int x;
    printf("Nhap x (0 de dung): ");
    while (1) {
        scanf("%d", &x);
        if (x == 0) break;
        *H = ThemDau(*H, x);
    }
}

// Hàm tạo danh sách kiểu FIFO
void FIFO(Node **H) {
    int n, x;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &x);
        ThemCuoi(H, x);
    }
}

// Hàm xuất danh sách ra màn hình
void Xuat(Node *H) {
    if (H == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    Node *p = H;
    while (p != NULL) {
        printf("%d ", p->Item);
        p = p->Next;
    }
    printf("\n");
}

// Hàm xóa một giá trị x khỏi danh sách
void Xoa(Node **H, int x) {
    Node *p = *H, *prev = NULL;
    while (p != NULL) {
        if (p->Item == x) {
            if (prev == NULL) {
                *H = p->Next;
            } else {
                prev->Next = p->Next;
            }
            free(p);
            printf("Da xoa %d\n", x);
            return;
        }
        prev = p;
        p = p->Next;
    }
    printf("Khong tim thay %d trong danh sach\n", x);
}

// Hàm thực hiện menu
int Menu() {
    int choice;
    printf("\n1. Tao DS LIFO\n");
    printf("2. Tao DS FIFO\n");
    printf("3. Xuat DS LIFO\n");
    printf("4. Xuat DS FIFO\n");
    printf("5. Nhap x va xoa x ra khoi DS LIFO\n");
    printf("6. Noi DS FIFO vao DS LIFO\n");
    printf("7. Thoat\n");
    printf("Nhap lua chon: ");
    scanf("%d", &choice);
    return choice;
}

// Hàm main thực hiện các thao tác
int main() {
    Node *LIFOList = NULL, *FIFOList = NULL;
    int choice, x;
    
    do {
        choice = Menu();
        switch (choice) {
            case 1:
                LIFO(&LIFOList);
                break;
            case 2:
                FIFO(&FIFOList);
                break;
            case 3:
                printf("Danh sach LIFO: ");
                Xuat(LIFOList);
                break;
            case 4:
                printf("Danh sach FIFO: ");
                Xuat(FIFOList);
                break;
            case 5:
                printf("Nhap gia tri x de xoa: ");
                scanf("%d", &x);
                Xoa(&LIFOList, x);
                break;
            case 6:
                if (FIFOList != NULL) {
                    Node *q = FIFOList;
                    while (q != NULL) {
                        ThemCuoi(&LIFOList, q->Item);
                        q = q->Next;
                    }
                    FIFOList = NULL; // Xóa FIFOList sau khi đã nối vào LIFO
                }
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 7);
    
    return 0;
}
