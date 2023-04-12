#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>

float x[5];
float y[5];

int k = 3;

float t[8] = {0, 0, 0, 1, 2, 3, 3, 3};

float basis(int i, int k, float t[], float u)
{
	if (k == 0)
	{
		if (t[i] <= u && u < t[i + 1])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		float w1 = 0, w2 = 0;
		if (t[i + k] != t[i])
		{
			w1 = ((u - t[i]) / (t[i + k] - t[i])) * basis(i, k - 1, t, u);
		}
		if (t[i + k + 1] != t[i + 1])
		{
			w2 = ((t[i + k + 1] - u) / (t[i + k + 1] - t[i + 1])) * basis(i + 1, k - 1, t, u);
		}
		return w1 + w2;
	}
}

int main()
{

	int gd = DETECT, gm;
	initgraph(&gd, &gm, (char*)"");

	for (int j = 0; j < 5; j++)
	{
		printf("Enter x%d and y%d: ", j, j);
		scanf("%f %f", &x[j], &y[j]);
	}
	cleardevice();

	// Draw the control points
	setcolor(GREEN);
	for (int i = 0; i < 5; i++)
	{
		circle(x[i], y[i], 3);
	}
	// Draw the B-spline curve
	setcolor(YELLOW);
	for (float u = t[k]; u < t[5]; u += 0.01)
	{
		float x_cur = 0, y_cur = 0;
		for (int i = 0; i < 5; i++)
		{
			float b = basis(i, k, t, u);
			x_cur += x[i] * b;
			y_cur += y[i] * b;
		}
		putpixel(x_cur, y_cur, YELLOW);
		delay(10);
	}
	getch();
	closegraph();
	return 0;
}
