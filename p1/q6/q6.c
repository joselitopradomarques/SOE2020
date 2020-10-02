/*
- Não consegui implementar a multiplicação dentro da função
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define L 50000

struct dados_vetor
{
	double *v;
	double n;
};

void *dobrar (void* parameters)
{
    struct dados_vetor* p = (struct dados_vetor*) parameters;
    
	for(int i=0;i < L/4; i++)
	{
        //p->v[i] = p->v[i] + p->v[i];
        p->v[i] = p->v[i] + p->v[i];
    }
    printf("Mesmos valores dobrados: %f\n",p->v[0]);
	return NULL;
}

int main()
{
    int i;
    double n = 3;
	double v[L];
    
	srand(time(NULL));
    
	for(i=0;i<L;i++)
	{
		v[i] = rand() % 100001;

	}

	struct dados_vetor vs[4];
	pthread_t thread_id[4];
	
	for(i=0;i<4;i++)
	{
		vs[i].v = &v[(L/4)*i];
		pthread_create(&thread_id[i], NULL, dobrar, &vs[i]);
        printf("Valor de v[%d]: %f\n", i*L/4, v[i*L/4]);
	}
    
	for(i=0;i<4;i++)
    {
		pthread_join(thread_id[i],NULL);
    }
	return 0;
}
