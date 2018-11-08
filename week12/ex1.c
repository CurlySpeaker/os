#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{

    int fr;
    char buff[20];

    fr = open("/dev/random", O_RDONLY);
    read(fr, buff, 20);

    FILE *fw;
    fw = fopen("out1.txt", "w");

    for(int i=0;i<20;i++){
        fprintf(fw, "%d\n", buff[i]);
    }
    fclose(fw);

    return 0;
}
