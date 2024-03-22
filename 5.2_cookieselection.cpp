// Problem: https://open.kattis.com/problems/cookieselection

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string token;
    multiset<int> cookies;

    int medianIdx;
    multiset<int>::iterator medianIt;

    while (cin >> token)
    {
        if (token != "#")
        {
            int d = stoi(token);
            cookies.insert(d);

            if (cookies.size() == 1)
            {
                medianIdx = 0;
                medianIt = cookies.begin();
            }
            else
            {
                if (d < *medianIt)
                {
                    if (cookies.size() % 2 == 1)
                    {
                        medianIdx -= 1;
                        --medianIt;
                    }
                }
                else
                {
                    if (cookies.size() % 2 == 0)
                    {
                        medianIdx += 1;
                        ++medianIt;
                    }
                }
            }
        }
        else
        {
            auto toRemove = medianIt;
            if (cookies.size() % 2 == 0)
            {
                medianIdx -= 1;
                --medianIt;
            }
            else
            {
                medianIdx += 1;
                ++medianIt;
            }
            cout << *toRemove << '\n';
            cookies.erase(toRemove);
        }
    }
}