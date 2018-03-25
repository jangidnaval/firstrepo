#include<stdio.h>

int INSIDE=0,TOP=8,BOTTOM=4,RIGHT=2,LEFT=1;
int xmin=2,ymin=3,xmax=8,ymax=6;
int c=1;

int findcode(double x,double y)
{
int code=INSIDE;
	if(x<xmin)			code |= LEFT;
	else if(x>xmax)		code |= RIGHT;
	
	if(y<ymin)			code |= BOTTOM;
	else if(y>ymax)		code |= TOP;
	
return code;
}
	
void cslca(double x1,double y1,double x2,double y2)
{
	int code1=findcode(x1,y1);
	int code2=findcode(x2,y2);
	//printf("%d\t%d\n",code1,code2);
	int ans=0;

	while(1)
	{
		if(code1==0 && code2==0)
		{
			ans=1;
			break;
		}
		else if (code1 & code2)
			break;
		else
		{
			double x,y;
			int code;
		
			if(code1!=0)	code=code1;
			else code=code2;
			
			 if (code & TOP)
            {
                // point is above the clip rectangle
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (code & BOTTOM)
            {
                // point is below the rectangle
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (code & RIGHT)
            {
                // point is to the right of rectangle
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else if (code & LEFT)
            {
                // point is to the left of rectangle
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }
            
            if(code==code1)
            {
            	x1=x;
            	y1=y;
            	code1=findcode(x1,y1);
            }
            else
            {
            	x2=x;
            	y2=y;
            	code2=findcode(x2,y2);
           }
		}
	}
	
	if(ans)			printf("Line lies completely inside from (%.2f,%.2f) to (%.2f,%.2f)\n",x1,y1,x2,y2);
	else			printf("Line lies completely outside.\n");
return;
}

int main()
{
printf("Rectangle End Points :\n\t\t(2,3)\t\t(8,2)\n\n\n\t\t(2,6)\t\t(8,6)\n\n");

//L1	(4,4) to (7,5)		//Completely inside
printf("\nL%d : (4,4) to (7,5)\n",c++);
cslca(4,4,7,5);
//L2	(0,2) to (1,5)		//Completely outside
printf("\nL%d : (0,2) to (1,5)\n",c++);
cslca(0,2,1,5);
//L3	(1,4) to (4,3.5)		//One Endpoint inside
printf("\nL%d : (1,4) to (4,3.5)\n",c++);
cslca(1,4,4,3.5);
//L4	(10,4) to (6,8)		//Tangent at (8,6)
printf("\nL%d : (10,4) to (6,8)	\n",c++);
cslca(10,4,6,8);
//L5	(7,2) to (10,5)		//Intersecting Line
printf("\nL%d : (7,2) to (10,5)\n",c++);
cslca(7,2,10,5);
//L6	(5,1) to (5,7)		//Intersecting Line 
printf("\nL%d : (5,1) to (5,7)\n",c++);
cslca(5,1,5,7);

return 0;
}
