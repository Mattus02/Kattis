// Problem: https://open.kattis.com/problems/spiderman

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define INF 2000
#define BAD -1

vector<int> distances;
int M;
int bestHeight;
string solution;
vector<vector<int>> mem;

bool rec(int index, int height, int maxHeight, string moves)
{
    if (index == M) {
        if (height == 0 && maxHeight < bestHeight) {
            bestHeight = maxHeight;
            solution = moves;
            return true;
        }
        return false;
    }
    if (height < 0 || maxHeight >= bestHeight || maxHeight >= mem[index][height]) return false;

    int h1 = height - distances[index];
    int h2 = height + distances[index];

    bool b = rec(index+1, h1, maxHeight, moves+"D");
    b = rec(index+1, h2, max(maxHeight, h2), moves+"U") || b;

    if (b) {
        mem[index][height] = maxHeight;
        return true;
    }
    mem[index][height] = BAD;
    return false;
}

void solve()
{
    bestHeight = INF;
    solution = "";
    if (!rec(0, 0, 0, "")) cout << "IMPOSSIBLE" << endl;
    else                   cout << solution << endl; 
}

int main()
{
    int N;
    cin >> N;

    while (N--)
    {
        cin >> M;

        distances = vector<int>(M);
        mem = vector<vector<int>>(M, vector<int>(1001, INF));

        for (int& i : distances) cin >> i;

        solve();
    }
}