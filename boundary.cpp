#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <graphics.h>

void boundaryFill4(int i, int j, int fill_color, int boundary_color)
{
    if (getpixel(i, j) != boundary_color &&
        getpixel(i, j) != fill_color)
    {
        putpixel(i, j, fill_color);
        boundaryFill4(i + 1, j, fill_color, boundary_color);
        boundaryFill4(i, j + 1, fill_color, boundary_color);
        boundaryFill4(i - 1, j, fill_color, boundary_color);
        boundaryFill4(i, j - 1, fill_color, boundary_color);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    int x = 250, y = 200, radius = 50;
    circle(x, y, radius);
    delay(1000);
    boundaryFill4(x, y, CYAN, WHITE);
    delay(10000);
    getch();
    closegraph();
    return 0;
}
