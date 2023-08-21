// Problem: https://open.kattis.com/problems/railroad2

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int X, Y;
    cin >> X >> Y;

    if (Y % 2 == 0)
    {
        cout << "possible\n";
    }
    else
    {
        cout << "impossible\n";
    }
}