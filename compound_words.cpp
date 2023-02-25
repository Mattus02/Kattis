// Problem: https://open.kattis.com/problems/compoundwords

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {

    string words[100];
    set<string> wordcomb; 

    string word;
    string tmp;
    string current;
    int idx = 0;

    while (cin >> word) {
        words[idx] = word;
        ++idx;
    }

    for (int i = 0; i < idx; ++i) {
        current = words[i];
        for (int n = i-1; n > -1; --n) {
            tmp = current + words[n];
            wordcomb.insert(tmp);
        }
        for (int n = i+1; n < idx; ++n) {
            tmp = current + words[n];
            wordcomb.insert(tmp);
        }
    }

    for (const string& w : wordcomb) {
        cout << w << '\n';
    }

}