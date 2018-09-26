#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>


int main()
{
    int pid1, pid2, fd[2];
    pipe(fd);

    printf("Creating 1st shild\n");
    pid1 = fork();
    if(pid1 == 0)
    {

        printf("Getting pid of 2nd child in 1st one\n");
        close(fd[1]);
        read(fd[0], &pid2, sizeof(int));

        printf("Sending SIGSTOP to 2nd child from 1st one\n");
        kill(pid2, SIGSTOP);

    }
    else
    {
        printf("Creating 2nd child\n");
        pid2 = fork();
        if(pid2 == 0)
        {
            while(1);
        }
        else{

            printf("Sending pid on 2nd child to 1st one from parent\n");
            close(fd[0]);
            write(fd[1], &pid2, sizeof(int));

            printf("Waiting for termination of 2nd child...\n");
            int status;
            waitpid(pid2, &status, WUNTRACED);
            printf("Parent have got %d signal from 2nd child\n", status);
        }
    }


    return 0;
}
