#include "stdio.h"
#define tB 25000
main(){
	int tongTien = 0, soPhut;
	printf("nhap so phut: ");
	scanf("%d", &soPhut);
	
	if (soPhut <= 10){
		tongTien = tB + soPhut * 600;
	}
	else if (soPhut > 10 && soPhut <= 60){
		tongTien = tB + 10 * 600 + (soPhut - 10) * 400; 
	}
	else {
		tongTien = tB + 10 * 600 + 50 * 400 + (soPhut - 60) * 200;
	}
	
	printf("tong tien: %d", tongTien);
}
