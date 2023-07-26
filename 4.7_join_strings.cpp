// Problem: https://open.kattis.com/problems/joinstrings

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> strings;
vector<vector<int>> mappings;

void printStrings(int S) {

    cout << strings[S];
    for (int s : mappings[S]) printStrings(s);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    strings = vector<string>(N+1);
    mappings = vector<vector<int>>(N+1);

    for (int i = 1; i <= N; ++i) cin >> strings[i];

    int a = 1, b;
    while (--N) {
        cin >> a >> b;
        mappings[a].push_back(b);
    }

    printStrings(a);
}