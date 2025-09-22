#include "stdio.h"
#include "math.h"
#include "limits.h"

// ham nhap
void hamNhap(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("A[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

// ham in 
void hamIn(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
        if((i + 1) % 10 == 0){
            printf("\n");
        }
    }
}

// ham max min 
int max(int a[], int n){
    int max = a[0];
    for(int i = 1; i < n; i++){
        if(max < a[i]){
            max = a[i];
        }
    }
    return max;
}
int min(int a[], int n){
    int min = a[0];
    for(int i = 1; i < n; i++){
        if(min > a[i]){
            min = a[i];
        }
    }
    return min;
}

// ham sap xep tang dan (bubble sort)
void hamSXTang(int a[], int n){
    int kgian = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(a[j] > a[j + 1]){
                kgian = a[j];
                a[j] = a[j + 1];
                a[j + 1] = kgian;
            }
        }
    }
}

// ham sap xep giam dan (insertion sort)
void hamSXGiam(int a[], int n){
    int banDau = 0;
    for(int i = 1; i < n; i++){
        banDau = a[i];
       int j = i - 1;
        while(j >= 0 && banDau > a[j]){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = banDau;
    }
}

// ham tim so duong
void Tongduong(int a[], int n){
    int s = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > 0){
            s += a[i];
        }
    }
    printf("%d ", s);
}

// ham dem so duong 
int demDuong(int a[], int n){
    int dem = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > 0) dem++;
    }
    return dem; // cac so duong trong mang
}

// ham in ra so duong nho nhat
int hamDuongMin(int a[], int n){
    int duongMin = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > 0){
            duongMin = i;
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i] > 0 && a[duongMin] > a[i]){
            duongMin = i;
        }
    }
    return duongMin;
}

// ham tim so am lon nhat 
int hamAmMax(int a[], int n){
    int amMax = -1;
    for(int i = 0; i < n; i++){
        if(a[i] < 0){
            amMax = i;
            break;
        }
    }
    if( amMax == -1) return -1;// khong co gia tri am nao trong mang

    for(int i = amMax + 1; i < n; i++){
        if(a[i] < 0 && a[amMax] < a[i]){
            amMax = i;
        }
    }
    return amMax;
}

// ham in ra cac phan tu ma lap lai nhieu nhat 
void hamTimSoLapLaiNhieuLan(int a[], int n){
    int dem = 1, max = 1;
    int demCacPhanTuTrung = 0;
    int kqua[100];
    hamSXTang(a, n);
    for(int i = 1; i < n ; i++){
        if(a[i] == a[i - 1]){
            dem++;
        }
        else{
            if(dem > max){
                max = dem;
                kqua[0] = a[i - 1];
                demCacPhanTuTrung = 1;
            }
            else if(max == dem){
                kqua[demCacPhanTuTrung++] = a[i - 1];
            }
            dem = 1;
        }
    }
    if(dem > max){
        max = dem;
        kqua[0] = a[n - 1];
        demCacPhanTuTrung = 1;
    }
    else if( max == dem ){
        kqua[demCacPhanTuTrung++] = a[n - 1];
    }
    // in phan tu 
    if(max < 2){
        printf("khong co phan tu nao lap lai");
    }
    else{
        printf("co %d phan tu xuat hien nhieu nhat la (xuat hien %d lan): ", demCacPhanTuTrung, max);
        for(int i = 0; i < demCacPhanTuTrung; i++){
            printf("%d ", kqua[i]);
        }
    }
}

// ham tim phan tu lon thu nhi cua mang 
void hamNhiMax(int a[], int n){
   int max1 = max(a, n);
   int nhiMax = INT_MIN;
   int soLan = 0;
   int vitri = -1;
    for(int i = 0; i < n; i++){
        if(a[i] != max1 && nhiMax < a[i]){
            nhiMax = a[i];
            soLan = 1;
            vitri = i;
        }
    }
    if(soLan){
        printf("so lan thu hai cua mang la %d va o vi tri A[%d]", nhiMax, vitri);
    }
    else{
        printf("khong co so lon thu hai trong mang ");
    }
}

// ham tim so duong lien tiep nhieu nhat trong mang
void hamTimDuongLT(int a[], int n){
    int dem = 0, max = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > 0){
            dem++;
            if(dem > max){
                max = dem;
            }
        }
        else{
            dem = 0;
        }
    }
    if(max > 1){
        printf("So duong lien tiep trong mang nhieu nhat la %d ", max);
    }
    else{
        printf("khong co so duong lien tiep trong mang");
    }
}

