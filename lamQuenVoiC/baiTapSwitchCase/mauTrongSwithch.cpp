#include "stdio.h"

main(){
	char color;
	printf("enter color: ");
	scanf("%c", &color);// %c ki tu vd: r, g, f,...
	
	switch(color){
		case 'r':
		case 'R':
			printf("RED Color");
			break;
		case 'b':
		case 'B':
			printf("BLUE Color");
			break;
		case 'g':
		case 'G':
			printf("GREEN Color");
			break;
		default:
			printf("BLACK Color");
	}
}
