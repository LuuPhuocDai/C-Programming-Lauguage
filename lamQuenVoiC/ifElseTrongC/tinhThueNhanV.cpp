#include "stdio.h"
#include "math.h"

main(){
	int luong, thue = 0, thucLinh = 0;
	printf("nhap so luong cua ban: ");
	scanf("%d", &luong);
	
	if (luong >= 1500000){
		thue = luong * 0.3;
	}
	else if ( luong < 1500000 && luong >= 7000000){
		thue = luong * 0.2;
	}
	else {
		thue = luong * 0.1;
	}
	thucLinh = luong - thue;
	printf("so thuc linh cua ban: %d va thue cua ban la: %d ", thucLinh, thue);
}
