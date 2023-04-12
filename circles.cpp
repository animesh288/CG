
#include <graphics.h>
#include <conio.h>
#include <math.h>
int main()
{
    int gd = DETECT, gm, i;
    initgraph(&gd, &gm, (char *)"");
    for (i = 50; i < 200; i = i + 30)
        circle(i, i + 30, 50);
    getch();
    closegraph();

    return 0;
}