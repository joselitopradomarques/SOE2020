#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    printf("PID pai = %d\n", getpid());
    for(int i=0;i<3;i++)
    {
        if(fork() == 0)
        {
            printf("PID filho: %d de PID pai: %d\n",getpid(),getppid());
            exit(0);
        }
    }
    
    for(int i=0;i<3;i++)
    wait(NULL);
    
    return 0;
}