// ham tim tong duong lien tiep lon nhat trong mang
void hamTongDuongLT(int a[], int n){
    int s = 0, max = 0;
    int dem = 0;
    int dem2 = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > 0){
            s += a[i];
            dem++;
            if(max < s && dem > 1){
                max = s;
                dem2 = dem;
            }
        }
        else{
            s = 0;
            dem = 0;
        }
    }
    if(dem2 > 1){
        printf("Tong so duong lien tiep lon nhat la: %d", max);
    }else{
        printf("vi trong mang khong co so duong lien tiep nao nen khong tinh duoc");
    }
}

// ham tong so am lien tiep lon nhat trong mang 
void hamTongAmLT(int a[], int n){
    int s = 0;
    int dem = 0 ;
    int max = INT_MIN;
    int dem2 = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < 0){
            s += a[i];
            dem++;
            if(max < s && dem > 1 ){
                max = s;
                dem2 = dem;
            }
        }
        else{
            s = 0;
            dem = 0;
        }
    }
    if(dem2 > 1){
        printf("Tong so am lien tiep lon nhat trong mang la: %d", max);
    }
    else{
        printf("ham khong co so am lien tiep nao trong mang nen khong tinh duoc!!!");
    }
}
// ham doi so am xuong duoi 
void hamDOi(int a[], int n){
    int phai = n - 1, trai = 0, tg = 0;
    while(trai < phai){
        if(a[trai] < 0 && a[phai] > 0){
            tg = a[phai];
            a[phai] = a[trai];
            a[trai] = tg;
            trai++;
            phai--; 
        }
        if(a[trai] > 0){
            trai++;
        }
    }
    puts("mang sau khi chuyen het so duong len dau la: ");
    hamIn(a, n);
}



// chuong trinh chinh
int main(){
    int a[101], b[101];
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    // nhap ham
    hamNhap(a, n); 
    for(int i = 0; i < n; i ++){// luu gia tri ban dau
        b[i] = a[i];
    }
    // in ham 
    puts("cac phan tu vua nhap vao mang la:");
    hamIn(a, n);
    printf("\n------------------------------------------------------------------------\n");

    // Tìm phần tử có tần suất xuất hiện nhiều nhất trong mảng và xuất hiện bao nhiêu lần
    hamTimSoLapLaiNhieuLan(a, n);
    printf("\n------------------------------------------------------------------------\n");

    // max min trong mang
    int max1 = max(a, n);
    printf("gia tri lon nhat trong mang la: %d", max1);
    int min1 = min(a, n);
    printf("\ngia tri nho nhat trong mang la: %d", min1);
    printf("\n------------------------------------------------------------------------\n");

    // Nhập vào một mảng và in ra số lượng các số dương và tổng của các số dương
    int demDuong1 = demDuong(a, n);
    printf("co %d phan tu duong trong mang va tong cua chung bang: ", demDuong1);
    Tongduong(a, n);
    printf("\n------------------------------------------------------------------------\n");

    // tìm số hạng âm lớn nhất của mảng và chỉ số của nó
    int soAm1 = hamAmMax(b, n);
    if(soAm1 == -1 ){
        printf("trong mang khong phan tu nao la so am ");
    }
    else{
        printf("so am lon nhat trong mang la %d va no o vi tri A[%d]", b[soAm1], soAm1);
    }
    printf("\n------------------------------------------------------------------------\n");

    // tim so hang duong nn
    int duongMin1 = hamDuongMin(b, n);
    printf("so duong nho nhat trong mang la %d vs o vi tri A[%d]", b[duongMin1], duongMin1);
    printf("\n------------------------------------------------------------------------\n");

    // tim so lon thu hai trong mang
    hamNhiMax(b, n);
    printf("\n------------------------------------------------------------------------\n");

    // hàm sắp xếp tăng dần, giảm dần của một mảng số nguyên cho trước.
    hamSXTang(a, n);
    printf("ham dc sap xep tang dan:\n");
    hamIn(a, n);
    hamSXGiam(a, n);
    printf("\nham dc sap xep giam dan la:\n");
    hamIn(a, n);
    printf("\n------------------------------------------------------------------------\n");

    // tìm số lượng các số dương liên tiếp nhiều nhất.
    hamTimDuongLT(b, n);
    printf("\n------------------------------------------------------------------------\n");

    //tìm số lượng các số hạng dương liên tiếp có tổng lớn nhất.
    hamTongDuongLT(b, n);
    printf("\n------------------------------------------------------------------------\n");
 
    // tim so am lien tiep lon nhat trong mang
    hamTongAmLT(b, n);
    printf("\n------------------------------------------------------------------------\n");

    // doi so duong len dau 
    hamDOi(b, n);
    printf("\n------------------------------------------------------------------------\n");


    return 0;
}