// Problem: https://open.kattis.com/problems/cudoviste

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int R, C;
    cin >> R >> C;
    cin.ignore();

    vector<vector<char>> grid(R, vector<char>(C));
    vector<int> result(5);

    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c)
            cin >> grid[r][c];


    for (int r = 0; r < R-1; ++r) {
        for (int c = 0; c < C-1; ++c)
        {
            if (grid[r][c]   == '#' || grid[r][c+1]   == '#' ||
                grid[r+1][c] == '#' || grid[r+1][c+1] == '#') continue;

            int X_count = 0;
            if (grid[r][c]     == 'X') X_count += 1;
            if (grid[r][c+1]   == 'X') X_count += 1;
            if (grid[r+1][c]   == 'X') X_count += 1;
            if (grid[r+1][c+1] == 'X') X_count += 1;

            result[X_count] += 1;
        }
    }

    for (int i = 0; i < 5; ++i) cout << result[i] << endl;
}