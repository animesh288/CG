#include <graphics.h>
#include<iostream>
using namespace std;
int gd = DETECT, gm;
int n, x[100], y[100], i;
float sfx, sfy;
void draw();
void scale();

int main()
{
     n=3;
     
    cout << "Enter coordinates x, y for each vertex: ";
    for (i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    cout << "Enter scale factors: sfx and sfy : ";
    cin >> sfx >> sfy;
    initgraph(&gd, &gm, (char *)"");
    cleardevice();
    setcolor(RED);
    draw();
    scale();
    setcolor(YELLOW);
    draw();
    getch();
    closegraph();
    return 0;
}
void draw()
{
    for (i = 0; i < n; i++)
    {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }
}
void scale()
{
    for (i = 0; i < n; i++)
    {
        x[i] = (int)((float)(x[i]) * sfx);
        y[i] = (int)((float)(y[i]) * sfy);
    }
}
