//Problem: https://open.kattis.com/problems/horror 

#include <iostream>
#include <vector>

using namespace std;

#define INF 9999

int main()
{
    int m, h, s;
    cin >> m >> h >> s;

    vector<int> search(h);
    for (int i = 0; i < h; ++i) {
        cin >> search[i];
    }

    vector<vector<int>> sims(m);
    while (s--)
    {
        int a, b;
        cin >> a >> b;
        sims[a].push_back(b);
        sims[b].push_back(a);
    }

    vector<bool> done(m);
    vector<int> hi(m, INF);
    for (int i : search) {
        hi[i] = 0;
        done[i] = true;
    }

    int val = 1;
    while (search.size() != 0)
    {
        vector<int> temp;
        for (int i : search) {
            for (int j : sims[i]) {
                if (!done[j]) {
                    hi[j] = val;
                    done[j] = true;
                    temp.push_back(j);
                }
            }
        }
        search.clear();
        for (int i : temp)
            search.push_back(i);
        ++val;
    }

    int highest = 0;
    for (int i = 0; i < m; ++i) {
        if (hi[i] > hi[highest]) {
            highest = i;
            if (hi[i] == INF) {
                break;
            }
        }    
    }

    cout << highest << endl;
}
