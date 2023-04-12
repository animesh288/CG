#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

class point
{
public:
    int x, y;
    point(int a, int b)
    {
        x = a;
        y = b;
    }
};

void computeCoefficient(vector<double> &c, int n)
{
    double k, i;

    for (int k = 0; k <= n; k++)
    {
        c[k] = 1;
        for (i = n; i >= k + 1; i--)
        {
            c[k] *= i;
        }
        for (i = n - k; i >= 2; i--)
        {
            c[k] /= i;
        }
    }
}
double blend(double u, int k, vector<double> &c, int n)
{
    return c[k] * pow(u, k) * pow((1 - u), (n - k));
}

void draw(vector<point> poly, vector<double> &c)
{
    int n = poly.size() - 1; // degree of the curve
    int i;
    double x, y, basis, u;
    for (u = 0; u <= 1; u += 0.001)
    {
        x = 0;
        y = 0;
        for (i = 0; i < poly.size(); i++)
        {
            basis = blend(u, i, c, n);
            x += basis * poly[i].x;
            y += basis * poly[i].y;
        }
        putpixel(round(x), round(y), WHITE);
    }
}

int main()
{
    initwindow(700, 700, "Bezier Curve");
    cout << "\nEnter Degree of the Bezier Curve : ";
    int n; // degree of curve;
    cin >> n;
    vector<point> poly;
    for (int i = 0; i < n + 1; i++)
    {
        // takes n+1 point as input p0 to pn;
        int x, y;
        cout << "\nEnter Coordinates of Control Point " << i + 1 << ": ";
        cin >> x >> y;
        point newp(x, y);
        poly.push_back(newp);
    }
    vector<double> c(n + 1); // vector to store binomial coefficient, it contains coefficient of n+1 points;
    computeCoefficient(c, n);

    draw(poly, c);
    getch();
    return 0;
}
