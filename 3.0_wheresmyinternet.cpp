// Problem: https://open.kattis.com/problems/wheresmyinternet

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N+1);

    int a, b;
    while (M--)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // BFS

    vector<bool> visited(N+1, false);
    unordered_set<int> toVisit;
    toVisit.insert(1);

    while (!toVisit.empty())
    {
        int curr = *toVisit.begin();
        toVisit.erase(curr);

        for (int neighbour : graph[curr])
            if (!visited[neighbour])
                toVisit.insert(neighbour);

        visited[curr] = true;
    }

    bool connected = true;
    for (int i = 1; i < N+1; ++i) {
        if (!visited[i]) {
            cout << i << '\n';
            connected = false;
        }
    }

    if (connected) cout << "Connected\n";
}