// Problem: https://open.kattis.com/problems/phonelist

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

void Solve(vector<unordered_set<string>>& allNumbers) {

    int size = 10;
    while (size > 1) {
        for (const string& s : allNumbers[size]) {
            for (int i = size-1; i > 0; --i) {
                if (allNumbers[i].find(s.substr(0, i)) != allNumbers[i].end()) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
        size -= 1;
    }

    cout << "YES" << endl;
}

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        cin.ignore();

        string Nr;
        vector<unordered_set<string>> allNumbers(11);

        while (n--) {
            getline(cin, Nr);
            allNumbers[Nr.size()].insert(Nr);
        }

        Solve(allNumbers);
    }
}