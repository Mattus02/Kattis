// Problem: https://open.kattis.com/problems/hindex

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> citations(n);

    for (int i = 0; i < n; ++i) cin >> citations[i];

    sort(begin(citations), end(citations));

    int remaining = n;
    int H = 0;
    
    for (int i = 0; i < n; ++i) {
        if (remaining <= citations[i]) {
            H = remaining;
            break;
        }
        remaining -= 1;
    }

    cout << H << endl;
}