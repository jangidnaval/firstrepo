#include<stdio.h>
struct p{
	int bt,id,ct;
	int tat,wt;
};

struct a{
		int r_bt;
		int id;

};

void fun(struct p process[],int tq,int n)
{

printf("in fun");

struct a arr[1000]; 
int k=0;
int j=n;
int i=0;
for(i=0;i<n;i++)
	{arr[i].r_bt=process[i].bt;
		arr[i].id=i;}
		
i=0;		
while(i!=j)
{
printf("in while loop %d %d\n", arr[i].id,k);


if(arr[i].r_bt-tq==0)
	{process[arr[i].id].ct=k+tq;;
	printf("in complete %d %d\n", arr[i].id,k);
		k=k+tq;
		i++;}
	
else
if(arr[i].r_bt-tq>0)
		{arr[j].id=arr[i].id;
			arr[j].r_bt=arr[i].r_bt-tq;
			k+=tq;
			i++;
			j++;}	
	
else
		{process[arr[i].id].ct=k+arr[i].r_bt;
		k+=arr[i].r_bt;
		i++;}
}		


for(i=0;i<n;i++)
printf("%d\t%d\n",process[i].id,process[i].ct);	
	
}




int main()
{
int n,i;

printf("enter n\n");
scanf("%d",&n);

struct p process[n];

printf("Enter BT\n");
for( i=0;i<n;i++)
{scanf("%d",&process[i].bt);
process[i].id=i;}
int tq;

printf("Enter TQ\n");
scanf("%d",&tq);

fun(process,tq,n);







}
