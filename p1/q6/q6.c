#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define L 50000

struct dados_vetor
{
	long int *v;
	long int n;
};

void *dobrar (void* parameters)
{
    struct dados_vetor* p = (struct dados_vetor*) parameters;
    
	for(int i=0;i < L/4; i++)
	{
        p->v[i] = p-> v[i] + p-> v[i];
	}
    printf("%ld\n",p->v[0]);
	return NULL;
}

int main()
{
    int i;
    long int n = 3;
	long int v[L];
    
	srand(time(NULL));
    
	for(i=0;i<L;i++)
	{
		v[i] = rand() % 100001;

	}
    printf("%ld\n", v[0]);
    printf("%ld\n", v[L/4]);
    printf("%ld\n", v[L/2]);
    printf("%ld\n", v[3*L/4]);
	struct dados_vetor vs[4];
	pthread_t thread_id[4];
	
	for(i=0;i<4;i++)
	{
		vs[i].v = &v[(L/4)*i];
		pthread_create(&thread_id[i], NULL, dobrar, &vs[i]);
	}
    
	for(i=0;i<4;i++)
    {
		pthread_join(thread_id[i],NULL);
    }
	return 0;
}
