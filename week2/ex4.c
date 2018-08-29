#include <stdio.h>
#include <malloc.h>
#include <string.h>

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a, b;
    printf("Please enter first integer: ");
    scanf("%d", &a);
    printf("Please enter second integer: ");
    scanf("%d", &b);

    printf("Before swap first: %d second %d \n", a, b);
    swap(&a, &b);
    printf("After swap first: %d second %d \n", a, b);

    return 0;
}
