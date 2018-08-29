#include <stdio.h>
#include <malloc.h>
#include <string.h>


int main()
{
    int n;
    printf("Please enter size");
    scanf("%d", &n);

    for(int level=0;level<n;level++){
        //first part
        for (int i=0;i<(n-1-level);i++)
            printf(" ");
        //stars
        for (int i=0;i<(1+level*2);i++)
            printf("*");
        //second part
        for (int i=0;i<(n-1-level);i++)
            printf(" ");
        printf("\n");
    }
    return 0;
}
