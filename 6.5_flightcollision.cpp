// Problem: https://open.kattis.com/problems/flightcollision

#include <bits/stdc++.h>

using namespace std;

struct Drone
{
    int id;
    int x;
    int v;
};

bool operator<(Drone const& a, Drone const& b)
{
    return a.x < b.x;
}

struct Crash
{
    long double time;
    set<Drone>::iterator a;
    set<Drone>::iterator b;
};

bool operator<(Crash const& a, Crash const& b)
{
    return b.time < a.time;
}

long double CalcCrashTime(set<Drone>::iterator const& a, set<Drone>::iterator const& b)
{
    return (long double)(b->x - a->x) / (a->v - b->v); 
}

set<Drone> drones;

bool IsValidCrash(Crash const& crash)
{
    return (drones.find(*crash.a) != drones.end()) && (drones.find(*crash.b) != drones.end());
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int x, v;
        cin >> x >> v;
        drones.insert({i+1, x, v});
    }

    priority_queue<Crash> crashQueue;
    for (auto it = drones.begin(); it != prev(drones.end()); ++it)
    {
        auto nxt = next(it);
        if (it->v > nxt->v)
            crashQueue.push({CalcCrashTime(it, nxt), it, nxt}); 
    }

    while (crashQueue.size() > 0)
    {
        Crash crash = crashQueue.top();
        crashQueue.pop();
        if (!IsValidCrash(crash))
            continue;

        if (crash.a != drones.begin() && crash.b != prev(drones.end())) {
            auto left = prev(crash.a); 
            auto right = next(crash.b);
            if (left->v > right->v)
                crashQueue.push({CalcCrashTime(left, right), left, right});
        }

        drones.erase(crash.a);
        drones.erase(crash.b);
    }

    cout << drones.size() << '\n';
    for (Drone const& d : drones)
        cout << d.id << ' ';
}
