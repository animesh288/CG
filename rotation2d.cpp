#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <iostream>
using namespace std;
int main()
{
    int gd = 0, gm, x1, y1, x2, y2, x3, y3;
    double s, c, angle;
    initgraph(&gd, &gm, (char *)"");
    setcolor(RED);
    cout << "Enter coordinates of triangle: ";
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    setbkcolor(BLACK);
    cleardevice();
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    cout << "Enter rotation angle: ";
    cin >> angle;
    c = cos(angle * 3.14 / 180);
    s = sin(angle * 3.14 / 180);
    int x11 = floor(x1 * c - y1 * s);
    int y11 = floor(x1 * s + y1 * c);
    int x22 = floor(x2 * c - y2 * s);
    int y22 = floor(x2 * s + y2 * c);
    int x33 = floor(x3 * c - y3 * s);
    int y33 = floor(x3 * s + y3 * c);
    setcolor(GREEN);
    line(x11, y11, x22, y22);
    line(x22, y22, x33, y33);
    line(x33, y33, x11, y11);
    getch();
    closegraph();
    return 0;
}
