// Problem: https://open.kattis.com/problems/bungeebuilder

#include <bits/stdc++.h>

using namespace std;

struct mountain
{
    int height;
    int idx;
};

bool operator<(mountain a, mountain b) { return a.height > b.height; }

void calcHeights(vector<int>& heights, int curr, int end, int& maxDiff)
{
    int bridgeHeight = min(heights[curr], heights[end]);
    for (curr += 1; curr < end; ++curr)
    {
        maxDiff = max(maxDiff, bridgeHeight - heights[curr]);
    }
}

int main()
{
    int N;
    cin >> N;

    vector<int> heights(N);
    vector<mountain> mountains(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> heights[i];
        mountains[i] = {heights[i], i};
    }

    sort(mountains.begin(), mountains.end());

    int maxDiff = 0;
    vector<int> endpoints;

    for (auto m : mountains)
    {
        if (endpoints.size() == 0)
        {
            endpoints.push_back(m.idx);
            continue;
        }
        else if (endpoints.size() == 1)
        {
            endpoints.push_back(m.idx);
            if (endpoints[0] > endpoints[1]) swap(endpoints[0], endpoints[1]);
            calcHeights(heights, endpoints[0], endpoints[1], maxDiff);
            continue;
        }
        
        if (m.idx < endpoints[0])
        {
            calcHeights(heights, m.idx, endpoints[0], maxDiff);
            endpoints[0] = m.idx;
        }
        else if (m.idx > endpoints[1])
        {
            calcHeights(heights, endpoints[1], m.idx, maxDiff);
            endpoints[1] = m.idx;                   
        }
    }

    cout << maxDiff << endl;
}