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
int pr[] = {3, 1, 2, 4};

void swap(int x[], int i, int j)
{
int t = x[i];
x[i] = x[j];
x[j] = t;
}

void sort()
{
int i,j;
for(i=f;i<l;i++)
{
	for(j=i+1;j<l;j++)
	{
		if(pr[q[j]-1]<pr[q[i]-1]) {
		swap(q, i, j); swap(q2, i, j);
		}
	}
}
}


int main()
{
	f = l = 0;
	add(2,3);
	add(3,3);
	add(4,7);
	add(1,24);
	
	sort();	
	
	int tat, wt;
	int ct, at;
	int y = 2;
	int po, ti;
	while((po=poll())!=-1)
	{
		ti = poll2();
		printf("Process %d --- %d %d  ", po, y, ti+y);
		y = ti+y;
		
		at = 2;
		ct = y;
		tat = ct-at;
		wt = tat-b[po-1];
		if(wt<0) wt = 0;
		printf("TAT = %d, WT = %d\n", tat, wt);
	}	
}



