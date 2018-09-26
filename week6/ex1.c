#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define read_size 200

int main()
{
    int fd[2];
    pipe(fd);

    write(fd[1], "It's wednesday my dudes", read_size);
    char r_str[read_size];

    read(fd[0], r_str, read_size);

    printf("%s", r_str);
    return 0;
}
