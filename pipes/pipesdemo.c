#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    unsigned char rbuff[128];
    pid_t id;
    int pfd[2];
    pipe(pfd);

    id = fork();

    if(0 == id)
    {
        read(pfd[0], rbuff, 128);
        printf("Child: %s\n", rbuff);
        close(pfd[0]);
    }
    else
    { // Parent process
        
       write(pfd[1], "cdac\n", 5);
       close(pfd[1]);
        
    }

    return 0;
    
}