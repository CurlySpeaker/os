#include <stdio.h>
#include <pthread.h>

int buffer[100];
int c=0;
int ps=0;
int cs=0;

void* consume(void* null)
{
    while (1)
    {
        while (cs);
        if (c==0)
        {
            cs=1;
            continue;
        }
        printf("consumer gets %d\n", buffer[--c]);
        if (ps)
        {
            ps=0;
        }
    }
}

int main()
{
    pthread_t thread;
    pthread_create(&thread,NULL,consume,NULL);

    for (int i=0;;i++)
    {
        while (ps);
        if (c==100)
        {
            ps=1;
            continue;
        }
        printf("producer puts %d\n",i);
        buffer[c++]=i;
        if (cs)
        {
            cs=0;
        }
    }
}
