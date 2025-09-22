#include "stdio.h"
#include "math.h"

// ham Kiểm tra dãy có bao nhiêu cặp số mà số sau bằng tổng 2 số trước
int cap(int a[], int n){
    int i, temp = 0;
    int cap = 0;
    for(i = 0; i < n - 2; i++){
        temp = a[i] + a[i + 1];
        if(temp == a[i + 2]) cap++;
    }
    return cap;
}
// ham them phan tu vao mang
int hamThem(int a[], int x, int k, int n){
	for(int i = n; i > k; i--){
		a[i] = a[i - 1];
	}
	a[k] = x;
    return n + 1;
}
// ham xoa phan tu trong mang
int hamXoa(int a[], int k, int n){
	for(int i = k; i < n - 1; i++){
		a[i] = a[i + 1];
	}
	return n - 1;
}

// ham dao
void hamDao(int a[],  int n){
    int khGian = 0;
    for(int i = 0; i < n / 2; i++){
         khGian = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = khGian;
    }
    for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
		if((i + 1) % 10 == 0){
			printf("\n");
		}
	}
}

// ktra mang co doi xung hay khong
int ktraCDoiXung(int a[], int n){
	int i;
	for(i = 0; i < n / 2; i++){
		if(a[i] != a[n-1-i]){
			return 0;
		}
    }
	return 1;
}
// ham ktr mang dang sap xep tang dan hay giam dan
int ktraTangDan(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		if(a[i] > a[i + 1]){
			return 2;
		}
	}
	return 3;// ham da sap xep theo thu tu tang dan
}
// ham tong
double hamTong(int a[], int n){
	double tong = 0;
	for(int i = 0; i < n; i++){
		tong += (double)a[i];
	}
	return tong;
}

// ham tinh tbn
double hamTinhTbn(int a[], int n){
	double logsum = 0;
	int dem = 0;
	for(int i = 0; i < n; i++){
		if(a[i] > 0){
			logsum += log(a[i]);
			dem++;
		}
        else{
            printf("\nKhong tinh trung binh nhan do trong mang co phan tu <= 0");
		return -1;
        }
	}
	if(dem == 0){
		printf("\nKhong tinh trung binh nhan do trong mang co phan tu <= 0");
		return -1;
	}
	else{
	    double tbn = exp(logsum / dem);// cong thuc tinh trung binh nhan
		printf("\nTrung binh nhan trong mang la: %.2f", tbn);
		return tbn;
	}

}
//ham tim cac phan tu duong va in ra tong cua chung
int timDuong(int a[], int n){
	int dem1 = 0;
	for(int i = 0; i < n;i++){ 
		if(a[i] > 0){
			dem1++;
		}
    }
return dem1;
}
int timDuong1(int a[], int n){
	int s2 = 0;
	for(int i = 0; i < n;i++){ 
	    if(a[i] > 0){
		    s2 += a[i];
	    }
    }
return s2;
}
   
// ham tim duong nho nhat trong mang
int hamTimDuongNn(int a[], int n){
	int min2 = 0;// gia trj duong nho nhat
	for(int i = 0; i < n;i++){// tim phan tu duong dau tien de so sanh lay gia tri nho nhat
		if(a[i] >= 0){
			min2 = i;
			break;
		}
	}
	for(int i = 0; i < n; i++){
		if(a[i] >= 0 && a[min2] > a[i]){
			min2 = i;
		}
	}
	return min2;// de luu gia tri min2
}

// ham max va min
int hamMax(int a[], int n){
	int max;
    max = a[0];
	for(int i = 1; i < n; i++){
		if(max < a[i]){
			max = a[i];
		}
	}
	return max;// de luu gia tri max
}
int hamMin(int a[], int n){
	int min;
	min = a[0];
	for(int i = 1; i < n; i++){
		if(min > a[i]){
			min = a[i];
		}
	}
	return min;// de luu gia tri min
}

// ham nhap 
void hamNhapCacphanTu(int a[], int n){
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

// ham tim so nt trong mang
int ktSoNT(int m){
	int i;
	if (m < 2) return 0;
	for(i = 2; i <= sqrt(m); i++){
		if(m % i == 0){
			return 0;// khong phai la so nguyen to
		}
	}
		return 1;// la so nguyen to
}

// ham Kiê?m tra trong da~y sô´ co´ bao nhiêu ca?p ai+aj (i#j) la` sô´ nguyên tô´.
int hamKtrCap(int a[], int n){
	int capaiaj = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(ktSoNT(a[i] + a[j]) == 1){
				capaiaj++;
			}
		}
	}
	return capaiaj;
}

// ham sap xep cac phan tu trong mang tang dan
void SapXepTangDan(int a[], int n){// thuat toan bubble sort( bot noi)
	int i, j;
	int hVi ;
	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n-1-i; j++){
			if(a[j] > a[j + 1]){
				hVi = a[j];
				a[j] = a[j + 1];
				a[j + 1] = hVi;
			}
		}
	}
}

// ham sap xep cac phan tu trong mang giam dan 
void sapXepGiamDan(int a[], int n){
	int hVi;
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n-1-i; j++){
			if(a[j] < a[j + 1]){
				hVi = a[j];
				a[j] = a[j + 1];
				a[j + 1] = hVi;
			}
		}
	}
}


