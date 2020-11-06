#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int a,b;
int sum;

sem_t s1,s2;

void *input_thread(void *data)
{
    while(1)
    {
        printf("T1: Got signal from processing thread\n");
        sem_wait(&s2);
        printf("T1: Getting new inputs\n");
        scanf("%d", &a);
        scanf("%d", &b);
        printf("T1: Got new inputs\n");
        sem_post(&s1);
        printf("T1:Sending signal to processing thread\n");
    }
}

void *processing_thread(void *data)
{
    while(1)
    {
        printf("T2:Waiting signal from input thread\n");
        sem_wait(&s1);
        printf("T2: Starting processing\n");
        sum = a+b;
        printf("T2: Processing done..Sum: %d\n", sum);
        sem_post(&s2);
        printf("T2: Sending signal from input thread\n");
    }
}

int main(int argc, char const *argv[])
{
    pthread_t input_id, processing_id;
    sem_init(&s1,0, 0);
    sem_init(&s2,0, 1);
    pthread_create(&processing_id, NULL, processing_thread, NULL);
    pthread_create(&input_id, NULL, input_thread, NULL);

    pthread_join(input_id, NULL);
    pthread_join(processing_id, NULL);
    return 0;
}