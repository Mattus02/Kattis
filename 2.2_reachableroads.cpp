// Problem: https://open.kattis.com/problems/reachableroads

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void bfs(int place)
{
    queue<int> q;
    q.push(place);
    visited[place] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int neighbour : graph[curr])
        {
            if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int m, r;
        cin >> m;
        graph = vector<vector<int>>(m);
        visited = vector<bool>(m, false);

        cin >> r;
        for (int i = 0; i < r; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int clusterCount = 0;
        for (int i = 0; i < m; i++)
        {
            if (!visited[i])
            {
                bfs(i);
                clusterCount += 1;
            }
        }

        cout << clusterCount-1 << endl;
    }
}