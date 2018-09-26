#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>


void sig_catcher(int sig) {
    switch(sig){
        case SIGKILL:
            printf("Received SIGKILL.");
            break;
        case SIGSTOP:
            printf("Received SIGSTOP.");
            break;
        case SIGUSR1:
            printf("Received SIGUSR1.");
            break;
    }
    exit(1);
}

int main()
{
    signal(SIGKILL, sig_catcher);
    signal(SIGSTOP, sig_catcher);
    signal(SIGUSR1, sig_catcher);

    while(1)
    {
        printf("Program is running...\n");
        sleep(1);
    }

    return 0;
}
