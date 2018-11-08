#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>


#define INPUT_SIZE 1024

int main(int argc, char* argv[])
{

    char buff[INPUT_SIZE];

    FILE* fw;
    char* mode = "w";

    for (int i = 1; i < argc; i++)
        if(strcmp(argv[i],"-a") == 0)
            mode = "a";

    read(STDIN_FILENO, buff, INPUT_SIZE);


    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-a") == 0)
            continue;
        fw = fopen(argv[i], mode);
        fprintf(fw, "%s", buff);
        fclose(fw);
    }


    fwrite(buff, 1, INPUT_SIZE, stdout);

    return 0;
}
