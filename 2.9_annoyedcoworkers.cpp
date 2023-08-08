// Problem: https://open.kattis.com/problems/annoyedcoworkers

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long u64;

struct Coworker {
    int id;
    u64 level;
    u64 increase;
};

bool operator<(Coworker const& a, Coworker const& b) { return a.level+a.increase > b.level+b.increase; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, c;
    cin >> h >> c;

    priority_queue<Coworker> coworkers_pq;
    vector<u64> coworkers(c);

    for (int i = 0; i < c; ++i)
    {
        u64 a, d;
        cin >> a >> d;
        coworkers[i] = a;
        coworkers_pq.push({i, a, d});
    }

    while (h--)
    {
        Coworker cow = coworkers_pq.top();
        coworkers_pq.pop();
        cow.level += cow.increase;
        coworkers[cow.id] += cow.increase;
        coworkers_pq.push(cow);
    }

    sort(coworkers.begin(), coworkers.end());
    cout << coworkers.back() << endl;
}