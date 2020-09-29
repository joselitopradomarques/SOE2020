#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char **argv)
{
    pid_t p;

    char * vec [] = {*argv, (char*)NULL};

    for (int i = 1; i < argc+1; i++)
    {
        if (!fork())
        {
            execlp(argv[i], argv[i], (char*)0);
            sleep(1);
            exit(1);
        }
    }
    return 0;
    
}
