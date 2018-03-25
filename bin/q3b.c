#include<stdio.h>
struct p{
	int at,bt,id,ct;
	int tat,wt;
};

struct a{
		int r_bt;
		int id;

};

void fun(struct p process[],int tq,int n)
{

printf("For TQ =%d\n",tq);

struct a arr[1000]; 
int k=0;
int j=n;
int i=0;
for(i=0;i<n;i++)
	{arr[i].r_bt=process[i].bt;
		arr[i].id=i;}
	
FILE *fp1=fopen("tat.dat","a");

FILE *fp2=fopen("wt.dat","a");	
	
		
i=0;		

while(i!=j)
{
if(arr[i].r_bt-tq==0)
	{process[arr[i].id].ct=k+tq;;
	//printf("in complete %d %d\n", arr[i].id,k);
		k=k+tq;
		i++;}
	
else
if(arr[i].r_bt-tq>0 && process[i].at>=k)
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

float avgtat=0,avgwt=0;		
for(i=0;i<n;i++)
{process[i].tat=process[i].ct;
process[i].wt=process[i].tat-process[i].bt;
avgtat+=process[i].tat;
avgwt+=process[i].wt;

}
printf("Pid\tCT\tTAT\tWT\n");
for(i=0;i<n;i++)
printf("%d\t%d\t%d\t%d\n",process[i].id,process[i].ct,process[i].tat,process[i].wt);	
	printf("\n");

printf("Average TAT =%f and Average WT =%f \n\n",avgtat/n,avgwt/n);	

fprintf(fp1,"%d\t%f\n",tq,avgtat/n);
    fclose(fp1);
fprintf(fp2,"%d\t%f\n",tq,avgwt/n);
	fclose(fp2);
}




int main()
{
int n,i;

printf("enter n\n");
scanf("%d",&n);


struct p process[n];

printf("Enter AT and BT\n");
for( i=0;i<n;i++)
{scanf("%d%d",&process[i].at,&process[i].bt);
process[i].id=i;}
int tq;

//printf("Enter TQ\n");
//scanf("%d",&tq);

fun(process,1,n);
fun(process,2,n);
fun(process,3,n);







}
