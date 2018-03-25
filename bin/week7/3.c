#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX 100

sem_t sem, sem2;
int nr,nw,cr;

void *reader(void *p){
	int id=*(int *)p;
	//int ok=0;
	sem_wait(&sem2);
	if(cr==0){
		//ok=1;
		sem_wait(&sem);
	}
	++cr;
	sem_post(&sem2);
	//sleep(1);
	sem_wait(&sem2);
	printf("Reader no %d is reading, total Readers=%d\n",id,cr);
	sem_post(&sem2);
	//sleep(1);
	sem_wait(&sem2);
	--cr;
	if(cr==0){
		sem_post(&sem);
	}
	sem_post(&sem2);
}

void *writer(void *p){
	int id=*(int *)p;
	sem_wait(&sem);
	printf("Writer no %d is writing\n",id);
	sem_post(&sem);
}

int main(){
	pthread_t tr[MAX], tw[MAX];
	sem_init(&sem,0,1);
	sem_init(&sem2,0,1);
	int n,type[MAX];
	printf("Enter no of readers & writers: ");
	scanf("%d",&n);
	int i;
	for(i=0; i<n; ++i){
		printf("Enter thread no %d type(0=reader/1=writer): ",i);
		scanf("%d",&type[i]);
	}
	for(i=0; i<n; ++i){
		int *a=malloc(sizeof (int));
		if(type[i]==0){
			*a=nr;
			pthread_create(&tr[nr],0,reader,a);
			++nr;
		}else{
			*a=nw;
			pthread_create(&tw[nw],0,writer,a);
			++nw;
		}
	}
	for(i=0; i<nr; ++i){
		pthread_join(tr[i],0);
	}
	for(i=0; i<nw; ++i){
		pthread_join(tw[i],0);
	}
	return 0;
}
