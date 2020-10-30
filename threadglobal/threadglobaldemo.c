#include<stdio.h>
#include<pthread.h>
#include <unistd.h>


void *thread(void *arg)
{
    printf("New Thread\n");
    int sum =add(20,30);
    printf("new thread Add:%d\n",sum);
}
int add(int a,int b)
{
    return a+b;
}

int main(int argc, char const *argv[])
{
    pthread_t tid;
    int sum=add(30,40);
    printf("main Add:%d\n",sum);
    printf("before thread Creation\n");
    pthread_create(&tid,NULL,thread,NULL);
    sleep(1);
    return 0;
}
