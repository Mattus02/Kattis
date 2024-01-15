#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int value;
    int weight;
};

int C, n;
vector<Item> items;
vector<vector<int>> mem;

int solve(int index, int weight) {
    if (index >= n)
        return 0;

    if (mem[index][weight] != -1)
        return mem[index][weight];

    int best = solve(index + 1, weight);
    if (weight + items[index].weight <= C)
        best = max(best, items[index].value + solve(index + 1, weight + items[index].weight));

    return mem[index][weight] = best;
}

vector<int> getPath() {
    vector<int> result;
    int row = 0;
    int column = 0;

    while (row + 1 < n) {
        if (mem[row + 1][column] < mem[row][column]) {
            result.push_back(row);
            column += items[row].weight;
        }
        row += 1;
    }

    if (row < n && mem[row][column] > 0)
        result.push_back(row);
    return result;
}

int main() {
    while (cin >> C >> n) {
        mem = vector<vector<int>>(n, vector<int>(C+1, -1));
        items.resize(n);
        for (Item& i : items)
            cin >> i.value >> i.weight;
        solve(0, 0);
        vector<int> path = getPath();
        cout << path.size() << endl;
        for (int p : path)
            cout << p << ' ';
        cout << endl;
    }
}