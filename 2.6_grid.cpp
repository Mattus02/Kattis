// Problem: https://open.kattis.com/problems/grid

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Tile {
    int r;
    int c;
    int jumps;  // Jumps to get to this tile
};

bool operator<(const Tile& a, const Tile& b) { return a.jumps > b.jumps; }

int bfs(int R, int C, vector<vector<int>>& grid)
{
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    priority_queue<Tile> pq;
    pq.push({0, 0, 0});
    visited[0][0] = true;

    while (!pq.empty())
    {
        Tile curr = pq.top();
        int r = curr.r;
        int c = curr.c;
        int jumps = curr.jumps;
        if (r == R-1 && c == C-1) return jumps;
        pq.pop();
        
        int dist = grid[r][c];

        int up    = r - dist;
        int down  = r + dist;
        int left  = c - dist;
        int right = c + dist;

        if (up >= 0 && !visited[up][c]) {
            pq.push({up, c, jumps+1});
            visited[up][c] = true;
        }   
        if (down < R && !visited[down][c]) {
            pq.push({down, c, jumps+1});
            visited[down][c] = true;
        } 
        if (left >= 0 && !visited[r][left]) {
            pq.push({r, left, jumps+1});
            visited[r][left] = true;
        }   
        if (right < C && !visited[r][right]) {
            pq.push({r, right, jumps+1});
            visited[r][right] = true;
        }   
    }

    return -1;
}

int main()
{
    int R, C;
    cin >> R >> C;

    vector<vector<int>> grid(R, vector<int>(C));

    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            char ch;
            cin >> ch;
            grid[r][c] = ch - '0';
        }
    }

    cout << bfs(R, C, grid) << endl;
}