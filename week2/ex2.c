#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX_LENGTH 200

int main()
{
    char* input;
    input = malloc(MAX_LENGTH);
    printf("Please enter your string");
    scanf("%[^\n]", input);

    for(int i=strlen(input);i>=0;i--)
        printf("%c", input[i]);
    printf("\n");

    free(input);
    return 0;
}
