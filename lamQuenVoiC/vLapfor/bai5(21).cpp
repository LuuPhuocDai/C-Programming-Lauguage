#include "stdio.h"
int main(){
    int i, a = 1, b = 1, n, j, s; 
    printf("nhập n: ");
    scanf("%d", &n);
    printf("1 1 ");
    for(i = 3; i <= n; i++){
        s = a + b;
        printf("%d ", s);
        b = a ;
        a = s;
    }
}