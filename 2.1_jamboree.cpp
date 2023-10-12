// Problem: https://open.kattis.com/problems/jamboree

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> items(N);
    vector<int> scouts(M);

    for (int& i : items) cin >> i;
    sort(items.begin(), items.end());

    for (int& s : scouts)
    {
        if (items.empty()) break;

        s = items.back();
        items.pop_back();
    }

    if (items.empty())
    {
        cout << scouts.front() << endl;
        return 0;
    }

    for (int i = M - 1; i >= 0; --i)
    {
        if (items.empty()) break;

        scouts[i] += items.back();
        items.pop_back();
    }

    int maxSize = 0;
    for (int s : scouts)
    {
        maxSize = max(maxSize, s);
    }

    cout << maxSize << endl;
}