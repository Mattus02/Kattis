// Problem: https://open.kattis.com/problems/cd

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int jack, jill, tmp;

    while (true) {
        cin >> jack >> jill;
        int count = 0;
        if (jack == 0 || jill == 0)
            break;

        unordered_set<int> jacks;

        for (int i = 0; i < jack; ++i) {
            cin >> tmp;
            jacks.insert(tmp);
        }

        for (int i = 0; i < jill; ++i) {
            cin >> tmp;
            if (jacks.find(tmp) != jacks.end())
                ++count;
        }
        cout << count << '\n';
    }
}