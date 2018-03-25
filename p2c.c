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

void swap(int x[], int i, int j)
{
int t = x[i];
x[i] = x[j];
x[j] = t;
}

void sort(int a[], int b[], int p[], int n)
{
int i,j;
for(i=0;i<n;i++)
{
	for(j=i+1;j<n;j++)
	{
		if(a[j]<a[i]) {
		swap(a, i, j); swap(b, i, j);
		swap(p, i, j);
		}
		else if(a[i]==a[j] && b[j]<b[i]) {
		swap(a,i,j); swap(b,i,j); swap(p,i,j);}
	}
}
}

void sort2()
{
int i,j;
for(i=f;i<l;i++)
{
	for(j=i+1;j<l;j++)
	{
		if(q2[j]<q2[i]) {
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
	int at[n];
	int burs[n];
	int i;
	
	int y = 10000;
	
	a[0] = 0; a[1] = 2; a[2] = 1; a[3] = 3;
	b[0] = 24; b[1] = 3; b[2] = 3; b[3] = 7;
	
	for(i=0;i<n;i++) {
	p[i] = i+1;
	//printf("Process %d --- ",p[i]);
	//scanf("%d%d", &a[i], &b[i]);
	y = y>a[i]?y = a[i]:y;
	at[i] = a[i];
	burs[i] = b[i];
	}
	
	
	
	sort(a, b, p, n);
	
	i = 0;
	
	while(i<n && a[i]==y) {
	add(p[i], b[i]);i++;}
	
	int tat[n], ct[n], wt[n];
	
	int t;
	scanf("%d", &t);
	
	printf("\n\n---------SCHEDULING------------\n\n");
	
	int pid;
	int schedule[100];
	int k = y;
	
	int j;
	
	while((pid = poll())!=-1)
	{
	int bur = poll2();
	//printf("%d %d %d\n", pid, bur, y);
	y++;
	
	int min = t<bur?y+t-1:y+bur-1;
	bur = t<bur?bur-t:0;
	while(y<min)
		schedule[y++] = pid;
	schedule[y] = pid;
	
	//printf("%d %d\n", y, min);
	
	int ccct = y;
	if(i<n && y>=a[i]) {
		while(i<n && y>=a[i])
		{add(p[i], b[i]); i++;}
	}
	
	if(bur==0) {
		ct[pid-1] = ccct;
	}
	else add(pid, bur);
	
	
	if(i<n && f==l && y<a[i]) {
		while(y<a[i]) {
		y++;schedule[y] = 10000;}
	}
	//sort2();
	}
	
	//printf("%d\n", y);
	
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
	
	double avt = 0;
	double avw = 0;
	for(i=0;i<n;i++) {
		avt+=tat[i];
		avw+=wt[i];
	}
	avt/=n;
	avw/=n;
	
	FILE *ftat = fopen("ftat", "a");
	FILE *fwt = fopen("fwt", "a");
	
	fprintf(ftat, "%d %lf\n", t, avt);
	fprintf(fwt, "%d %lf\n", t, avw);
	
	return 0;
}



	
	 

