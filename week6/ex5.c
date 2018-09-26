#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>


void fork_me() {
    int pid = fork();
    if(pid == 0)
    {
        while(1)
        {
            printf("I'm alive\n");
            sleep(1);
        }
    }
    else
    {
        sleep(10);
        kill(pid, SIGTERM);
    }
}

int main()
{
    fork_me();


    return 0;
}
