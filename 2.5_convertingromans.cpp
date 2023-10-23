// Problem: https://open.kattis.com/problems/convertingromans

#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> val = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};

int GoBackwards(string& line, int idx, int& sum)
{
    int currVal{val[line[idx]]};
    sum += currVal;

    if (idx == 0) return -1;

    idx -= 1;

    while (idx >= 0 && val[line[idx]] < currVal)
    {
        sum -= val[line[idx]];
        idx -= 1;
    }

    return idx;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        string line;
        cin >> line;

        int sum{0};

        int i{line.length()-1};

        while (i >= 0)
        {
            i = GoBackwards(line, i, sum);
        }

        cout << sum << endl;
    }
}