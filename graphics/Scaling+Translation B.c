// C program to demonstrate Scaling+Translation of 2D Objects - Square
#include<stdio.h>
#include<graphics.h>
 
// Matrix Multiplication to find new Coordinates.
// s[][] is scaling matrix. p[][] is to store
// points that needs to be scaled.
// p[0][0] is x coordinate of point.
// p[1][0] is y coordinate of given point.
void findNewCoordinate(int s[][2], int p[][1])
{
    int temp[2][1] = { 0 } , i,j,k;
 
    for (i = 0; i < 2; i++)
        for (j = 0; j < 1; j++)
            for (k = 0; k < 2; k++)
                temp[i][j] += (s[i][k] * p[k][j]);
 
    p[0][0] = temp[0][0];
    p[1][0] = temp[1][0];
}
 
// Scaling the Polygon
void scale(int x[], int y[], int sx, int sy)
{
    // Square before Scaling
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[3], y[3]);
    line(x[3], y[3], x[0], y[0]);
 
    // Initializing the Scaling Matrix.
    int s[2][2] = { sx, 0, 0, sy };
    int p[2][1],i;
 
    // Scaling the Square
    for (i = 0; i < 4; i++)
    {
        p[0][0] = x[i];
        p[1][0] = y[i];
 
        findNewCoordinate(s, p);
 
        x[i] = p[0][0];
        y[i] = p[1][0];
    }
 
    // Square after Scaling
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[3], y[3]);
    line(x[3], y[3], x[0], y[0]);
}
 
// Driver Program
int main()
{
    int x[] = { 50, 100, 100, 50 };
    int y[] = { 50, 50, 100, 100 };
    int sx = 3, sy =1 ;
 
    int gd, gm;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm," ");
 
    scale(x, y, sx,sy);
    getch();
 
    return 0;
}
