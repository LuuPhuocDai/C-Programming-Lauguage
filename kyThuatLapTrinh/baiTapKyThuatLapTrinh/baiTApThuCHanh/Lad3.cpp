#include "stdio.h"
#include "string.h"
#include "stdlib.h"


#define MAX_MON 100
#define MAX_BAN 5
#define MAX_DAT_MON 50

typedef struct {
    char ten[50];
    float gia;
} MonAn;

typedef struct {
    char tenMon[50];
    int soLuong;
} DatMon;

typedef struct {
    DatMon danhSachDatMon[MAX_DAT_MON];
    int soLuongMon;
} DonHang;

MonAn thucDon[MAX_MON];
int soLuongMonAn = 0;

DonHang ban[MAX_BAN];

int timMonAn(char ten[]) {
    for (int i = 0; i < soLuongMonAn; i++) {
        if (strcmp(thucDon[i].ten, ten) == 0)
            return i;
    }
    return -1;
}

void xoaDauXuongDong(char *s) {
    s[strcspn(s, "\n")] = '\0';
}

void themMonAn() {
    if (soLuongMonAn >= MAX_MON) {
        printf("⚠️  Thực đơn đã đầy.\n");
        return;
    }

    MonAn m;
    printf("Nhập tên món ăn: ");
    getchar(); 
    fgets(m.ten, sizeof(m.ten), stdin);
    xoaDauXuongDong(m.ten);

    if (timMonAn(m.ten) != -1) {
        printf("⚠️  Món '%s' đã có trong thực đơn.\n", m.ten);
        return;
    }

    printf("Nhập giá món ăn: ");
    if (scanf("%f", &m.gia) != 1 || m.gia <= 0) {
        printf("⚠️  Giá không hợp lệ.\n");
        while (getchar() != '\n'); 
        return;
    }

    thucDon[soLuongMonAn++] = m;
    printf("✅ Đã thêm món '%s' vào thực đơn.\n", m.ten);
}

void xemThucDon() {
    printf("\n📜 THỰC ĐƠN:\n");
    if (soLuongMonAn == 0) {
        printf("Không có món ăn nào.\n");
        return;
    }
    printf("%-3s | %-30s | %-10s\n", "STT", "Tên món", "Giá (VND)");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < soLuongMonAn; i++) {
        printf("%-3d | %-30s | %-10.2f\n", i + 1, thucDon[i].ten, thucDon[i].gia);
    }
}

void datMonChoBan() {
    int banSo;
    printf("Chọn bàn (1-5): ");
    if (scanf("%d", &banSo) != 1 || banSo < 1 || banSo > MAX_BAN) {
        printf("⚠️  Số bàn không hợp lệ.\n");
        while (getchar() != '\n');
        return;
    }

    DonHang *donHang = &ban[banSo - 1];
    char tenMon[50];
    int soLuong;

    while (1) {
        printf("Nhập tên món (hoặc 'x' để kết thúc): ");
        getchar();
        fgets(tenMon, sizeof(tenMon), stdin);
        xoaDauXuongDong(tenMon);

        if (strcmp(tenMon, "x") == 0) break;

        int viTri = timMonAn(tenMon);
        if (viTri == -1) {
            printf("⚠️  Món '%s' không tồn tại trong thực đơn.\n", tenMon);
            continue;
        }

        printf("Nhập số lượng: ");
        if (scanf("%d", &soLuong) != 1 || soLuong <= 0) {
            printf("⚠️  Số lượng không hợp lệ.\n");
            while (getchar() != '\n');
            continue;
        }

        int daTonTai = 0;
        for (int i = 0; i < donHang->soLuongMon; i++) {
            if (strcmp(donHang->danhSachDatMon[i].tenMon, tenMon) == 0) {
                donHang->danhSachDatMon[i].soLuong += soLuong;
                daTonTai = 1;
                break;
            }
        }

        if (!daTonTai && donHang->soLuongMon < MAX_DAT_MON) {
            strcpy(donHang->danhSachDatMon[donHang->soLuongMon].tenMon, tenMon);
            donHang->danhSachDatMon[donHang->soLuongMon].soLuong = soLuong;
            donHang->soLuongMon++;
        }

        printf("✅ Đã đặt món '%s' x%d cho bàn %d\n", tenMon, soLuong, banSo);
    }
}

void xemDonHangBan() {
    int banSo;
    printf("Nhập số bàn (1-5): ");
    if (scanf("%d", &banSo) != 1 || banSo < 1 || banSo > MAX_BAN) {
        printf("⚠️  Số bàn không hợp lệ.\n");
        while (getchar() != '\n');
        return;
    }

    DonHang *donHang = &ban[banSo - 1];
    if (donHang->soLuongMon == 0) {
        printf("📝 Bàn %d chưa có đơn hàng nào.\n", banSo);
        return;
    }

    float tongTien = 0;
    printf("\n🧾 ĐƠN HÀNG CỦA BÀN %d:\n", banSo);
    printf("%-3s | %-30s | %-10s | %-10s\n", "STT", "Tên món", "SL", "Thành tiền");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < donHang->soLuongMon; i++) {
        char *ten = donHang->danhSachDatMon[i].tenMon;
        int soLuong = donHang->danhSachDatMon[i].soLuong;
        int viTri = timMonAn(ten);
        if (viTri != -1) {
            float thanhTien = thucDon[viTri].gia * soLuong;
            printf("%-3d | %-30s | %-10d | %-10.2f\n", i + 1, ten, soLuong, thanhTien);
            tongTien += thanhTien;
        }
    }

    printf("---------------------------------------------------------------\n");
    printf("💰 TỔNG TIỀN: %.2f VND\n", tongTien);
}

void hienMenu() {
    printf("\n===== 📋 MENU CHÍNH =====\n");
    printf("1. ➕ Thêm món ăn vào thực đơn\n");
    printf("2. 📖 Xem thực đơn\n");
    printf("3. 🍽️  Đặt món cho bàn\n");
    printf("4. 🧾 Xem đơn hàng của bàn\n");
    printf("5. ❌ Thoát\n");
    printf("==========================\n");
    printf("Chọn chức năng (1-5): ");
}

int main() {
    int luaChon;
    do {
        hienMenu();
        if (scanf("%d", &luaChon) != 1) {
            printf("⚠️  Lựa chọn không hợp lệ.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (luaChon) {
            case 1: themMonAn(); break;
            case 2: xemThucDon(); break;
            case 3: datMonChoBan(); break;
            case 4: xemDonHangBan(); break;
            case 5: printf("👋 Thoát chương trình. Hẹn gặp lại!\n"); break;
            default: printf("⚠️  Vui lòng chọn từ 1 đến 5.\n");
        }
    } while (luaChon != 5);

    return 0;
}
