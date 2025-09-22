#include "stdio.h"

main(){
	int month, year;
	printf("Enter Month: ");
	scanf("%d", &month);
	
	printf("\nEnter Year: ");
	scanf("%d", &year);
	
	switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			printf("month %d has 31 days", month);
		break;
		case 4:
		case 6:
		case 9:
		case 11:
			printf("month %d has 30 days", month);
			break;
		case 2:
			if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0 ){
				printf("month %d has 29 days", month);
			}
			else{
				printf("month %d has 28 days", month);
			}
			break;
		
		default:
			printf("invalid month");// thang kh hop le
			
			
	}
}
