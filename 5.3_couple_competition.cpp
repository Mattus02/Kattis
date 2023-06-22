// Problem: https://open.kattis.com/problems/couplecompetition

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int blockAmount;
    cin >> blockAmount;

    map<int, vector<int>> blockHeights;
    int tmp;

    for (int i = 0; i < blockAmount; ++i)
    {
        cin >> tmp;
        blockHeights[tmp].push_back(i);
    }

    vector<int> jumpCache (blockAmount);
    set<int> higherBlocks;
    auto iter = blockHeights.end();

    // All highest blocks require 0 jumps;
    for (int i : (*--iter).second)
    {
        //jumpCache[i] = 0;
        higherBlocks.insert(i);
    }

    int upperBoundIndex;
    int lowerIndex;

    while (iter-- != blockHeights.begin())
    {
        for (int i : (*iter).second)
        {
            auto upperBoundIter = higherBlocks.upper_bound(i);
            auto lowerIter = upperBoundIter;
            --lowerIter;
            upperBoundIndex = *upperBoundIter;
            lowerIndex = *lowerIter;
            if (i >= upperBoundIndex)
            {
                jumpCache[i] = 1 + jumpCache[lowerIndex];
            }
            else if (upperBoundIter == higherBlocks.begin())
            {
                jumpCache[i] = 1 + jumpCache[upperBoundIndex];
            }
            else
            {
                jumpCache[i] = 1 + min(jumpCache[upperBoundIndex], jumpCache[lowerIndex]);
            }
        }
        for (int i : (*iter).second)
        {
            higherBlocks.insert(i);
        }
    }

    for (int i : jumpCache)
    {
        cout << i << ' ';
    } 
}