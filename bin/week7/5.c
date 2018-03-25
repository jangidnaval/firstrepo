#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX 100

sem_t sem;
int n,np;

void *haircut(void *p){
	int id=*(int *)p;
	sem_wait(&sem);
	printf("Person no %d got haircut\n",id);
	sem_post(&sem);
}

int main(){
	pthread_t t[MAX];
	printf("Enter no of free chairs at barbershop: ");
	scanf("%d",&n);
	sem_init(&sem, 0, n);
	int i;
	printf("Enter no of people who want haircut: ");
	scanf("%d",&np);
	for(i=0; i<np; ++i){
		int *a=malloc(sizeof (int));
		*a=i;
		pthread_create(&t[i],0,haircut,a);
	}
	for(i=0; i<n; ++i){
		pthread_join(t[i],0);
	}
	return 0;
}
