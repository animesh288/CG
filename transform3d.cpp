#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <direct.h>

using namespace std;

int main()
{
    int gd = DETECT, gm;
    int ans = 0;
    initgraph(&gd, &gm, (char *)"");
    while (ans != 4)
    {
        // int input;

        cleardevice();
        cout << "\n--------------3D Transformation Interface--------------\n";
        cout << "\nChoose from the following choices:";
        cout << "\n1. Translation";
        cout << "\n2. Scaling";
        cout << "\n3. Rotation";
        cout << "\n4. Exit";
        cout << "\n\nEnter your choice : ";
        cin >> ans;
        Sleep(5);
        // ans=input;

        cleardevice();
        int ymax, xmax;
        xmax = getmaxx();
        ymax = getmaxy();
        int xm, ym;
        xm = xmax / 2;
        ym = ymax / 2;
        setcolor(WHITE);
        bar3d(100, 100, 190, 150, 20, 1);//ltrb
        xmax = getmaxx();
        ymax = getmaxy();
        int xmid = xmax / 2;
        int ymid = ymax / 2;
        setcolor(GREEN);
        line(0, ymid, xmax, ymid);
        line(xmid, 0, xmid, ymax);

        if (ans == 1)
        {
            int tx, ty;
            outtextxy(0, 0, "\n Enter translation factor \n");
            cin >> tx >> ty;
            setcolor(WHITE);
            bar3d(100 + tx, 100 + ty, 190 + tx, 150 + ty, 20, 1);
            getch();
        }

        else if (ans == 2)
        {
            int sx, sy;
            outtextxy(0, 0, "\n Enter scalling factor \n");
            cin >> sx >> sy;
            setcolor(WHITE);
            bar3d((100 * sx), (100 * sy), (190 * sx), (150 * sy), 20, 5);
            Sleep(10);
            getch();
        }

        else if (ans == 3)
        {
            float t;
            outtextxy(0, 0, "\n Enter angle \n");
            cin >> t;
            t = t * (3.14 / 180);

            int mx = (100 + 100) / 2;
            int my = (190 + 150) / 2;

            int x1 = 100 + mx + ((100 - mx) * cos(t)) - ((100 - my) * sin(t));
            int y1 = 100 + my + ((100 - mx) * sin(t)) + ((100 - my) * cos(t));
            int x2 = 100 + mx + ((190 - mx) * cos(t)) - ((150 - my) * sin(t));
            int y2 = 100 + my + ((190 - mx) * sin(t)) + ((150 - my) * cos(t));
            setcolor(WHITE);
            int dep;
            if (x2 > x1)
                dep = (x2 - x1) / 4;
            else
                dep = (x1 - x2) / 4;
            bar3d(x1, y1, x2, y2, 20, 1);
            getch();
        }

        else if (ans == 4)
            exit(1);

        else
        {
            outtextxy(50, 50, "\n\nEnter a valid choice : ");
        }
    }
    getch();
    return 0;
}
