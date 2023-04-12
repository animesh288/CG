#include <graphics.h>
#include <iostream>
using namespace std;


int main() {
   int gd = DETECT, gm,x1,y1,x2,y2,x3,y3;
   
   initgraph(&gd, &gm, (char*)"");
cout<<"Enter coordinates of triangle: ";
cin>>x1>>y1;
cin>>x2>>y2;
cin>>x3>>y3;
   // Draw original triangle
   setcolor(YELLOW);
   line(x1, y1, x2, y2);
   line(x2, y2, x3, y3);
   line(x3, y3, x1, y1);

   // Reflect triangle About Y-Axis


   setcolor(GREEN);
   line(getmaxx()-x1, y1, getmaxx()-x2, y2);
   line(getmaxx()-x2, y2, getmaxx()-x3, y3);
   line(getmaxx()-x3, y3, getmaxx()-x1, y1);

   getch();
   closegraph();
   return 0;
}
