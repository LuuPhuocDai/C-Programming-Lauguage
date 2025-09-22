#include "stdio.h"

main(){
	
// tinh n = 1+2+3+4...+n =?

/*	int n, s = 0, i;
	printf("nhap n: ");
	scanf("%d", &n);
	
	for(i = 1; i <= n ; i++){
		s = s + i;
	}
	printf("tong n = %d  ", s);
}*/

// giai thua trong for

/*	int n, gThua = 1, i;
	printf("nhap n: ");
	scanf("%d", &n);
	
	for(i = 1; i <= n ; i++){
		gThua = gThua * i;
	}
	printf("%d! = %d  ", n, gThua);
}*/

// thay doi bien dieu khien tu 1 - 100, moi lan tang 1;

/*   int i, n ;
    printf("nhap n: ");
    scanf("%d", &n);
    
    for(i = 1; i <= n; i++){
    	printf("\n%d", i);
	}
} */

// thay doi bien dieu khien tu 100 - 1, moi lan giam 1;

/*    int i, n ;
    printf("nhap n: ");
    scanf("%d", &n);
    
    for(i = 0; i <= n; i++){
    	printf("\n%d",n - i);
	}
}  */

// z - a, moi lan giam a lan;

/*    int i, z, a ;
    printf("nhap z - a: ");
    scanf("%d%d", &z, &a);
    
    for(i = z; i >= 0; i = i - a){
    	printf("\n%d",i );
	} 
} */

// viet chuong trinh nhap cac so nguyen, tính tong cac gia tri le 0 - n;
/*   int n, i, s = 0;
   printf("nhap n: ");
   scanf("%d", &n);
   
   for( i = 1; i <= n; i++ ){
   	if(i % 2 == 1){
   		s += i;
	   }
   }
   printf(" tong cac so le : %d", s);
}  */

// vd 4: tinh tong s = 1+1/2+1/4+...+1/n voi n la so chan;


   int n, i;
   float s = 1.0;
   
   for(i = 0; i <= n; i++){
   	printf("nhap n: ");
    scanf("%d", &n);
    
   	 if( n % 2 == 1 ){
   	   continue;
	 }
     else {
   	   for( i = 2; i <= n; i+=2 ){
		s += 1.0/i;
	   }
	printf("tong = %.2f",s);
     }    
   }
}   

