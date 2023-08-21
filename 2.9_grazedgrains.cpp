// Problem: https://open.kattis.com/problems/grazedgrains

#include <bits/stdc++.h>

using namespace std;

struct circle
{
    int x;
    int y;
    int r;
};

bool isInCircle(float x, float y, circle c)
{
    return ((c.x-x)*(c.x-x) + (c.y-y)*(c.y-y)) < c.r*c.r;
}

int main()
{
    int n;
    cin >> n;

    vector<circle> circles(n);

    for (circle& circle : circles)
    {
        cin >> circle.x >> circle.y >> circle.r;
        circle.x += 10;
        circle.y += 10;
    }

    float area = 0;

    for (float y = 0; y < 30; y += 0.1f)
    {
        for (float x = 0; x < 30; x += 0.1f)
        {
            for (auto circle : circles)
            {
                if (isInCircle(x, y, circle))
                {
                    area += 0.01f;
                    break;
                }
            }
        }
    }

    cout << area << endl;
}