// Problem: https://open.kattis.com/problems/cake

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
    int row;
    int col;
};

void print(Point a, Point b)
{
    cout << a.row << ' ' << a.col << ' ' << b.row << ' ' << b.col << '\n';
}

int area(Point a, Point b)
{
    return (b.row - a.row + 1) * (b.col - a.col + 1);
}

int main()
{
    int p, q, n;
    cin >> p >> q >> n;

    vector<Point> roses(n);
    for (Point& p : roses)
        cin >> p.row >> p.col;

    sort(roses.begin(), roses.end(),
        [](auto p1, auto p2) {
            if (p1.row == p2.row)
                return p1.col < p2.col;
            return p1.row < p2.row;
    });

    int totalRectangleArea = 0;
    Point topLeft = {1, 1};
    for (int i = 0; i < roses.size(); ++i)
    {
        Point& currRose = roses[i];
        if (i < roses.size() - 1)
        {
            Point nextRose = roses[i + 1];

            if (currRose.row == nextRose.row) 
            {
                Point bottomRight = {currRose.row, currRose.col};
                if (currRose.row == roses.back().row)
                    bottomRight.row = p;

                print(topLeft, bottomRight);
                totalRectangleArea += area(topLeft, bottomRight);
                
                topLeft.col = currRose.col + 1;
            }
            else
            {
                Point bottomRight = {currRose.row, q};
                print(topLeft, bottomRight);
                totalRectangleArea += area(topLeft, bottomRight);

                topLeft.row = currRose.row + 1;
                topLeft.col = 1;
            }
        }
        else
        {
            print(topLeft, {p, q});
            totalRectangleArea += area(topLeft, {p, q});
        }
    }

    cout << (p * q) - totalRectangleArea << endl;
}