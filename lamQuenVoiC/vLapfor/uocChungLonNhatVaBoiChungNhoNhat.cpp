#include "stdio.h"

main(){
	// viet chuong trinh tim uoc chuong lon nhat va boi so chung nho nhat;
	
	int a, b, i, ucln, doi;
	
	printf("nhap a va b: ");
	scanf("%d%d", &a, &b);
	
	if(a > b){       // tuc la buoc lay so trc no phai lon hon so sau vd 10 va 2 de so lay ucln
		a = doi;
		a = b;
		b = doi;
	}
	for(i = a; i >= 1; i--){      // phai chay tu cao den thap de tim so co uoc giong nhau;
	    if(a % i == 0 && b % i == 0){
	    	ucln = i;
	    	break;
		}
	}
	printf("uoc chung lon nhat cua a va b la %d", ucln);
	printf("\nboi chung nho nhat cua a va b la %d", a * b / ucln);   // tim dc uoc chung thì a * b / ucln ra boi chung nho nhat;
}
