// Problem: https://open.kattis.com/problems/3dprinter

#include <iostream>

using namespace std;

int main() {

    int statues;
    cin >> statues;
    int printers = 1;
    int days = 1;

    while (printers < statues) {
        printers *= 2;
        days += 1;
    }

    cout << days << endl;
}