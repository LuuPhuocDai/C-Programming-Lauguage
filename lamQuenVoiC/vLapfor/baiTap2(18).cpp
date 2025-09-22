
#include "stdio.h"
#include "math.h"

main(){
	
	// tong cac so le binh phuong;
	
/*	int i, n, s = 0, bP;
	printf("Enter n: ");
	scanf("%d", &n);
	
	for(i = 1; i <= n; i++){
		if(i % 2 == 1){
			s += i;
			bP = pow(s, 2);
		}
    }
    printf("tong so le: %d ", bP); */
    
    // viet chuong trinh nhap vao roi in ra tat ca cac uoc cua so do;
    
   int n, i ;
    printf("nhap n: ");
    scanf("%d", &n);
    
    for(i = 2; i <= n; i++){
    	if( n % i == 0){
    		printf(" \nuoc cua %d la %d ", n, i);
		}
	}  
	
	// viet chuong trinh nhap vao mot so va kiem tra xem so do co phai so nguyen to hay khong?
	
/*	int n, i;
	printf("nhap n: ");
	scanf("%d", &n);

    for(i = 2; i < n; i++){
    	if(n % i == 0){
    		printf("%d khong phai la so nguyen to",n);
    		return 0; // thoat khoi chuong trinh 
		}
	}
	printf("%d la so nguyen to",n); 
	
	// viet chuong trinh tim uoc chuong lon nhat va boi so chung nho nhat; */
	
/*	int a, b, i, ucln, doi;
	
	printf("nhap a va b: ");
	scanf("%d%d", &a, &b);
	
	if(a > b){       
		a = doi;
		a = b;
		b = doi;
	}
	for(i = a; i >= 1; i--){      // phai chay tu cao den thap;
	    if(a % i == 0 && b % i == 0){
	    	ucln = i;
	    	break;
		}
	}
	printf("uoc chung lon nhat cua %d va %d la %d", a, b, ucln); */
}
