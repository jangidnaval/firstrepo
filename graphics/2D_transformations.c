/*
Arun kumar
20158050
Information Technology(5th Sem)
MNNIT Allahabad

2-d Transformations For a Polygon & Circle

*/


#include<stdio.h>
#include<graphics.h>
#include<math.h>

#define SIN(x) sin(x * 3.141592653589/180)
#define COS(x) cos(x * 3.141592653589/180)


void translate(float a[][2],int tx,int ty,int n)
{
     int i=0;
     setcolor(WHITE);
    printf("Original-WHITE\n");
    for(i=0;i<n-1;i++){
    	line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
    	delay(300);
    }
    line(a[n-1][0],a[n-1][1], a[0][0], a[0][1]);
    delay(300);

        while(i<n){
                a[i][0]+=(float)tx;
                a[i][1]+=(float)ty;
                i++;
        }
     setcolor(RED);
    printf("Translate-RED\n");
    for(i=0;i<n-1;i++){
    	line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
    	delay(300);
    }
    line(a[n-1][0],a[n-1][1], a[0][0], a[0][1]);
    delay(300);

}



void rotate(float a[][2], int n, int x_pivot,
                      int y_pivot, int angle)
{

    int i = 0;
    while (i < n)
    {
        int x_shifted = a[i][0] - x_pivot;
        int y_shifted = a[i][1] - y_pivot;
        a[i][0]= x_pivot + (x_shifted*COS(angle)
                          - y_shifted*SIN(angle));
        a[i][1] = y_pivot + (x_shifted*SIN(angle)
                          + y_shifted*COS(angle));
        i++;
    }
    setcolor(GREEN);
    printf("Rotation-GREEN\n");
    for(i=0;i<n-1;i++){
    	line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
    	delay(300);
    }
    line(a[n-1][0],a[n-1][1], a[0][0], a[0][1]);
    delay(300);
}




void findNewCoordinate(int s[][2], int p[][1])
{
    int i,j,k,temp[2][1] = { 0 };

    for (i = 0; i < 2; i++)
        for (j = 0; j < 1; j++)
            for (k = 0; k < 2; k++)
                temp[i][j] += (s[i][k] * p[k][j]);

    p[0][0] = temp[0][0];
    p[1][0] = temp[1][0];
}

void scale(int x[], int y[], int sx, int sy,int n)
{


    int s[2][2] = { sx, 0, 0, sy };
    int p[2][1];
    int i;

    for ( i = 0; i < n; i++)
    {
        p[0][0] = x[i];
        p[1][0] = y[i];

        findNewCoordinate(s, p);

        x[i] = p[0][0];
        y[i] = p[1][0];
    }

    setcolor(YELLOW);
    printf("Scaling-YELLOW\n");
    for(i=0;i<n-1;i++){
    	line(x[i],y[i],x[i+1],y[i+1]);
    	delay(300);
    }
    line(x[i],y[i],x[0],y[0]);
    delay(300);

}


void drawCircle(int xc, int yc, int x, int y,int c)
{
    putpixel(xc+x, yc+y,c);
    putpixel(xc-x, yc+y,c);
    putpixel(xc+x, yc-y,c);
    putpixel(xc-x, yc-y,c);
    putpixel(xc+y, yc+x,c);
    putpixel(xc-y, yc+x,c);
    putpixel(xc+y, yc-x,c);
    putpixel(xc-y, yc-x,c);
}


void circleBres(float xc, float yc, float r,int c)
{
    float x = 0.0, y = r;
    float d = 3.0 - 2.0 * r;
    while (y >= x)
    {

        drawCircle(xc, yc, x, y,c);
        x++;
        if (d > 0.0)
        {
            y--;
            d = d + 4.0 * (x - y) + 10.0;
        }
        else
            d = d + 4.0 * x + 6.0;
        drawCircle(xc, yc, x, y,c);
        delay(80);
    }
}



int main()
{
    int n,i;
    printf ("Enter the sides of polygon (-1 for circle)\n");
    scanf("%d",&n);

    if(n==-1)
    {
    	int r,xc,yc,angle,sx,tx,ty,c;
     	printf("Enter the radius of circle\n");
     	scanf("%d",&r);
     	printf("Enter the coordinate of center of circle\n");
     	scanf("%d %d",&xc,&yc);


     	printf("Enter Rotation Angle\n");
    	scanf("%d",&angle);


    	printf("Enter Translation\n");
        scanf("%d %d",&tx,&ty);

    	printf("Enter Scaling factor\n");
    	scanf("%d",&sx);

    	int gd=DETECT,gm;

    	initgraph(&gd,&gm,"");

    	setcolor(WHITE);
    	printf("Original-WHITE\n");
    	//circle(xc, yc, r);
    	circleBres(xc, yc, r,15);

    	setcolor(BLUE);
    	printf("Translate-BLUE\n");
    	//circle(xc+tx, yc+ty, r);
    	circleBres(xc+tx, yc+ty, r,1);

    	setcolor(RED);
    	printf("Scale-RED\n");
    	//circle(xc, yc, r*sx);
    	circleBres(xc, yc, r*sx,4);

    	setcolor(GREEN);
    	printf("Rotate-GREEN\n");
    	//circle(xc*COS(angle)-yc*SIN(angle),xc*SIN(angle)+ yc*COS(angle), r);
    	circleBres(xc*COS(angle)-yc*SIN(angle),xc*SIN(angle)+ yc*COS(angle), r,2);

  		getch();
    	closegraph();

    }

    else{

    	int x[n],y[n],sx,sy,tx,ty,angle;

    	printf("Enter the coordinates of polygon\n");
    	for(i=0;i<n;i++)
    		scanf("%d %d",&x[i],&y[i]);

    	float coor[n][2];
    	for(i=0;i<n;i++){
    		coor[i][0]=x[i];
    		coor[i][1]=y[i];
    	}
    	printf("Enter Rotation Angle\n");
    	scanf("%d",&angle);


    	printf("Enter Translation\n");
        scanf("%d %d",&tx,&ty);

    	printf("Enter Scaling factor\n");
    	scanf("%d %d",&sx,&sy);

    	int gd, gm;
    	detectgraph(&gd, &gm);
    	initgraph(&gd, &gm," ");

    	translate(coor,tx,ty,n);
    	scale(x, y, sx,sy,n);
    	rotate(coor,n, 100, 100,angle);

    	getch();
    	closegraph();

    }
    return 0;
}
