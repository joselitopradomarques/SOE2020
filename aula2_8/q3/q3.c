#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Declaração da struct
struct numero
{
    int num;
};

/*
 A conversão é necessária pois a variável recebida é do tipo void
 Portanto
 Devemos convertê-la na struct definida
 Dentro da Struct, o valor recebido será transformado em inteiro
 void -> struct -> int
 */

void *print_ptr(void *parameters)
{
    struct numero *p = (struct numero*)parameters;
    int i;
    for(i = 1; i<11; i++)
    {
        printf("Thread recebeu: %d\n", p->num);
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t thread_id1;
    // Definição da struct
    struct numero thread_arg;
    int i;
    pthread_create(&thread_id1, NULL, &print_ptr, &thread_arg);
    for(i = 1; i<11; i++)
    {
        thread_arg.num = i;
        sleep(1);
    }
    pthread_join(thread_id1,NULL);
    return 0;
}
