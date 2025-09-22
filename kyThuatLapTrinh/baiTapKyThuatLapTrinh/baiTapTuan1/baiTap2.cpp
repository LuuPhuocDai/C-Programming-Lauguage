#include "stdio.h"
int main(){
	int a[101], i, n, max, min, sum, dem = 0, x;
	float tbCong;
	do{
		printf("nhap so luong phan tu cua day: ");
	    scanf("%d", &n);
	}while(n <= 0);
	
	
		for(i = 0; i < n; i++){
		printf("a[%d]= ",i + 1);
		scanf("%d", &a[i]);
	    }
	    printf("so phan tu vua nhap vao la: ");
	    for(i = 0; i < n; i++){
		   printf("%d ", a[i]);
        }
        printf("\ntong day: ");// tong phan tu trong day
        for(i = 0; i < n; i++){
		   sum += a[i];
        }
        printf("%d", sum);
        printf("\ntrung binh cong: ");// tinh tb cong cua day
    	tbCong = (float)sum / n;
        printf("%.2f", tbCong);
    
    	max = a[0];// max min trong day
    	for(i = 0; i < n; i++){
		  if(max < a[i]){
		    max = a[i];
		   }
		  else{
			min = a[i];
		   }
	    }
	    printf("\nso lon nhat trong day la %d", max);
        printf("\nso nho nhat trong day la %d", min);
        
        printf("\nNhap gia tri x: ");// so phan tu chan cua day nho hon x
        scanf("%d", &x);
    
        for (i = 0; i < n; i++) {
           if (a[i] % 2 == 0 && a[i] < x) {
            dem++;  
            }
        }

    printf("So phan tu chan nho hon %d co %d phan tu", x,dem);// thong ke
	
	
}

