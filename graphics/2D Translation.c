//C Program to demonstrate Translation of 2D objects
#include<stdio.h>
#include<graphics.h>

/*void rectangle (int a,int b, int c, int d)
{
line(a,b,c,b);
line(c,b,c,d);
line(c,d,a,d);
line(a,d,a,b);
return;
}*/

void translateRectangle(int P[][2],int T[])
{
setcolor(2);
rectangle( P[0][0] , P[0][1] , P[1][0] , P[1][1] );
P[0][0]+=T[0];
P[1][0]+=T[0];
P[0][1]+=T[1];
P[1][1]+=T[1];
setcolor(3);
rectangle( P[0][0] , P[0][1] , P[1][0] , P[1][1] );
//closegraph();
}

int main()
{
int gd, gm;
detectgraph(&gd, &gm);
initgraph(&gd, &gm," ");
int P[2][2]={50,100,150,200};   //  { (Xmin Ymin),(Xmax Ymax) }
int T[]={30,20};
translateRectangle(P,T);
getch();
getch();
return 0;
}

