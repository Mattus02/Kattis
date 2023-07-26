// Problem: https://open.kattis.com/problems/teque

#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    
    deque<int> frontEnd;  // front end of teque, last element is mid
    deque<int> backEnd;   // back end of teque, size is always equal to or one less than front end

    while (N--) {

        string command;
        int arg;
        cin >> command >> arg;
        cin.ignore();

        if (command[0] == 'g') {    
            if (arg >= frontEnd.size()) cout << backEnd[arg - frontEnd.size()];
            else                        cout << frontEnd[arg];
            cout << '\n';
            continue;
        }
        
        if (command[5] == 'b') {
            backEnd.push_back(arg);
            if (backEnd.size() > frontEnd.size()) {
                frontEnd.push_back(backEnd.front());
                backEnd.pop_front();
            }
            continue;
        }
        
        if (command[5] == 'f') frontEnd.push_front(arg);
        else                   frontEnd.push_back(arg);

        if (frontEnd.size() - backEnd.size() == 2) {
            backEnd.push_front(frontEnd.back());
            frontEnd.pop_back();
        }
    }
}