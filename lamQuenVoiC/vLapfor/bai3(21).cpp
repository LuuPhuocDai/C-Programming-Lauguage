#include "stdio.h"
int main(){
    int i, a = 0, n;
    printf("nhập n: ");
    scanf("%d", &n);
    for(i = 2; i <= n; i++){
        if( n % i == 0){
            a +=i;
        }
    }
    if(a == n){
        printf("%d là số hoàn hảo", n);
    }
    else{
        printf("%d không phải là số hoàn hảo", n);
    }
}