// Problem: https://open.kattis.com/problems/howmanyzeros

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

///////////////////////////////////////////////

unsigned zeroes(string& s) {
    unsigned n = static_cast<unsigned>(stoll(s));
    reverse(s.begin(), s.end());
    unsigned width = s.size();
    unsigned charnum;
    unsigned sum = (n/10)+1;

    unsigned diff_add, powb, pows;

    for (unsigned i=1; i < width-1; ++i) {
        powb = static_cast<unsigned>(pow(10,i+1));
        pows = powb/10;
        charnum = s[i] - '0';
        if (charnum == 0) {
            diff_add = n%pows + 1;
            sum += ((n - powb)/powb)*pows + diff_add;
        }
        else {
            sum += (n/powb)*pows;
        }
    }
    
    return sum;
}

///////////////////////////////////////////////

unsigned countzeros(string& s) {
    unsigned size = s.size();
    unsigned count = 0;
    for (unsigned i = 0; i < size; ++i) {
        if (s[i] == '0')
            ++count;
    }
    return count;
}

///////////////////////////////////////////////

int main() {

    string a, b;
    cin >> a >> b;
    long long check = stoll(a);
    while (check >= 0) {
        cout << zeroes(b)-zeroes(a)+countzeros(a) << '\n';
        cin >> a >> b;
        check = stoll(a);
    }
}