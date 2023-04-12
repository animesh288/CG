#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
int main(void)
{
    int gd = DETECT, gmode;
    int i, x, y, flag1 = 0, flag2 = 0;
    initgraph(&gd, &gmode, (char *)"");
    x = 0;
    y = getmaxy() / 2;
    while (!kbhit())
    {
        if (y >= getmaxy() - 30 || y <= 0)
            flag1 = !flag1;
        if (x >= getmaxx() - 30 || x <= 0)
            flag2 = !flag2;
        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        circle(x, y, 30);
        floodfill(x, y, RED);
        delay(20);
        cleardevice();
        if (flag1 && flag2)
        {
            y = y + 3;
            x = x + 5;
        }
        else if (!flag1 && !flag2)
        {
            x = x - 5;
            y = y - 4;
        }
        else if (!flag1 && flag2)
        {
            x = x + 5;

            y = y - 4;
        }
        else
        {
            x = x - 5;
            y = y + 4;
        }
        if (x == 0)
        {
            y = getmaxy() / 2;
        }
    }
    getch();
    closegraph();

    return 0;
}