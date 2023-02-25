// Problem: https://open.kattis.com/problems/birds

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

///////////////////////////////////////////////////

int fill_spots(int spots, int d) {
    int sum = spots/d;
    if (spots % d == 0)
        return sum;
    return ++sum;
}

///////////////////////////////////////////////////

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int l, d, n, tmp, diff, prev;
    int sum = 0;
    cin >> l >> d >> n;

    if (n > 0) {
        vector<int> birds(n);
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            birds[i] = tmp;
        }
        sort(birds.begin(), birds.end());
        int first_b = birds.front();
        int last_b = birds.back();

        for (int i : birds) {
            if (i == first_b) {
                diff = i-5-d;
                if (diff > 0) {
                    sum += fill_spots(diff, d);
                }
            }
            else {
                diff = i-prev+1;
                diff = diff-2*d;
                if (diff > 0) {
                    sum += fill_spots(diff, d);
                }
            }
            prev = i;
            if (i == last_b) {
                diff = (l-i)-5-d;
                if (diff > 0) {
                    sum += fill_spots(diff, d);
                }
            }
        }
    }
    else {
        diff = l - 11;
        if (diff > 0) {
            sum = fill_spots(diff, d);
        }
    }
    cout << sum << endl;
}