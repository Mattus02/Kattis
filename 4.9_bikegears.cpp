// Problem: https://open.kattis.com/problems/bikegears

#include <bits/stdc++.h>

using namespace std;

struct Gear
{
    int f, b;
    bool operator<(Gear other)
    {
        auto ratio = (long double)f / b;
        auto other_ratio = (long double)other.f / other.b;
        if (ratio == other_ratio)
            return f < other.f;
        return ratio < other_ratio;
    }
};

int main()
{
    int F, B;
    cin >> F >> B;

    vector<int> fronts(F);
    for (int& f : fronts) cin >> f;
    vector<int> backs(B);
    for (int& b : backs) cin >> b;

    vector<Gear> gears;
    for (int f : fronts)
        for (int b : backs)
            gears.push_back({f, b});

    sort(gears.begin(), gears.end());
    for (Gear g : gears)
        cout << '(' << g.f << ',' << g.b << ")\n";
}