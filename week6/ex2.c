#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define read_size 200

void pipe_fork(int fd[2])
{
    if(fork() == 0)
    {
        char r_str[read_size];
        close(fd[1]);
        read(fd[0], r_str, read_size);
        close(fd[0]);
        printf("%s", r_str);
    }
    else
    {
        close(fd[0]);
        write(fd[1], "It's wednesday my dudes", read_size);
        close(fd[1]);
    }
}

int main()
{
    int fd[2];
    pipe(fd);
    printf("Output: \n");
    pipe_fork(fd);

    return 0;
}
