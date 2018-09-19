#include <stdio.h>
#include <pthread.h>


void* thread(int* n)
{
    printf("thread: %d\n", *n);
    return NULL;
}

int main()
{
    int n;
    pthread_t pthread;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        pthread_create(&pthread,NULL,&thread,&i);
        pthread_join(pthread, NULL);
    }
}
