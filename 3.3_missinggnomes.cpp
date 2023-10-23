// Problem: https://open.kattis.com/problems/missinggnomes

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<bool> found(n+1, false);
    vector<int> rem(m);
    for (int& i : rem)
    {
        cin >> i;
        found[i] = true;
    }

    vector<int> missing(n-m);
    int idx{0};
    for (int i{1}; i <= n; ++i)
    {
        if (!found[i])
        {
            missing[idx] = i;
            idx += 1;
        }
    }

    int rIdx{0};
    int mIdx{0};
    vector<int> answer(n);
    for (int& i : answer)
    {
        if (mIdx == (n-m) || (rIdx < m && rem[rIdx] < missing[mIdx]))
        {
            i = rem[rIdx];
            rIdx += 1;
        }
        else
        {
            i = missing[mIdx];
            mIdx += 1;
        }
    }

    for (int i : answer)
    {
        cout << i << '\n';
    }
}