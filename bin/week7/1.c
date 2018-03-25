#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX 10

sem_t sem;
int a[MAX], cnt=0;

void *produce(void *p){
	while(1){
		sem_wait(&sem);
		if(cnt<MAX){
			a[cnt]=cnt;
			printf("produced v=%d\n", a[cnt]);
			++cnt;
		}
		sem_post(&sem);
	}
}

void *consume(void *p){
	while(1){
		sem_wait(&sem);
		if(cnt>0){
			printf("consumed v=%d\n", a[cnt-1]);
			--cnt;
		}
		sem_post(&sem);
	}
}

int main(){
	pthread_t t1,t2;
	sem_init(&sem,0,1);
	pthread_create(&t1,0,produce,0);
	pthread_create(&t2,0,consume,0);
	pthread_join(t1,0);
	pthread_join(t2,0);
	return 0;
}
