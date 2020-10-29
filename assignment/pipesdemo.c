#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int sum(int,int);

int main(int argc, char const *argv[])
{
    int pfd[2],pfd1[2],ibuff[128],rbuff[128];
    pid_t id;
    pipe(pfd);
    pipe(pfd1);

    printf("enter two integer:\n");
    scanf("%d %d",&ibuff[0],&ibuff[1]);

    id = fork();

    if(0 == id)//child process//process2
    {
        printf("##############\n");
        printf("Welcome To child Process->\n");
        read(pfd[0], ibuff, 128);
        printf("Child received 1st int from parent: %d\n",ibuff[0]);
        printf("Child received 2nd int from parent: %d\n",ibuff[1]);
        rbuff[0]= sum(ibuff[0],ibuff[1]);
        printf("child Send Addition of two integer to Parent: %d\n",rbuff[0]);
        write(pfd1[1], rbuff,128);


        close(pfd[0]);
    }
    else
    { // Parent process//process1
        printf("Welcome to parent proces->\n");
        write(pfd[1], ibuff, 128);
        printf("1st int: %d\n",ibuff[0]);
        printf("2nd int: %d\n",ibuff[1]);
        close(pfd[1]);
        read(pfd1[0],rbuff,128);
        printf("###################\n");
        printf("Again You Are in Parent Process:\n");
        printf("Parent Received the sum from Child: %d\n",rbuff[0]);
    }
    return 0;
}
int sum(int a,int b){


    return a+b;

}









