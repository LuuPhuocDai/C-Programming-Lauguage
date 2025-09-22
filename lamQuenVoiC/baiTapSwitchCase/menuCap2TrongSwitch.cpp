#include "stdio.h"

main(){
	int menu, sudMenu;
	
	printf("--------------------------------\n");
	printf("\tMAIN MENU\n");
	printf("--------------------------------\n");
	printf("1.File\n");
	printf("2.Edit\n");
	printf("3.Search\n");
	printf("select the corresponding item: ");// chon muc tuong ung
	scanf("%d", &menu);
	
	switch(menu){
		case 1:
			printf("--------------------------------\n");
	        printf("MENU FILE\n");
	        printf("--------------------------------\n");
	        printf("1.Open file\n");
	        printf("2.New file\n");
	        printf("select the correspondig item: ");
	        scanf("%d", &sudMenu);
	        
	        switch(sudMenu){
	        	case 1:
	        		printf("you have selected the open file item");// ban da lua chon muc open file
	        		break;
	        	case 2:
	        		printf("you have selected the new file item");// ban da lua chon muc new file
	        		break;
	        	default:
	        		printf("does not exist in the file section");// khong ton tai trong muc file
			}
			break;
		case 2:
			printf("you have selected the edit item");// ban da chon muc edit 
			break;
		case 3:
			printf("you have selected the search item");// ban da chon muc search
			break;
		default:
			printf("item does not exist");// muc khong ton tai
		
			
			
	   
	}
}
