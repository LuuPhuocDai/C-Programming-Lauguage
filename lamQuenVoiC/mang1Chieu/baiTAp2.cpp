#include "stdio.h"
#include "math.h"


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
// ham dem so am trong mang
int HamDemSoAm(int a[], int n){
    int demSoAm = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < 0){
          demSoAm++;
        }
    }
    return demSoAm;
}
// ham dem tromg mang co bao nhieu cap tong = x
int hamCapTongX(int a[], int n, int x){
    int demCap = 0;
    for(int i = 0; i < n - 1; i++){
       for(int j = i + 1; j < n; j++){
        if(a[i] + a[j] == x){
            demCap++;
        }
       }
    }
    return demCap;
}
// ham Tim so nguyen to
int hamSNT( int n){
    if(n < 2)return 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return 0;// khong phai so nguyen to
        }
    }
    return 1;// la so nguyen to
}
// ham dem so nguyen to lon hon 10
int DemSoNT(int a[], int k, int n){
    int demSONTLonHon10 = 0;
    for(int i = 0; i < n; i++){
        if(hamSNT(a[i])  && a[i] > k){// no vua ktr so nguen to vua ktr xem so do lon hon k hay khong
            demSONTLonHon10++;
        }
    }
    return demSONTLonHon10;
}
// ham ktra trongn phan tu co thanh cap so nhan hhay khong
int hamCSN(int a[], int n){
    int i;
    if( n < 2 || a[0] == 0) return 0;
    double q = (double)a[1] / (double)a[0];
    for(i = 2; i < n; i++){
        if(a[i-1] == 0 || (double)a[i] / (double)a[i - 1] != q) return 0;
    }
    return 1;
}
// ham tim so hoan hao
int hamSHHao(int a[], int n){
    int dem = 0;
    for(int i = 0; i < n; i++){
        if(a[i] <= 0){
            continue;
        }
        else{
            int s = 0;
            for(int j = 1; j < a[i]; j++){
                if(a[i] % j == 0){
                    s += j;
                }
            }
            if(s == a[i]) dem++;
        }
    }
    return dem;
}


int main(){
    int a[101];
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    // nhap cac phan tu vao mang
    hamNhap(a, n);
    // in cac phan tu vua nhap ra
    printf("Cac phan tu vua nhap vao mang la:\n");
    hamIn(a, n);
    printf("\n-----------------------------------------------------------------\n");
    // dem trong day co bao nhieu so am
    int demSoAm = HamDemSoAm(a, n);
    printf("cac so am trong mang la: %d", demSoAm);
    printf("\n-----------------------------------------------------------------\n");
    // tim so nguyen to lon 10
    int k = 10;
    int TimSoNT = DemSoNT(a, k, n);
    printf("Cac so nguyen to lon hon 10 la: %d ", TimSoNT);
    printf("\n-----------------------------------------------------------------\n");
    // tim cap co tong bang x
    int x;
    printf("nhap x: ");
    scanf("%d", &x);
    int demCap1 = hamCapTongX(a, n, x);
    printf("Co %d cap co tong bang %d", demCap1, x);
    printf("\n-----------------------------------------------------------------\n");
    // ktra day so co tao thanh cap so nhan hay khong
    if(hamCSN(a, n) == 1){
        printf("mang co the tao thanh cap so nhan");
    }
    else{
        printf("mang khong the tao thanh cap so nhan");
    }
    printf("\n-----------------------------------------------------------------\n");
    // co may so hoan hao trong mang 
    int sohoanhao = hamSHHao(a, n);
    printf("co %d so hoan hao trong mang", sohoanhao);
    printf("\n-----------------------------------------------------------------\n");
   

    return 0;

}