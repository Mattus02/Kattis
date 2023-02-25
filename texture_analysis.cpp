// Problem: https://open.kattis.com/problems/textureanalysis

#include <iostream>
#include <string>

using namespace std;

////////////////////////////////////////////////

bool is_even(const string& s) {
    int first_distance = 0;
    int curr_distance  = 0;
    for (unsigned i = 1; i < s.size(); ++i) {
        if (s[i] == '.') {
            ++first_distance;
        }
        else {
            break;
        }
    }

    for (unsigned i = 1; i < s.size(); ++i) {
        if (s[i] == '.') {
            ++curr_distance;
        }
        else {
            if (first_distance != curr_distance) {
                return false;
            }
            curr_distance = 0;
        }
    }
    return true;
}

////////////////////////////////////////////////

int main() {

    string input;
    string output;
    int    outputs = 0;

    while (cin >> input) {
        ++outputs;
        if (input == "END") {
            break;
        }
        else if (is_even(input)) {
            output += to_string(outputs) += ' ';
            output += "EVEN\n";
        }
        else {
            output += to_string(outputs) += ' ';
            output += "NOT EVEN\n";
        }
    }

    cout << output;
    
}