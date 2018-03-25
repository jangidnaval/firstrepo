 #include<stdio.h>
 
 int main()
{
int p[20],bt[20], su[20];
int wt[20],tat[20],i, k, n, temp;
float wtavg, tatavg;
printf("Enter n\n");
scanf("%d",&n);

printf("Burst Time  and type(0-system,1-user)\n ");
for(i=0;i<n;i++)
{
p[i] = i;
scanf("%d%d",&bt[i],&su[i]);
}

for(i=0;i<n;i++)
  {for(k=i+1;k<n;k++)
	if(su[i] > su[k])
	{
	temp=p[i];
	p[i]=p[k];
	p[k]=temp;
	
	temp=bt[i];
	bt[i]=bt[k];
	bt[k]=temp;
	
	temp=su[i];
	su[i]=su[k];
	su[k]=temp;
	}
}



wtavg = wt[0] = 0;
tatavg = tat[0] = bt[0];
for(i=1;i<n;i++)
{
wt[i] = wt[i-1] + bt[i-1];
tat[i] = tat[i-1] + bt[i];
wtavg = wtavg + wt[i];
tatavg = tatavg + tat[i];
}
printf("\nprocess\tsys/user \tbt\ttat\twt");
for(i=0;i<n;i++)
printf("\n%d\t%d\t%d\t%d\t%d ",p[i],su[i],bt[i],tat[i],wt[i]);
printf("\navgwt %f",wtavg/n);
printf("\navgtat%f",tatavg/n);
return 0;
}

