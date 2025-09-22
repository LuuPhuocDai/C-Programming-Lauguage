#include "stdio.h"
#include "math.h"
main(){
	char sign, continuee;
	float x, y;
	
	do{
	   
	   printf("enter x, y: ");
	   scanf("%f%f", &x, &y);

	    fflush(stdin);// chan so va ki tu 
	    printf("choose calculation(+, -, *, /, ^): ");
    	scanf("%c", &sign);
    	fflush(stdin);

	    switch(sign){
		    case '+':
			    printf("%.2f + %.2f = %.2f", x, y, x + y);
			    printf("\ndo you want to continuee the calculation?(yes = y or no = n) ");
			    scanf("%c", &continuee);
		        break;
		    case '-':
			    printf("%.2f - %.2f = %.2f", x, y, x - y);
			    printf("\ndo you want to continuee the calculation?(yes = y or no = n) ");
			    scanf("%c", &continuee);
			    break;
		    case '*':
			    printf("%.2f * %.2f = %.2f", x, y, x * y);
			    printf("\ndo you want to continuee the calculation?(yes = y or no = n) ");
			    scanf("%c", &continuee);
			    break;
		    case '^':
			    printf("%.2f ^ %.2f = %.2f", x, y, pow(x, y));
			    printf("\ndo you want to continuee the calculation?(yes = y or no = n) ");
			    scanf("%c", &continuee);
			    break;
		    default:
			    if(y == 0){
				  printf("cannot perform calculation");// không thuc hien dc phep tinh
				  printf("\ndo you want to continuee the calculation?(yes = y or no = n) ");
			      scanf("%c", &continuee);
			    }
			    else{
				  printf("%.2f / %.2f = %.2f ", x, y, x / y);
				  printf("\ndo you want to continuee the calculation?(yes = y or no = n) ");
			      scanf("%c", &continuee);
			    }	
    	}
    }
    while(continuee == 'y' || continuee == 'Y');
    printf("\n-----------end------------");
}
