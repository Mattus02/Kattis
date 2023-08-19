// Problem: https://open.kattis.com/problems/powerstrings

#include <iostream>
#include <string>

using namespace std;

void solve(string const& line)
{
    for (int i = 1; i <= line.size() / 2; i += 1)
    {
        if (line.size() % i != 0) continue;

        string substring = line.substr(0, i);

        bool foundIt = true;
        for (int j = i; j < line.size(); j += i)
        {
            if (substring != line.substr(j, i))
            {
                foundIt = false;
                break;
            }
        }

        if (foundIt)
        {
            cout << line.size() / i << endl;
            return;
        }
    }
    
    cout << 1 << endl;
}

int main()
{
    for (;;)
    {
        string line;
        getline(cin, line);
        if (line == ".") break;
        solve(line);
    }
}