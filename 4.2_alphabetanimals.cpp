// Problem: https://open.kattis.com/problems/alphabetanimals

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string previous;
    cin >> previous;
    
    int n;
    cin >> n;

    vector<int> startsWith(256);

    vector<string> words(n);
    for (string& word : words)
    {
        cin >> word;
        startsWith[word.front()] += 1;
    }

    for (string const& word : words)
    {
        if (word.front() == previous.back())
        {
            if (startsWith[word.back()] == 0 || (startsWith[word.back()] == 1 && word.front() == word.back()))
            {
                cout << word << '!' << endl;
                exit(0);
            }
        }
    }

    for (string const& word : words)
    {
        if (word.front() == previous.back())
        {
            cout << word << endl;
            exit(0);
        }
    }

    cout << '?' << endl;
}
