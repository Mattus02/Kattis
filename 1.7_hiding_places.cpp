// Problem: https://open.kattis.com/problems/hidingplaces

#include <bits/stdc++.h>

using namespace std;

int jumps[8][8] = {{0,3,2,3,2,3,4,5},
                   {3,2,1,2,3,4,3,4},
                   {2,1,4,3,2,3,4,5},
                   {3,2,3,2,3,4,3,4},
                   {2,3,2,3,4,3,4,5},
                   {3,4,3,4,3,4,5,4},
                   {4,3,4,3,4,5,4,5},
                   {5,4,5,4,5,4,5,6}};
struct ans{
    char c;
    char r;
};
bool operator<(ans lhs, ans rhs){
    if(lhs.r > rhs.r) return true;
    else if(lhs.r == rhs.r) return lhs.c < rhs.c;
    return false;
}

int hiding_places(int kr, int kc, vector<ans>& answers)
{
    int maxjumps = 0;
    for(int r = 0; r < 8; ++r){
        for(int c = 0; c < 8; ++c){
            maxjumps = max(maxjumps, jumps[abs(kr-r)][abs(kc-c)]);
        }
    }
    for(int r = 0; r < 8; ++r){
        for(int c = 0; c < 8; ++c){
            if(jumps[abs(kr-r)][abs(kc-c)] == maxjumps){
                answers.push_back({c+97,r+49});
            }
        }
    }
    sort(answers.begin(), answers.end());
    return maxjumps;
}

int main()
{
    int tests;
    cin >> tests;
    while(tests--)
    {
        cin.ignore();
        char c;
        int kr,kc;
        cin >> c;
        kc = c-97;
        cin >> kr;
        kr -= 1;
        vector<ans> answers;
        cout << hiding_places(kr,kc,answers) << ' ';
        for(ans a : answers){
            cout << a.c << a.r << ' ';
        } 
        cout << '\n';
    }
}
