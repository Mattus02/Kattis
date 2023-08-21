// Problem: https://open.kattis.com/problems/millionairemadness

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vault;
vector<vector<bool>> visited;
int M, N;

struct mountain
{
    int r;
    int c;
    int diff;
};

bool operator<(mountain a, mountain b) { return a.diff > b.diff; }

int dijkstra()
{
    priority_queue<mountain> pq;
    pq.push({0, 0, 0});

    for (;;)
    {
        int r = pq.top().r;
        int c = pq.top().c;
        int currDiff = pq.top().diff;
        pq.pop();
        if (visited[r][c]) continue;

        if (r == M-1 && c == N-1) return currDiff;

        int currHeight = vault[r][c];
        if (r != 0 && !visited[r-1][c])
        {
            pq.push({r-1, c, max(currDiff, vault[r-1][c] - currHeight)});
        }
        if (r != M-1 && !visited[r+1][c])
        {
            pq.push({r+1, c, max(currDiff, vault[r+1][c] - currHeight)});
        }
        if (c != 0 && !visited[r][c-1])
        {
            pq.push({r, c-1, max(currDiff, vault[r][c-1] - currHeight)});
        }
        if (c != N-1 && !visited[r][c+1])
        {
            pq.push({r, c+1, max(currDiff, vault[r][c+1] - currHeight)});
        }

        visited[r][c] = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;

    vault = vector<vector<int>>(M, vector<int>(N));
    visited = vector<vector<bool>>(M, vector<bool>(N, false));

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> vault[i][j];
        }
    }

    cout << dijkstra() << endl;
}