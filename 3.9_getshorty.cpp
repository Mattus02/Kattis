// Problem: https://open.kattis.com/problems/getshorty

#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;

int n, m;
struct Neighbour;
vector<vector<Neighbour>> graph;

struct Neighbour {
    int id;
    float factor;
};

float solve() {

    vector<float> sizes(n, 0.0f);
    sizes[0] = 1.0f;
    priority_queue<pair<float,int>> pq;
    pq.push({1.0f, 0});
    
    for (;;) {

        float currSize = pq.top().first;
        int currNode = pq.top().second;
        if (currNode == n-1) return currSize;
        pq.pop();

        for (Neighbour n : graph[currNode]) {
            if (currSize * n.factor > sizes[n.id]) {
                sizes[n.id] = currSize * n.factor;
                pq.push({sizes[n.id], n.id});
            }    
        }
    }
}

int main() {

    for (;;) {

        cin >> n >> m;
        if (n == 0) break;

        graph = vector<vector<Neighbour>>(n, vector<Neighbour>());

        int a, b;
        float factor;

        while (m--) {
            cin >> a >> b >> factor;
            graph[a].push_back({b, factor});
            graph[b].push_back({a, factor});
        }

        cout << fixed << setprecision(4) << solve() << endl;
    }
}