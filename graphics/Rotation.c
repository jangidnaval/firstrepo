//2D ROTATION
#include<stdio.h>
#include<graphics.h>
#include<math.h>
int main()
{
 int graphdriver=DETECT,graphmode,errorcode;
int i;
int x2=200,y2=200,x1=300,y1=300,x=30,y=30,xn,yn;
double r11,r12,r21,r22,th;
//printf("Enter the 2 line end points:");
//printf("x1,y1,x2,y2");
//scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
initgraph(&graphdriver,&graphmode,"c:\\tc\\bgi");
line(x1,y1,x2,y2);
printf("\n\n\n[ Enter the angle : ");
scanf("%lf",&th);
r11=cos((th*3.1428)/180);
r12=sin((th*3.1428)/180);
r21=(-sin((th*3.1428)/180));
r22=cos((th*3.1428)/180);
//printf("%lf  %lf  %lf  %lf",r11,r12,r21,r22);
xn=((x2*r11)-(y2*r12));
yn=((x2*r12)+(y2*r11));
line(x1+x,y1+y,xn+x,yn+y);
getch();
closegraph();
return 0;
}
