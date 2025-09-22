#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "math.h"

// Ascending sort function 
void hamSXTD(int *a, int n){
	int banDau = 0;
	int j, i;
	for( i = 1; i < n; i++){
		banDau = *(a + i);
		j = i - 1;
		
		while(j >= 0 && banDau < *(a + j)){
			*(a + j + 1) = *(a + j);
			j--;
		}
		*(a + j + 1) = banDau;
	}	
}
// Descending sort function
void hamXSGIAM(int *a, int n){
	int banDau = 0;
	for(int i = 1; i < n; i++){
		banDau = *(a + i);
		int j = i - 1;
		while(j >= 0 && banDau > *(a + j)){
			*(a + j + 1) = *(a + j);
			j--;
		}
		*(a + j + 1) = banDau;
	}
}
// import function
void hamNhap(int *a, int n){
	for(int i = 0; i < n; i++ ){
		printf("a[%d] = ",i);
		scanf("%d", a + i);
	}
}
// print function
void hamIn(int *a, int n){
	for(int i = 0; i < n; i++ ){
	   printf("%d ", *( a + i));
	   if((i + 1) % 5 == 0){
	   	  printf("\n");
	   }
	}
}
// min function
int hamMin(int *a, int n){
	int min = a[0];
	for(int i = 1; i < n; i++){
		if(min > *(a + i)){
			min = *(a + i);
		}
	}
	return min;
}
// max function
int hamMax(int *a, int n){
	int max = a[0];
	for(int i = 1; i < n; i++){
		if(max < *(a + i)){
			max = *(a + i);
		}
	}
	return max;
}

// function to find the second largest value in an array
void MaxNhi(int *a, int n){
	int Max1 = hamMax(a, n);
	int Max2 = INT_MIN;
	int viTri = -1;
	int ktra = 0;
	for(int i = 0; i < n; i++){
		if(Max1 != *(a + i) && Max2 < *(a + i)){
			Max2 = *(a + i);
			ktra = 1;
			viTri = i;
		}
	}
	if(ktra == 1){
		printf("\nThe second largest value in the array is %d and is at position a[%d]", Max2, viTri);
	}
	else{
		printf("\nThere are no second largest value in the array!!!");
	}
}

// function to find the most frequent elements in an array
void findFreEle(int *a, int n){
	hamSXTD(a, n);
	
	int cout = 1, max = 1;
	int repeatingElement = 0;
	int result[1000];
	
	for(int i = 1; i < n; i++){
		if(*(a + i) == *(a + i - 1)){
			cout++;
		}
		else{
		    if(cout > max){
				max = cout;
				result[0] = *(a + i - 1);
				repeatingElement = 1;
			}
			else if(cout == max){
				result[repeatingElement++] = *(a + i - 1);
			}
			cout = 1;		
		}	
	}
	if(cout > max){
		max = cout;
		result[0] = *(a + n - 1);
		repeatingElement = 1;
	}
	else if(cout == max){
		result[repeatingElement++] = *(a + n - 1);
	}
	if(max < 2){
		printf("\nThere are no duplicate element in the array");
	}
	else{
		printf("\nThere are %d repeating elements in the array and it is number(the number of repeating elements is: %d): ", repeatingElement, max);
		for(int i = 0; i < repeatingElement; i++){
			printf("%d ", result[i]);
		}
	}
}

// array search function
int search(int *a, int n, int d){// d is called the element to be searched for
	for(int i = 0; i < n; i++){
		if(*(a + i) == d){
			return i;
		}
	}
	return -1;
}

// function to check prime number in array
int primeNumber(int n){
	if(n < 2) return 0;
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}

void checkPrimeNumber(int *a, int n){
	int count = 0;
	int *p = a;
	for(int i = 0; i < n; i++){
		if(primeNumber(*(p + i)) == 1){
			count++;
		}
    }  
    if(count == 0){
			printf("\nThere are no prime numbers in the array!!!");
		}
	else{
		printf("\nThere are %d prime numbers in the array and they are: ", count);
	    for(int i = 0; i < n; i++){
		    if(primeNumber(*(p + i))){
			   printf("%d ", *(p + i));
		    }
	    }
	    printf("\n");
	}
}

// main program
int main(){
	int *a, *b, n;
	printf("Enter quantity n: ");
	scanf("%d", &n);
	
	a = (int *)malloc(n * sizeof(int));
	b = (int *)malloc(n * sizeof(int));
	
	hamNhap(a, n);
	for(int i = 0; i < n; i++){
		*(b + i) = *(a + i);
	}
	printf("\nThe elements just entered into the array:\n");
	hamIn(a, n);
	printf("\nValue of array after decrement:\n");
	hamXSGIAM(a, n);
	hamIn(a, n);
	printf("\nValue of array after increment:\n");
	hamSXTD(a, n);
	hamIn(a, n);
	printf("\n");
	printf("\nSmallest value in array: %d", hamMin(a, n));
	printf("\nLargest value in array: %d\n", hamMax(a, n));
	
	MaxNhi(b, n);
	printf("\n");
	
	findFreEle(a, n);
	printf("\n");
	
	int d;// d is called the element to be searched for
	printf("\nEnter the element you want to search for:  ");
	scanf("%d", &d);
	int k = search(b, n, d);
	if(k == -1){
		printf("\nThe element you want to search for is not in the array!!!");
	}
	else{
		printf("\n%d is the element you want to search for and it is at position a[%d]", d, k);
	}
	printf("\n");
	
	checkPrimeNumber(b, n);
	
	
	free(a);
	free(b);
	return 0;
}

