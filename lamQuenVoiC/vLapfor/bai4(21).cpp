#include "stdio.h"
int main(){
    int i, j, n, a;
    printf("nhập số nguyên n: ");
    scanf("%d", &n);
    for( ; n > 0; ){
       printf("%d", n % 10);
       n = n / 10;
    }
}