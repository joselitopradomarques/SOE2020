#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int pid;
    int fd[2];
    int i;
    int val;
    // Cria o pipe
    pipe(fd);
    // Cria o processo
    pid = fork();
    // Código do filho
    if(pid == 0)
    {
        // Fechar o descritor de escrita do filho
        wait(NULL);
        read(fd[0], &val, sizeof(val));
        printf("%d\n", val);
        close(fd[1]);
        
    }
    // Código do pai
    else
    {
        // Fechar o descritor de leitura do pai
        close(fd[0]);
        // Definir o array
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (i=0;i<10;i++)
            write(1, &arr[i], sizeof(arr[i]));
            //printf("%d\n", arr[i]);
            wait(NULL);
            sleep(1);
        
    }
    return 0;
}
