// Problem: https://open.kattis.com/problems/knotknowledge

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_set<int> knots;

    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        knots.insert(tmp);
    }

    for (int i = 0; i < n-1; i++)
    {
        cin >> tmp;
        knots.erase(tmp);
    }

    for (int i : knots)
    {
        cout << i << endl;
    }
}