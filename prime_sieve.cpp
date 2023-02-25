// Problem: https://open.kattis.com/problems/primesieve

#include <iostream>
#include <vector>

using namespace std;

int main() {

    int first;
    int times;

    int start = 2;
    int val;

    int tmp;

    cin >> first;
    cin >> times;

    int end = first+1;
    int count = 0;

    vector<bool> primes  (end, 1);
    primes[0] = 0;
    primes[1] = 0;

    while (start < end) {
        val = start+start;
        while (val < end) {
            primes[val] = 0;
            val = val + start;
        }
        ++start;
        while (primes[start] == 0 && start < end) {
            ++start;
        }
        ++count;
    }

    cout << count << '\n';

    for (int i = 0; i < times; ++i) {
        cin >> tmp;
        cout << primes[tmp] << '\n';
    }


}