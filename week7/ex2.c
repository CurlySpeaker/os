#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int main()
{
    int n;
    printf("%s", "Please enter the number \n");
    scanf("%d",&n);

    int *ar = malloc(n*sizeof(int));

    for (int i=0;i<n;i++){
       ar[i] = i;
    }

    printf("%s", "Printing the array: \n");
    for (int i=0;i<n;i++){
        printf("%d\n", ar[i]);
    }

    printf("%s", "Deallocating the memory... \n");
    free(ar);
    printf("%s", "Finished\n");

    return 0;
}
