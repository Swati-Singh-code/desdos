#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t id;

    printf("Before fork\n");
    id = fork();


    if (0 == id)
    { //child
        printf("In Child: PID= %d\t PPID= %d\n", getpid(), getppid());
    }
    else
    {
        printf("In Parent: PID =%d\t PPID= %d\n", getpid(), getppid());
        printf("In Parent:\n");
    }

    return 0;
    

         

    }
    
