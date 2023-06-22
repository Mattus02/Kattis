// Problem: https://open.kattis.com/problems/marblestree

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

/////////////////////////////////////////////
int sum = 0;
int root;
vector<int> nodes;
map<int, vector<int>> children;
set<int> chldrn;
/////////////////////////////////////////////

void redistribute(int parent) {

    if (children.find(parent) == children.end())
        return;

    for (int i : children[parent]) {
        redistribute(i);
    }

    int diff;
    for (int i : children[parent]) {
        diff = nodes[i] - 1;
        nodes[parent] += diff;
        sum += abs(diff);
        nodes[i] = 1;
    }
}

/////////////////////////////////////////////

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, n, size;
    cin >> size;

    while (size != 0) {

        nodes.push_back(0);
        for (int i = 1; i <= size; ++i) {
            cin >> k >> k;
            nodes.push_back(k);
            cin >> k;
            if (k > 0) {
                while (k != 0) {
                    cin >> n; 
                    children[i].push_back(n);
                    --k;
                    chldrn.insert(n);
                }
            }
        }

        for (int i = 1; i <= size; ++i) {
            if (chldrn.find(i) == chldrn.end())
                root = i;
        }

        redistribute(root);
    
        cout << sum << endl;
        sum = 0;
        nodes.clear();
        children.clear();
        chldrn.clear();
        cin >> size;
    }

}