#include<stdio.h>
int main()
{
  int i,j,n=4,time,sum_wait=0,sum_turnaround=0;
  int smallest,remain;
  remain=n;
  int at[4]={0,2,1,3};
  int bt[4]={24,3,3,7};
  int priority[4]={3,1,2,4};
  
  printf("\n\nProcess\tArrival Time\tTurnaround time\twaiting time\n");
  for(time=0;remain!=0;)
  {
    smallest=3;
    for(i=0;i<n;i++)
    {
      if(at[i]<=time && priority[i]<priority[smallest] && bt[i]>0)
      {
        smallest=i;
      }
    }
    time+=bt[smallest];
    remain--;
    printf("P%d\t\t%d\t\t%d\t\t%d\n",smallest+1,at[smallest],time-at[smallest],time-at[smallest]-bt[smallest]);
    sum_wait+=time-at[smallest]-bt[smallest];
    sum_turnaround+=time-at[smallest];
    bt[smallest]=0;
  }
  printf("\nAvg waiting time = %f\n",sum_wait*1.0/n);
  printf("Avg turnaround time = %f",sum_turnaround*1.0/n);
  return 0;
}
