// Problem: https://open.kattis.com/problems/shortestpath1

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

#define INF INT32_MAX

int n,m,q,s;

void solve(vector<int>& distances, vector<vector<pair<int,int>>>& graph, int s) {
   
    unordered_set<int> willVisit;
    willVisit.insert(s);
    distances[s] = 0;

    while (!willVisit.empty()) {
      
        int currNode = *willVisit.begin();
        willVisit.erase(currNode);

        for (auto n : graph[currNode]) {
            int neighbour = n.first;
            int distToNeighbour = n.second;
            if (distances[currNode] + distToNeighbour < distances[neighbour]) {
                distances[neighbour] = distances[currNode] + distToNeighbour;
                willVisit.insert(neighbour);
            }               
        }
    }

    while (q--) {
        int idx;
        cin >> idx;
        if (distances[idx] == INF) cout << "Impossible\n";
        else cout << distances[idx] << '\n';
    }
}

int main() {
 
    for (;;) {

        cin >> n >> m >> q >> s;
        if (n == 0) break;

        vector<int> distances(n, INF);
        vector<vector<pair<int,int>>> graph(n);

        while (m--) {
            int a,b,c;
            cin >> a >> b >> c;
            graph[a].push_back({b, c});
        }

        solve(distances, graph, s);
    }
}