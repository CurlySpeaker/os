#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


void* thread(int* n)
{
    printf("thread: %d\n", *n);
    return NULL;
}

int main()
{
    int n;
    scanf("%d", &n);
    pthread_t* pthread = malloc(sizeof(pthread_t)*n);

    for (int i=0;i<n;i++)
    {
        pthread_create(&pthread[i],NULL,&thread,&i);
    }
    for (int i=0;i<n;i++)
    {
        pthread_join(pthread[i], NULL);
    }

    free(pthread);

    return 0;
}
