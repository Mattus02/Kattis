// Problem: https://open.kattis.com/problems/classpicture

#include <bits/stdc++.h>

using namespace std;

vector<string> names;
bool dontLike[10][10];
int n;

bool solve(int* state, int size)
{
    if (size == n)
    {
        for (int i {0}; i < n; ++i)
        {
            cout << names[state[i]] << ' ';
        }
        cout << endl;
        return true;
    }

    for (int id {0}; id < n; ++id)
    {
        if (find(state, state+size, id) == (state+size))
        {
            if (size == 0 || !dontLike[id][state[size-1]])
            {
                state[size] = id;
                if (solve(state, size+1)) return true;
            }
            state[size] = -1;
        }
    }
    return false;
}

int main()
{
    while (cin >> n)
    {
        names.resize(n);

        for (int i {0}; i < 10; ++i) {
            for (int j {0}; j < 10; ++j) {
                dontLike[i][j] = false;
            }
        }
        
        for (string& name : names)
        {
            cin >> name;
        }
        sort(names.begin(), names.end());

        unordered_map<string,int> ID;
        for (int i {0}; i < n; ++i)
        {
            ID[names[i]] = i;
        }

        int m;
        cin >> m;
        for (int i {0}; i < m; ++i)
        {
            string a, b;
            cin >> a >> b;
            dontLike[ID[a]][ID[b]] = true;
            dontLike[ID[b]][ID[a]] = true;
        }

        int state[10];
        if (!solve(state, 0)) cout << "You all need therapy." << endl;
    }
}