#include "stdio.h"
int main(){
    char continuee;
	int namSinh, namHT, tuoi;
	
	do{
		printf("nhap nam hien tai: ");
	    scanf("%d", &namHT);
	    printf("nhap nam sinh cua ban: ");
	    scanf("%d", &namSinh);
		printf("\nso tuoi hien tai cua ban la %d", namHT - namSinh);
        printf("do you want to continue(n/Y): ");
		scanf("%s", &continuee);
		gets(continuee);
		fflush(stdin);
		
	}while('y' == continuee || 'Y' == continuee);
}
