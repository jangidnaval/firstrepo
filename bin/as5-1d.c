#include<stdio.h>

//Priority scheduling

int main()
{
   int bt[20],wt[20],tat[20],p[20],pr[20];
   int n,i,j;
  
   
   printf("enter the no of processes\n");
   scanf("%d",&n);
   
   printf("enter the burst time and priority\n");
   for( i=0;i<n;i++)
   {
   p[i]=i+1;
   scanf("%d",&bt[i]);
   scanf("%d",&pr[i]);
   }
   wt[0]=0;
   
   //selection sort based on priority
    int temp,pos;
   
   for(i=0;i<n-1;i++)
   {
   pos=i;
   for(j=i+1;j<n;j++)
   {
   if(pr[j]>pr[pos])
      pos=j;
      }
      
    temp=pr[i];
    pr[i]=pr[pos];
    pr[pos]=temp;
    
    temp=p[i];
    p[i]=p[pos];
    p[pos]=temp;
    
    temp=bt[i];
    bt[i]=bt[pos];
    bt[pos]=temp;
    }
    
    tat[0]=bt[0];
    wt[0]=0;
    
    printf("\n");
    
    for(int i=0;i<n;i++)
    printf("%d\n",bt[i]);
    
    
    for(i=1;i<n;i++)
    {
     tat[i]=tat[i-1]+bt[i];
     wt[i]=wt[i-1]+bt[i-1];
     }
     
     printf("turn around time --\n");
     for(i=0;i<n;i++)
       printf("%d",tat[i]);
       
       printf("\n");
       
       printf("waiting time--\n");
        for(i=0;i<n;i++)
       printf("%d\n",wt[i]);
       
       return 0;
       }
     
    
      
    
    
    
    
    
    
    
    
    
    