// chuong trinh chinh
int main(){
	int a[101],b[101] , i, n;
	int c[101];
	
	// ktr 
	do{
		printf("Nhap so phan tu trong n: ");
		scanf("%d", &n);
	}while(n <= 0 || n > 101);
	
	// nhap
    hamNhapCacphanTu(a, n);
    // luu cac phan tu ban dau de kh bi trung
	for( i = 0; i < n; i++ ){
		b[i] = a[i];
		c[i] = a[i];
	}
    // in cac phan tu
	printf("\nCac phan vua nhap vao trong mang la:\n");
	hamIn(a, n);
	printf("\n=======================================================================\n");
	// gia tri nho nhat lon nhat cua mang
	int max = hamMax(a, n);
	printf("Gia tri lon nhat la: %d",max);
	int min = hamMin(a, n);
	printf("\nGia tri nho nhat la: %d",min);
	printf("\n=======================================================================\n");
	// tim va in phan tu  duong nho nhat
	int min2 = hamTimDuongNn(a, n);
	printf("Gia tri duong nho nhat la %d va o vi tri A[%d]",a[min2], min2);
	printf("\n=======================================================================\n");
	// tong cua mang va tong tb va tong tb nhan
	double tbn = 1;
	double tbc = 0;
	double tong = hamTong(a, n);
	tbc = tong / n;
    printf("Tong cac phan tu trong mang la: %.2f", tong );
	printf("\nTrung binh tong trong trong mang la: %.2f", tbc);
    hamTinhTbn(a, n);
	printf("\n=======================================================================\n");
	// tim phan tu x trong mang
	int x, d = 0 ;// d o day dong vai tro tim x
	printf("Nhap x: ");
	scanf("%d", &x);
	for(i = 0; i < n; i++){
		if(x == a[i]){
			d = 1;
			break;
		}
	}
	if(d){
		printf("Trong mang co phan tu bang x bang %d", x);
	}
	else{
		printf("Mang khong co phan tu x nao bang %d", x);
	}
	printf("\n=======================================================================\n");
	// sap xep mang the thu tu tang dan 
    SapXepTangDan(a, n);
    printf("Cac phan tu dc sap xep tang dan trong mang:\n");
    hamIn(a, n);
	printf("\n=======================================================================\n");
	// sap xep mang the thu tu giam dan
	sapXepGiamDan(a, n);
    printf("Cac phan tu dc sap xep giam dan trong mang:\n");
    hamIn(a, n);
	printf("\n=======================================================================\n");
	// ktr so nguyen to
	int dem = 0;
	for(i = 0; i < n; i++){
		if(ktSoNT(a[i]) == 1){
			dem++;
		}
	}
	printf("Mang co %d so nguyen to", dem);
	printf("\nBao gom nhung so: ");
	for(i = 0; i< n; i++){
		if(ktSoNT(a[i]) == 1){
			printf("%d ", a[i]);
		}
	}
	printf("\n=======================================================================\n");
	// tim so nguyen duong trong mang
	int dem1 = 0;
	int s2 = 0;
	s2 = timDuong1(a, n);
	dem1 = timDuong(a, n);
	printf("Co %d so nguyen duong trong mang", dem1);
	printf(" va tong cua no bang: %d", s2);
	printf("\n=======================================================================\n");
    // dao lai day ban dau
    printf("Cac phan vua dc dao lai troong mang la:\n");
    hamDao(b, n);
	printf("\n=======================================================================\n");
    // ktra mang da sap xep tang dan chua
	if(ktraTangDan(a, n) == 3){
		printf("ham dang sap xep tang dan ");
	}
	else{
		printf("ham dang sap xep giam dan ");
	}
	printf("\n=======================================================================\n");
	// ktra mang co doi xung hay khong
	if(ktraCDoiXung(c, n) == 1){
		printf("Mang co doi xung voi nhau");
	}
	else{
		printf("Mang khong doi xung voi nhau"); 
	}
	printf("\n=======================================================================\n");
	// Kiểm tra dãy có bao nhiêu cặp số mà số sau bằng tổng 2 số trước
    int cap1 = cap(c, n);
	if(cap1){
        printf("Trong mang co %d cap ma so sau bang tong cua 2 so truoc", cap1);
    }
    else{
        printf("Trong mang khong co cap ma so sau bang tong cua 2 so truoc ");
    }
	printf("\n=======================================================================\n");
	//  Kiểm tra trong dãy số có bao nhiêu cặp ai+aj (i#j) là số nguyên tố.
	int capaiaj = hamKtrCap(c, n);
	printf("co %d cap (ai + aj) la so nguyen to ", capaiaj);
	printf("\n=======================================================================\n");
	// them phan tu vao mang
	int x1;
	int k;
	printf("nhap phan tu x1: ");
	scanf("%d", &x);
	do{
		printf("nhap vi tri cua x: ");
	    scanf("%d", &k);
	}while(k > n || k < 0);
	n = hamThem(c, x, k, n);
	printf("cac phan tu trong mang sau khi them la:\n");
    hamIn(c, n);
	printf("\n=======================================================================\n");
    // xoa phan tu tu trong mang
	n = hamXoa(c, k, n);
	printf("cac phan tu tu trong mang sau khi xoa la:\n");
	hamIn(c, n);

	return 0;
}