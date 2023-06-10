// Problem: https://open.kattis.com/problems/conquest

#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int islands, bridges;
    scanf("%d %d", &islands, &bridges);
    vector<vector<int>> bridge_map (islands+1);
    while(bridges--)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        bridge_map[from].push_back(to);
        bridge_map[to].push_back(from);
    }

    vector<int> armies {-1};
    for(int i = 0; i < islands; ++i)
    {
        int size;
        scanf("%d", &size);
        armies.push_back(size);
    }

    vector<bool> conquered (islands+1);
    conquered[1] = true;
    int army_size = armies[1];

    bool check = true;
    while(check)
    {
        check = false;
        for(int i = 1; i < islands+1; ++i){
            if (conquered[i]){
                for(int j : bridge_map[i]){
                    if (army_size > armies[j] && !conquered[j]){
                        army_size += armies[j];
                        conquered[j] = true;
                        check = true;
                    }
                }
            }           
        }
    }
    printf("%d", army_size);
}
