#include "stdio.h"

main(){
	char character;// dap an
	
	printf("what is the correct way to declare a variable and assign an integer value in c");// C�ch ch�nh x�c d? khai b�o m?t bi?n v� g�n m?t gi� tr? s? nguy�n trong c l� g�?
    
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
	





