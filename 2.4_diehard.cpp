// Problem: https://open.kattis.com/problems/diehard

#include <iostream>

using namespace std;

bool BetterOrEqual(int* first, int* second)
{
    int fcount{0};
    int scount{0};

    for (int i{0}; i < 6; ++i) {
        for (int j{0}; j < 6; ++j) {
            if (first[i] > second[j]) fcount += 1;
            else if (first[i] < second[j]) scount += 1;
        }
    }

    return fcount >= scount && fcount > 0;
}

int main()
{
    int d1[6];
    int d2[6];
    int d3[6];

    for (int& i : d1) cin >> i;
    for (int& i : d2) cin >> i;
    for (int& i : d3) cin >> i;

    if (BetterOrEqual(d1, d2) && BetterOrEqual(d1, d3))
    {
        cout << 1 << endl;
        return 0;
    }

    if (BetterOrEqual(d2, d1) && BetterOrEqual(d2, d3))
    {
        cout << 2 << endl;
        return 0;
    }

    if (BetterOrEqual(d3, d1) && BetterOrEqual(d3, d2))
    {
        cout << 3 << endl;
        return 0;
    }

    cout << "No dice" << endl;
}