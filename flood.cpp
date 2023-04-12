#include <graphics.h>

void flood(int x, int y, int fillColor, int defaultColor)
{
    if (getpixel(x, y) == defaultColor)
    {
        delay(0.5);
        putpixel(x, y, fillColor);
        flood(x + 1, y, fillColor, defaultColor);
        flood(x - 1, y, fillColor, defaultColor);
        flood(x, y + 1, fillColor, defaultColor);
        flood(x, y - 1, fillColor, defaultColor);
    }
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");

    setcolor(CYAN);
    rectangle(100, 100, 300, 300);
    flood(101, 101, 3, BLACK); //{x, y, fillcolor==CYAN, defaultColor==BLACK};

    getch();
    return 0;
}
