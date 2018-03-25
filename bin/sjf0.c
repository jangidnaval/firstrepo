#include<stdio.h>
#include<string.h>

struct ps{
		int p,id;
		int bt;
		int ct;
		int tat, wt;
		};

int compare( void *a, void *b)
{

 struct ps *x=(struct  ps*) a;
struct ps *y=(struct  ps*) b;

if(x->bt > y->bt){
return 1;}

else	if(x->bt < y->bt)
			return -1;
else
	return 0;


}

int main(){


int n,i;

float sum_tat=0,sum_wt=0;

printf("enter n\n");
scanf("%d",&n);

struct ps process[n];


printf("Enter  BT\n");

for(i=0;i<n;i++)
{scanf("%d",&process[i].bt);
process[i].id=i;}

qsort(process,n,sizeof(process[0]),compare);

for( i=0;i<n;i++)
printf("%d    %d\n",process[i].p,process[i].bt);



int temp=0;
for( i=0;i<n;i++)
	{
	
	process[i].ct=temp+process[i].bt;
	temp=process[i].ct;
	process[i].tat=process[i].ct-process[i].at;
	process[i].wt=process[i].tat-process[i].bt;
	sum_tat+=process[i].tat;
	sum_wt+=process[i].wt;
	}
printf("id		tat		wt  \n");
for( i=0;i<n;i++)
printf("%d		%d		%d\n",process[i].id,process[i].tat,process[i].wt);

printf("avg tat= %f \n",sum_tat/n);

printf("avg wt= %f ",sum_wt/n);


}
