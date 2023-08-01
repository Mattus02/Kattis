// Problem: https://open.kattis.com/problems/backspace

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<char> output(1000000, '_');

    char c;
    int currPos = 0;
    while (cin >> c) {
        if (c == '<') {
            currPos -= 1;
            output[currPos] = '_';
        } else {
            output[currPos] = c;
            currPos += 1;
        }
    }

    for (char ch : output) {
        if (ch == '_') break;
        cout << ch;
    }

}