// Problem: https://open.kattis.com/problems/unionfind

#include <iostream>
#include <vector>
using namespace std;

vector<int> elems{};

int find(int a) {
    if (elems[a] == a)
        return a;
    elems[a] = find(elems[a]);
    return elems[a];
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int elms, ops, a, b;
    char op;
    cin >> elms >> ops;
    for (int i = 0; i < elms; ++i) {
        elems.push_back(i);
    }
    for (int i = 0; i < ops; ++i) {
        cin >> op >> a >> b;
        if (op == '?') {
            if (find(elems[a]) == find(elems[b]))
                cout << "yes\n";
            else
                cout << "no\n";
        }
        else
            elems[find(elems[a])] = find(elems[b]);
    }
}