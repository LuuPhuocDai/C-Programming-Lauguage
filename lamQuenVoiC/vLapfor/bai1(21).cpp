#include "stdio.h"
int main(){
    int i, j, k, n = 0, a, b;

    for(i = 1; i < 6; i++){
        for(j = 1; j <= i ; j++){
            if(i == 1 || i == 5){
                printf(" *");
            }
            else{
               if(j == 1 || j == i){
                printf(" *");
               }
               else{
                printf("  ");
               }
            }
        }
        printf("\n");
    }
}