//2D TRANSLATION
#include<stdio.h>
#include<graphics.h>
#include<math.h>
int main()
{
int graphdriver=DETECT,graphmode,errorcode;
int i;
int x2=200,y2=250,x1=50,y1=100,x=200,y=200;
//printf("Enter the 2 line end points:");
//printf("x1,y1,x2,y2 : ");
//scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
initgraph(&graphdriver,&graphmode," ");
//printf("Enter scaling co-ordinates ");
//printf("x,y");
//scanf("%d%d",&x,&y);
setcolor(2);
line(x1,y1,x2,y2);
x1=(x1+x);
y1=(y1+y);
x2=(x2+x);
y2=(y2+y);
printf("Line after scaling");
setcolor(3);
line(x1,y1,x2,y2);
getch();
closegraph();
return 0;
}
