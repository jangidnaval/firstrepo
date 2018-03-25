#include<stdio.h>
#include<stdlib.h>

int q[100];
int q2[100];
int f, l;

int poll()
{
if(f==l) return -1;
return q[f];
}
int poll2()
{
if(f==l) return -1;

return q2[f++];

}

void add(int p, int t)
{
q[l] = p;
q2[l] = t;
l++;
}

int b[] = {24,3,3,7};
int tat[4];
int wt[4];
int at[4];
int arr[4] = {0};

int main()
{
	f = l = 0;
	
	add(1,24);
	add(2,3);
	add(3,3);
	add(4,7);
	
	
	int ct;
	int y = 2;
	int po, ti;
	
	int t = 2;
	
	while((po=poll())!=-1)
	{
		int burst = poll2();
		
		
		int till = burst<t?y+burst:y+t;
		if(f==l)
		{
		till = burst+y;
		}
		burst = burst<t?0:burst-t;
		if(f==l) burst = 0;
		
		printf("Process %d --- %d %d \n ", po, y, till);
		y = till;
		
		if(burst>0)
		add(po, burst);
		
		
		if(burst==0) {
		int at = 2;
		ct = y;
		tat[po-1] = ct-at;
		wt[po-1] = tat[po-1]-b[po-1];
		if(wt[po-1]<0) wt[po-1] = 0;
		}
	}
	printf("\n");
	int i;
	for(i=0;i<4;i++)
	{
		printf("Process %d ", i+1);
		printf("TAT = %d, WT = %d\n", tat[i], wt[i]);
	}
	return 0;
}



