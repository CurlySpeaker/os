#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>


void sig_catcher(int sig) {
    printf("You interrupted the program.");
    exit(1);
}

int main()
{
    signal(SIGINT, sig_catcher);

    while(1)
    {
        printf("Program is running...\n");
        sleep(1);
    }

    return 0;
}
