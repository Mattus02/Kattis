// Problem: https://open.kattis.com/problems/coast

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pos {
    int r = 0;
    int c = 0;
};

int main() {

    int r, c, row, col, ur, uc, rr, rc, dr, dc, lr, lc;
    int sum = 0;
    char ch;
    cin >> r >> c;
    vector<vector<int>> tiles(r+2, vector<int>(c+2,0));
    vector<vector<bool>> visited(r+2, vector<bool>(c+2,0));

    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> ch;
            tiles[i][j] = (ch-'0');
        }
    }

    queue<pos> q;
    q.push({0,0});
    visited[0][0] = 1;

    while (!q.empty()) {
        row = q.front().r;
        col = q.front().c;
        q.pop();
        ur = row-1; uc = col;
        rr = row;   rc = col+1;
        dr = row+1; dc = col;
        lr = row;   lc = col-1;

        if (ur >= 0) {
            if (tiles[ur][uc] == 1)
                ++sum;
            else
                if (visited[ur][uc] == 0) {
                    q.push({ur,uc});
                    visited[ur][uc] = 1;
                }
        }

        if (rc < c+2) {
            if (tiles[rr][rc] == 1)
                ++sum;
            else
                if (visited[rr][rc] == 0) {
                    q.push({rr,rc});
                    visited[rr][rc] = 1;
                }
        }

        if (dr < r+2) {
            if (tiles[dr][dc] == 1)
                ++sum;
            else
                if (visited[dr][dc] == 0) {
                    q.push({dr,dc});
                    visited[dr][dc] = 1;
                }
        }

        if (lc >= 0) {
            if (tiles[lr][lc] == 1)
                ++sum;
            else
                if (visited[lr][lc] == 0) {
                    q.push({lr,lc});
                    visited[lr][lc] = 1;
                }
        }
    }
    cout << sum << endl;
}