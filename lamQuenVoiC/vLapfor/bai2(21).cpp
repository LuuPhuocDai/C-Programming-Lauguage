#include "stdio.h"
int main(){
    int j, i, a, b;
    for(i = 1; i <= 8; i++){
        for(j = 1; j <= 8; j++){
            if(i % 2 == 0){
                if(j % 2 == 1){
                    printf(" # ");
                }
                else{
                    printf("  ");
                }
            }
            else{
                if(j % 2 == 1 ){
                    printf("  ");
                }
                else{
                    printf(" # ");
                }
            }
        }
        printf("\n");
    }
}