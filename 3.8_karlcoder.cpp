// Problem: https://open.kattis.com/problems/karlcoder

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long u64;

u64 Guess(u64 guess)
{
    cout << "buf[" << guess-1 << ']' << endl;
    u64 answer;
    cin >> answer;
    return answer;
}

void FinalAnswer(u64 answer)
{
    cout << "strlen(buf) = " << answer << endl;
}

void BinSearch(pair<u64,u64> range)
{
    while ((range.second - range.first) > 1)
    {
        u64 guess = range.first + (range.second - range.first) / 2;
        u64 answer = Guess(guess);
        if (answer == 0)
        {
            range.second = guess;
        }
        else
        {
            range.first = guess;
        }
    }

    FinalAnswer(range.first);
}

int main()
{
    u64 guess = 4;
    pair<u64,u64> range = {2, 2000000000000000000};

    for (;;)
    {
        u64 answer = Guess(guess);
        if (answer == 0)
        {
            range.second = guess;
            BinSearch(range);
            break;
        }
        else if (answer != 0)
        {
            range.first = guess;
            guess *= 2;
        }
    }
}