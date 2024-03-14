// Problem: https://open.kattis.com/problems/caching

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <queue>

using namespace std;

#define INF 100001

int main()
{
    int c, n, a;
    cin >> c >> n >> a;

    vector<int> accesses(a);
    vector<deque<int>> accessTime(n);

    for (int i = 0; i < a; ++i)
    {
        int object;
        cin >> object;
        accesses[i] = object;
        accessTime[object].push_back(i);
    }

    unordered_set<int> cache;
    priority_queue<pair<int, int>> cachePQ;
    
    int counter = 0;
    for (int object: accesses)
    {
        accessTime[object].pop_front();
        int nextAccess = accessTime[object].size() != 0 ? accessTime[object].front() : INF;

        // If object is in cache
        if (cache.find(object) != cache.end())
        {
            cachePQ.push({nextAccess, object});
            continue;
        }

        // If object is not in cache and needs to replace some other object
        if (cache.size() == c)
        {
            auto toRemove = cachePQ.top();
            cache.erase(toRemove.second);
            cachePQ.pop();
        }

        cache.insert(object);
        cachePQ.push({nextAccess, object});
        ++counter;
    }

    cout << counter << endl;
}