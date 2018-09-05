#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 300


void bubblesort (int *array, int n){
	for (int i=0;i<n-1;++i){
		for (int j=1;j<n-i;++j){
			if (array[j]<array[j-1]){
				int tmp = array[j-1];
				array[j-1] = array[j];
				array[j] = tmp;
			}
		}
	}
}


int main(){
	int * array = malloc(sizeof(int)*MAX_ARRAY_SIZE); 
	int size;
	printf("Enter an array size: ");
	scanf("%d", &size);
	printf("Enter %d integers: ", size);
	for (int i=0;i<size;i++){
		scanf ("%d", &array[i]);
	}
	bubblesort(array, size);
	for (int i=0;i<size;i++){
		printf("%d ", array[i]);
	}	
	return 0;
}
          
