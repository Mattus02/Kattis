// Problem: https://open.kattis.com/problems/delimitersoup

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

unordered_map<char,char> delim = {{'(',')'}, {'[',']'}, {'{','}'} };

int main()
{
    int L;
    cin >> L;
    cin.ignore();

    string line;
    getline(cin, line);

    stack<char> s;

    for (int i = 0; i < line.size(); ++i)
    {
        char c = line[i];
        if (c == ' ') continue;
        if (delim.find(c) != delim.end()) { s.push(c); continue; }
        if (s.empty() || c != delim[s.top()]) { cout << c << ' ' << i << endl; return 0; }
        s.pop();             
    }

    cout << "ok so far" << endl;
}