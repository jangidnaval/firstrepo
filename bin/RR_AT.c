//Jyot Mehta,20154135
//Date: 30 Aug '17
//RR Scheduling Algorithm for processes with different arrival time
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TQ 2
#define MAX 5000
typedef struct proc Process;
struct proc{
	int pid;
	int bt; //bt is burst time of process with i as its relative pid
	int bt_copy;
	int tat;
	int ct;
	int at;
	int wt;
};

int proc_count = 0;
//Functions of queue

int readyQ[MAX];
int front=-1,rear=-1;
void enQ(int data)
{
	if(rear==MAX-1) //if full
	{
		printf("Queue is full!!");
		return;
	}
	if(front==-1&&rear==-1)
		front++;
	readyQ[++rear]=data;
	return;		
}
int deQ()
{
	if(front>rear||front<0) //if empty
		return -1;
	int ele = readyQ[front];
	front++;
	if(front>rear)
		front=rear=-1;
	return ele;
}

//to sort on basis of arrival time
int comp1(const void *a,const void *b)
{
	Process *p1=(Process *)a,*p2=(Process *)b;
	return p1->at-p2->at;
}
//to sort on basis of pid
int comp2(const void *a,const void *b)
{
	Process *p1=(Process *)a,*p2=(Process *)b;
	return p1->pid-p2->pid;
}
int main()
{ 
	Process p[100]; //array of processes
	int n;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	proc_count = n;
	printf("Enter arrival times and burst times of processes:\n");
	for(int i=0;i<n;i++)
	{
		scanf(" %d %d",&p[i].at,&p[i].bt);
		p[i].pid=i;
		p[i].bt_copy = p[i].bt;
	}
	//Since RR therefore it will run for min(bt,tq) and then preempt and will be put in readyQ
	int curr_time=0;
	qsort(p,n,sizeof(Process),comp1);
	enQ(p[0].pid);
	int curr_count = 1;
	while(front<=rear&&front>=0) //while queue not empty
	{
		
		//printf("Curr_time = %d\n",curr_time);
		if(front==rear&&proc_count==curr_count) //only one process left and all other process have finished
		{
			int curr_proc = deQ();
			p[curr_proc].ct = curr_time+p[curr_proc].bt;
			p[curr_proc].tat = p[curr_proc].ct-p[curr_proc].at;
			p[curr_proc].wt = p[curr_proc].tat-p[curr_proc].bt_copy;
			break;
		}
		int curr_proc = deQ();
		//printf("curr_proc = %d\n",curr_proc);
		if(p[curr_proc].bt>TQ) //the process will be preempted
		{
			p[curr_proc].bt-=TQ;
			curr_time+=TQ;
			
			//checking for processes, if they are arriving or not
			for(int i=curr_count;i < proc_count;i++)
			{
				if(p[i].at<=curr_time)
				{
					curr_count++;
					enQ(i);
				}
				else
					break;
			}
			
			//enQuing currently preempted process
			enQ(curr_proc);	
		}
		else //the process will be terminated after its burst time is finished
		{
			
			//calculating values for terminated process
			p[curr_proc].ct = curr_time+p[curr_proc].bt;
			p[curr_proc].tat = p[curr_proc].ct-p[curr_proc].at;
			p[curr_proc].wt = p[curr_proc].tat-p[curr_proc].bt_copy;
			p[curr_proc].bt = 0;
		
			curr_time=p[curr_proc].ct; //updating the current time according to the burst time
	
			 
			//checking for processes, if they are arriving or not
			for(int i=curr_count;i<proc_count;i++)
			{
				if(p[i].at<=curr_time)
				{
					curr_count++;
					enQ(i);
				}
				else
					break;
			}
		   //no enQuing
		}		
	}
	qsort(p,n,sizeof(Process),comp2);
	printf("Process\t\tTAT\t\tWT\n");
	for(int i=0;i<n;i++)
		printf("P%d\t\t%d\t\t%d\n",p[i].pid,p[i].tat,p[i].wt);
	return 0;
}
