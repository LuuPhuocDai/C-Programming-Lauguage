#include "stdio.h"

main(){
	char character;// dap an
	
	printf("what is the correct way to declare a variable and assign an integer value in c");// Cách chính xác d? khai báo m?t bi?n và gán m?t giá tr? s? nguyên trong c là gì?
    
    printf("\na. int 1x=10;");
	printf("\nb. int x=10;");
	printf("\nc. float x=10.0f;");
	printf("\nd. string x='10';");
	printf(" \nyour answer is: ");
	scanf("%c", &character);
	
	switch(character){
		case 'a':
		case 'c':
		case 'd':
			printf("the answer is not correct");
			break;
		default:
			printf("the answer is correct");
		
	}
}
	





