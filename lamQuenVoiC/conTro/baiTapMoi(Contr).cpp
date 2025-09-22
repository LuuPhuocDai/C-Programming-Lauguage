#include "stdio.h"
#include "stdlib.h"

// import function
void importFunction(int *a, int n){
	for(int i = 0; i < n; i++){
		printf("A[%d] = ", i);
		scanf("%d", a + i);
	}
	printf("\n");
}

// print function
void PrintFunction(int *a, int n){
	for(int i = 0; i < n; i++){
		printf("%d ", *(a + i));
		if((i + 1)% 5 == 0){
			printf("\n");
		}
	}
}
// function to find maximum and minimum values
int MaxFct(int *a, int n){
	int max = a[0];
	for(int i = 1; i < n; i++){
		if(max < *(a + i)){
			max = *(a + i);
		}
	}
	return max;
}
int MinFct(int *a, int n){
	int min = a[0];
	for(int i = 1; i < n; i++){
		if(min > *(a + i)){
			min = *(a + i);
		}
	}
	return min;
}

// ascending sort function in array
void AscendingSort(int *a, int n){
	for(int i = 1; i < n; i++){
	   int initial = *(a + i);
	   int j = i - 1;
		while(j >= 0 && initial < *(a + j)){
			*(a + j + 1) = *(a + j);
			j--;
		}
		*(a + j + 1) = initial;
	}
}

// descending sort function in array
void DescendingSort(int *a, int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - 1 - i; j++){
			if(*(a + j) < *(a + j + 1)){
				int temp = *(a + j);
				*(a + j) = *(a + j + 1);
				*(a + j + 1) = temp;
			}
		}
	}
}

// array search function
void SearchFct(int *a, int n, int b){// b la bien can tim kiem
	for(int i = 0; i < n; i++){
		if(b == *(a + i)){
			printf("The elements you are looking is %d and it is position A[%d]", b, i);
			return;
		}
	}
	printf("The element you want to search for does not exist in the array!!!");
}

// function to find the most frequent element in an array
void frequent(int *a, int n){
	AscendingSort(a, n);
	int count = 1, max = 1;
	int result[1000];
	int numberRepeats = 0;
	for(int i = 1; i < n; i++){
		if(*(a + i - 1) == *(a + i)){
			count++;
		}
		else{
			if(count > max){
				max = count;
				result[0] = *(a + i - 1);
				numberRepeats = 1;
			}
			else if( count == max){
				result[numberRepeats++] = *(a + i - 1);
			}
			count = 1;
		}
	}
	// xu li phan tu cuoi cua mang
	if(count > max){
		max = count;
		result[0] = *(a + n - 1);
		numberRepeats = 1;  
	}
	else if(count == max){
		result[numberRepeats++] = *(a + n - 1);
	}
	if(max < 2){
		printf("\nThere are no duplicate elements in the array!!!");
	}
	else{
		printf("\nThere are %d elements that appear most often in the array (appeared %d times) and it is the number: ", numberRepeats, max);
		for(int i = 0; i < numberRepeats; i++){
			printf("%d ",  result[i]);
		}
	}
}

// function to add elememt to array
void addElement(int **a, int *n){
	int b, c;
	printf("\nEnter the elements you want to add to the array: ");
	scanf("%d", &c);
	printf("Enter the location where you want to insert: ");
	scanf("%d", &b);
	
	*a = (int *) realloc (*a, (*n + 1) * sizeof(int)); // tang so luong phan tu
	
	// dich chuyen cac phan tu qu phai de chen phan tu moi vao vi tri ma minh muon 
	for(int i = *n; i > b; i--){
	(*a)[i] = (*a)[i - 1];
	}
	
	// chen phan tu 
	(*a)[b] = c;
	(*n)++;	
}

// function to remove element from array
void removeElement(int **a, int *n){
	int b, c;
	int count = 0;
	printf("\nEnter the element you want to remove from array: ");
	scanf("%d", &c);
	
	for(int i = 0; i < *n; i++){
		if(c == (*a)[i]){
			count++;
		}
	}
	if( count > 1){
		printf("There are %d element you want to delete in the array", count);
		printf("\nEnter the location where you want to remove: ");
	    scanf("%d", &b); 
		    
	    for(int i = b; i < *n - 1; i++){
		   (*a)[i] = (*a)[i + 1];
	    }
	
	    (*n)--;
	 
	    *a = (int*)realloc(*a, (*n) * sizeof(int));  
	
	}
	else if(count == 1){
		for(int i = 0; i < *n; i++){
			if(c == (*a)[i]){
				for(int j = i; j < *n - 1; j++){
		          (*a)[j] = (*a)[j + 1];
	            }
	            (*n)--;
	            *a = (int*)realloc(*a, (*n) * sizeof(int));
	            break;
			}  
		}
	}
	else{
		printf("The element you want to delete dose not exist in the array!!!\n");
	}
}

			
// main program
int main(){
	int n, *a, *b;
	printf("enter n: ");
	scanf("%d", &n);
	
	a = (int *) malloc (n * sizeof(int));
	b = (int *) malloc (n * sizeof(int));
	
	importFunction(a, n);
	// save the initial value of array
	for(int i = 0; i < n; i++){
		*(b + i) = *(a + i);
	}
	printf("Elements just added to the array: ");
	PrintFunction(a, n);
	printf("\n======================================================================================\n");
	
	int min = MinFct(a, n);
	printf("\nMinimum value of array: %d ", min);
	int max = MaxFct(a, n);
	printf("\nMaximum value of arrray: %d ", max);
	printf("\n======================================================================================\n");
	
	printf("\nArray after being sorted in ascending order: ");
	AscendingSort(a, n);
	PrintFunction(a, n);
	printf("\nArray after being sorted in descending order: ");
	DescendingSort(a, n);
	PrintFunction(a, n);
	printf("\n======================================================================================\n");
    
    int x;
    printf("\nEnter the element you want to search for in the array: ");
    scanf("%d", &x);
    SearchFct(b, n, x);
	printf("\n======================================================================================\n");
	 
	frequent(a, n); 
	printf("\n======================================================================================\n");
	
	addElement(&b, &n);
	PrintFunction(b, n);
	printf("\n======================================================================================\n");
	
    printf("\nArray before deletion: \n");
	PrintFunction(b, n);
	removeElement(&b, &n);
	printf("\nArray after deletion: \n");
	PrintFunction(b, n);
	
	
	
	
	free(a);
	free(b);
	return 0;
}
