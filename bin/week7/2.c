#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX 100

sem_t sem[MAX];
int n;

void *dine(void *p){
	int id=*(int *)p;
	sem_wait(&sem[(id+1)%n]);
	sem_wait(&sem[id]);
	printf("Philosopher no %d is dining\n",id);
	sem_post(&sem[(id+1)%n]);
	sem_post(&sem[id]);
}

int main(){
	pthread_t t[MAX];
	printf("Enter no of philosophers: ");
	scanf("%d",&n);
	int i;
	for(i=0; i<n; ++i){
		sem_init(&sem[i],0,1);
	}
	for(i=0; i<n; ++i){
		int *a=malloc(sizeof (int));
		*a=i;
		pthread_create(&t[i],0,dine,a);
	}
	for(i=0; i<n; ++i){
		pthread_join(t[i],0);
	}
	return 0;
}
