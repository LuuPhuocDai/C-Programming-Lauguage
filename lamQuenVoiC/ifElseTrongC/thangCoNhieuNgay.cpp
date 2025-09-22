#include <stdio.h>

main(){
	int thang, nam;
	printf("Nhap vao thang va nam: ");
	scanf("%d%d", &thang, &nam);
	
	if (thang < 1 || thang > 12){
		printf("Ban nhap thang khong hop le, vui long nhap lai!!!");
	}
	else{
		if(thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12){
			printf("Thang %d co 31 ngay", thang);
		}
		else if(thang == 4 || thang == 6 || thang == 9 || thang == 11){
			printf("Thang %d co 30 ngay", thang);
		}
		else{
			if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0){
					printf("Thang %d co 29 ngay", thang);
			}
			else{
					printf("Thang %d co 28 ngay", thang);
			}
		}
	}
	
}
