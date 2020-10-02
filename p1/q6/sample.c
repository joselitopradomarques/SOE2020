#include <stdio.h>
#include <stdlib.h> //rand() e srand() estao aqui
#include <pthread.h>
#include <unistd.h>
#include <time.h> //para a funcao time()

struct ver_vetor
{
	long int *vec;
	long int max;
};

void *max_vetor(void *max)
{
    
	struct ver_vetor *p = (struct ver_vetor *) max;
    // a -> b = (*a).b
    // adquire o membro "a" da struct "b"
    // Nesse caso, estar-se-á zerando o ponteiro que varrerá o vetor
	p->max = 0;
	int i;
	for(i=0;i < 12500;i++)
	{
        // if max < vec[i]
		if(p->max < p->v[i])
		{
            // max = vec[i]
			p->max = p->vec[i];
		}
	}

	return NULL;
}

int main()
{
	long int v[50000];
	srand(time(NULL));
	int i;
	
	for(i=0;i<50000;i++)
	{
		v[i] = rand() % 100001;

	}
	
	long int max;
	max = 0;

	for(i=0;i<50000;i++)
	{
		if(v[i]>max)
		{
			max = v[i];
		}
	}
	
	printf("O valor máximo usando a busca completa é %ld.\n",max);
    
    // 
	struct ver_vetor verificar_vetor[4];
	pthread_t thread_id[4];
	
	for(i=0;i<4;i++)
	{
		verificar_vetor[i].vec = &v[12500*i];
		pthread_create(&thread_id[i],NULL,&max_vetor,&verificar_vetor[i]);
	}
	for(i=0;i<4;i++)
		pthread_join(thread_id[i],NULL);
	max = 0;
	for(i=0;i<4;i++)
	{
		//printf("Valor maximo da primeira thread %ld.\n",verificar_vetor[i].max);
		if(max < verificar_vetor[i].max)
		{
			max = verificar_vetor[i].max;
		}
	}
	printf("O valor máximo usando a busca paralela é %ld.\n",max);

	return 0;
}
