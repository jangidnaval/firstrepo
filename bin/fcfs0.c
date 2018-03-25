#include<stdio.h>
#include<string.h>


int main(){

int at[100]={0};
int wt[100],ct[100];
int p[100],bt[100];
int n,i;
int tat[100];
float sum_tat=0,sum_wt=0;
printf("enter n");

scanf("%d",&n);

printf("enter BT for proceses\n");
for( i=0;i<n;i++)
	scanf("%d",&bt[i]);

int temp=0;
for( i=0;i<n;i++)
	{ct[i]=temp+bt[i];
	temp=ct[i];
	tat[i]=ct[i]-at[i];
	wt[i]=tat[i]-bt[i];
	sum_tat+=tat[i];
	sum_wt+=wt[i];
	}
printf("tat		wt  \n");
for( i=0;i<n;i++)
printf("%d		%d\n",tat[i],wt[i]);

printf("avg tat= %f \n",sum_tat/n);

printf("avg wt= %f ",sum_wt/n);
}

