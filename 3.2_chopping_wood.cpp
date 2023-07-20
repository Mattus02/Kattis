// Problem: https://open.kattis.com/problems/chopwood

#include <iostream>
#include <vector>

using namespace std;

vector<int> input;
vector<int> leaf_count;
vector<int> output;

int it = 1;

int find_next_leaf() {

    while (leaf_count[it] != 0) {
        it += 1;
    }
    return it++;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    input = vector<int>(n+1);

    for (int i = 1; i <= n; i += 1) {
        cin >> input[i];
    }

    leaf_count = vector<int>(n+1);

    for (int i = n; i > 0; i -= 1) {
        leaf_count[input[i]] += 1; 
    }

    output = vector<int>(n+1);

    int i = 1;
    while (i <= n) {
        int lowest_leaf = find_next_leaf();
        if (lowest_leaf > n) {
            cout << "Error";
            return 0;
        }
        output[i] = lowest_leaf;
        leaf_count[input[i]] -= 1;
        while (leaf_count[input[i]] == 0 && input[i] < it) {
            output[i+1] = input[i];
            i += 1;
            leaf_count[input[i]] -= 1;
        }
        i += 1;
    }

    i = 1;
    while (i <= n) {
        cout << output[i] << '\n';
        i += 1;
    }

}