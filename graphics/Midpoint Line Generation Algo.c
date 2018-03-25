// C++ program for Mid-point line generation
#include<bits/stdc++.h>
using namespace std;
 
// Header file for including graphics functions
// #include<graphics.h>
 
// midPoint function for line generation
void midPoint(int X1, int Y1, int X2, int Y2)
{
    // calculate dx & dy
    int dx = X2 - X1;
    int dy = Y2 - Y1;
 
    // initial value of decision parameter d
    int d = dy - (dx/2);
    int x = X1, y = Y1;
 
    // Plot initial given point
    // putpixel(x,y) can be used to print pixel
    // of line in graphics
    cout << x << "," << y << "\n";
 
    // iterate through value of X
    while (x < X2)
    {
        x++;
 
        // E or East is chosen
        if (d < 0)
            d = d + dy;
 
        // NE or North East is chosen
        else
        {
            d += (dy - dx);
            y++;
        }// C program for implementing
// Mid-Point Circle Drawing Algorithm
#include<stdio.h>
 
// Implementing Mid-Point Circle Drawing Algorithm
void midPointCircleDraw(int x_centre, int y_centre, int r)
{
    int x = r, y = 0;
     
    // Printing the initial point on the axes 
    // after translation
    printf("(%d, %d) ", x + x_centre, y + y_centre);
     
    // When radius is zero only a single
    // point will be printed
    if (r > 0)
    {
        printf("(%d, %d) ", x + x_centre, -y + y_centre);
        printf("(%d, %d) ", y + y_centre, x + x_centre);
        printf("(%d, %d)\n", -y + y_centre, x + x_centre);
    }
     
    // Initialising the value of P
    int P = 1 - r;
    while (x > y)
    { 
        y++;
         
        // Mid-point is inside or on the perimeter
        if (P <= 0)
            P = P + 2*y + 1;
             
        // Mid-point is outside the perimeter
        else
        {
            x--;
            P = P + 2*y - 2*x + 1;
        }
         
        // All the perimeter points have already been printed
        if (x < y)
            break;
         
        // Printing the generated point and its reflection
        // in the other octants after translation
        printf("(%d, %d) ", x + x_centre, y + y_centre);
        printf("(%d, %d) ", -x + x_centre, y + y_centre);
        printf("(%d, %d) ", x + x_centre, -y + y_centre);
        printf("(%d, %d)\n", -x + x_centre, -y + y_centre);
         
        // If the generated point is on the line x = y then 
        // the perimeter points have already been printed
        if (x != y)
        {
            printf("(%d, %d) ", y + y_centre, x + x_centre);
            printf("(%d, %d) ", -y + y_centre, x + x_centre);
            printf("(%d, %d) ", y + y_centre, -x + x_centre);
            printf("(%d, %d)\n", -y + y_centre, -x + x_centre);
        }
    } 
}
 
// Driver code
int main()
{
    // To draw a circle of radius 3 centred at (0, 0)
    midPointCircleDraw(0, 0, 3);
    return 0;
}
 
        // Plot intermediate points
        // putpixel(x,y) is used to print pixel
        // of line in graphics
        cout << x << "," << y << "\n";
    }
}
 
// Driver program
int main()
{
    // graphics driver and mode
    // used in graphics.h
    // int gd = DETECT, gm;
 
    // Initialize graphics function
    // initgraph (&gd, &gm, "");
 
    int X1 = 2, Y1 = 2, X2 = 8, Y2 = 5;
    midPoint(X1, Y1, X2, Y2);
    return 0;
}
