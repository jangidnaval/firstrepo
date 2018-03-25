//chapani yash natwarlal
//20154131
//csa1
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


volatile struct semaphore{
	volatile int val;
}q,i;

/*void P(semaphore st){
	while(st.val==0);
	st.val--;
}

void V(semaphore st){
	st.val++;
}*/
int itemsp,itemsc;

void* produce(){
	while(itemsp--){
		printf("producer:: producing....\n");
		sleep(4);
		printf("producer:: produced\n");
//		P(q);
		while(!q.val);
		q.val--;
		printf("producer:: appending\n");
		sleep(2);
		printf("producer:: appended\n");
//		V(q);
		q.val++;
		printf("producer:: made it available for consumer\n");
//		V(i);
		i.val++;
		printf("producer:: available items:%d\n",i.val);
	}
}
void* consume(){
	while(itemsc--){
		printf("consumer:: waiting for producer to make something available to consume\n");
//		P(i);
		while(i.val==0);
		printf("consumer:: wait has ended\n");
//		P(q);
		while(!q.val);
		q.val--;
		printf("consumer:: taking it\n");
		sleep(1);
		printf("consumer:: taken\n");
		i.val--;
		printf("consumer:: items left:%d\n",i.val);
//		V(q);
		q.val++;
		printf("consumer:: consuming\n");
		sleep(2);
		printf("consumer:: consumed\n");
	}
}

int main(){
	i.val=0;
	q.val=1;
	printf("Enter itmes to produce and consume:");
	scanf("%d %d",&itemsp,&itemsc);
	pthread_t c,p;
	int cons=pthread_create(&c,NULL,consume,NULL);
	int prod=pthread_create(&p,NULL,produce,NULL);
	while(1);
	return 0;
}
