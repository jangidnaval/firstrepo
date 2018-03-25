#include<stdio.h>
//Round Robin

int main()
{
 int bt[20],p[20],tat[20],wt[20],rem[20];
 int i,j;
  int n;
  printf("Enter the no of processes\n");
  scanf("%d",&n);
  printf("Enter the burst time of each processes\n");
  for(i=0;i<n;i++)
  {
  
  scanf("%d",&bt[i]);
  p[i]=i+1;
  rem[i]=bt[i];
  }
  
  int tq;
  printf("Enter time slice\n");
  scanf("%d",&tq);
  
 
  int flag;
  int t=0;
  while(1)
  {
   flag=-1;
   for(i=0;i<n;i++)
  {
    if(rem[i]>0){
   if(rem[i]>tq)
   {
   flag=0;
     
     
    rem[i]-=tq;
    t+=tq;
    }
    else
    {
     flag=0;
    t+=rem[i];
     tat[i]=t;
    rem[i]=0;
   
    }
    }}
    if(flag==-1)
    break;}
    
    printf("tat for different processes\n");
    for(i=0;i<n;i++)
    printf("%d\n",tat[i]);
    
     wt[0]=0;
     
    for(int i=1;i<n;i++)
      wt[i]=wt[i-1]+tq;
      
      printf("\n");
      
      printf("wt for different process\n");
      for(i=0;i<n;i++)
      printf("%d\n",wt[i]);
    
    return 0;
    }
    
    
    
    
    
    
    
    
    
   
  
