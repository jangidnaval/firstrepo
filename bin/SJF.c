//Jyot Mehta,20154135
//Date: 30 Aug '17
//SJF Scheduling Algorithm for processes with same arrival time
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct proc Process;
struct proc{
	int pid;
	int bt; //bt is burst time of process with i as its relative pid
	int tat;
	int wt;
};
int comp1(const void *a,const void *b)
{
	Process *p1=(Process *)a,*p2=(Process *)b;
	return p1->bt-p2->bt;
}
int comp2(const void *a,const void *b)
{
	Process *p1=(Process *)a,*p2=(Process *)b;
	return p1->pid-p2->pid;
}
int main()
{ 
	Process p[100];
	int n;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	printf("Enter burst times of processes:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p[i].bt);
		p[i].pid=i+1;
	}
	//Since SJF therefore it will run with min BT first and without premption
	//completion time (ct) will be equal to Turn around time(tat) as at = 0
	int curr_time=0;
	qsort(p,n,sizeof(Process),comp1);
	for(int i=0;i<n;i++)
	{
		p[i].tat=curr_time+p[i].bt;
		p[i].wt=curr_time;
		curr_time+=p[i].bt;
	}
	qsort(p,n,sizeof(Process),comp2);
	printf("Process\t\tTAT\t\tWT\n");
	for(int i=0;i<n;i++)
		printf("P%d\t\t%d\t\t%d\n",p[i].pid,p[i].tat,p[i].wt);
	return 0;
}
