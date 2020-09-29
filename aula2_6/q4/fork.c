#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int v_global = 0; // Variavel global para este exemplo
int n = 3;

void Incrementa_Variavel_Global( pid_t id_atual)
{
    v_global++;
    printf("ID do processo que executou esta funcao = %d\n", id_atual);
    printf("v_global = %d\n", v_global);
}

int main (void){
    
    for(int i=0;i<n;i++)
    {
        if(fork() == 0)
        {
            printf("PID filho: %d de PID pai: %d\n",getpid(),getppid());
            Incrementa_Variavel_Global(getpid());
            exit(0);
        }
    }
    
    for(int i=0;i<n;i++)
    wait(NULL);
}


