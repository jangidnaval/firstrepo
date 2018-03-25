#include<stdio.h>
#include<stdlib.h>

#define SYS 0
#define USE 1

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

void swap(int x[], int i, int j)
{
int t = x[i];
x[i] = x[j];
x[j] = t;
}

void sort(int a[], int b[], int p[], int pr[],int queue[], int n)
{
int i,j;
for(i=0;i<n;i++)
{
	for(j=i+1;j<n;j++)
	{
		if(a[j]<a[i]) {
		swap(a, i, j); swap(b, i, j);
		swap(p, i, j);swap(pr, i, j);
		swap(queue, i, j);
		}
		else if(a[i]==a[j] && queue[j]<queue[i]) {
		swap(a,i,j); swap(b,i,j); swap(p,i,j);swap(pr, i, j);swap(queue, i, j);}
		else if(a[i]==a[j] && queue[j]==queue[i] && pr[j]<pr[i]) {
		swap(a,i,j); swap(b,i,j); swap(p,i,j);swap(pr, i, j);swap(queue, i, j);}
	}
}
}

void sort2(int ppr[], int qq[])
{
int i,j;
for(i=f;i<l;i++)
{
	for(j=i+1;j<l;j++)
	{
		if(qq[q[j]-1]<qq[q[i]-1]) {
			swap(q, i, j); swap(q2, i, j);	
		}
		else if(qq[q[j]-1]==qq[q[i]-1] && ppr[q[j]-1]<ppr[q[i]-1]) {
		swap(q, i, j); swap(q2, i, j);
		}
	}
}
}



int main()
{
	int n;
	scanf("%d", &n);
	int p[n];
	int a[n], b[n];
	int pr[n], ppr[n];
	int at[n];
	int burs[n];
	int i;
	
	int queue[n];
	int qq[n];
	
	int y = 10000;
	
	for(i=0;i<n;i++) {
	p[i] = i+1;
	printf("Process %d --- ",p[i]);
	scanf("%d%d%d%d", &a[i], &b[i], &pr[i], &queue[i]);
	ppr[i] = pr[i];
	qq[i] = queue[i];
	y = y>a[i]?y = a[i]:y;
	at[i] = a[i];
	burs[i] = b[i];
	}
	
	sort(a, b, p, pr, queue, n);
	
	i = 0;
	
	while(i<n && a[i]==y) {
	add(p[i], b[i]);i++;}
	
	int tat[n], ct[n], wt[n];
	
	printf("\n\n---------SCHEDULING------------\n\n");
	
	int pid;
	int schedule[100];
	int k = y;
	
	while((pid = poll())!=-1)
	{
	int bur = poll2();
	//printf("%d %d %d\n", pid, bur, y);
	y++;
	schedule[y] = pid;
	bur--;
	if(bur==0) {
		ct[pid-1] = y;
	}
	else add(pid, bur);
	
	
	if(i<n && f==l && y<a[i]) {
		while(y<a[i]) {
		y++;schedule[y] = 10000;}
	}
	
	if(i<n && y==a[i]) {
		add(p[i], b[i]); i++;
	}
	
	sort2(ppr,qq);
	}
	
	y++;
	schedule[y] = 1000000;
	
	int xx = k;
	for(i=k+2;i<=y;i++)
	{
		if(schedule[i]!=schedule[i-1]) {
			if(schedule[i-1]==10000)
			{printf("IDLE --- %d %d\n", xx, i-1);}
			else
			{printf("Process %d --- %d %d\n", schedule[i-1], xx, i-1);}
			xx = i-1;
		}
	}
	
	printf("\n-----TAT WT------\n\n");
	for(i=0;i<n;i++)
	{
		tat[i] = ct[i]-at[i];
		wt[i] = tat[i] - burs[i];
		printf("Process %d ----- TAT = %d, WT = %d\n", i+1, tat[i], wt[i]);
	}
	
	return 0;
}



	
	 

