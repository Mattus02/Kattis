// Problem: https://open.kattis.com/problems/bokforing

#include <bits/stdc++.h>

using namespace std;

struct person
{
    int wealth;
    int time;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int population, events;
    cin >> population >> events;
    vector<person> persons(population+1, {0, 0}); 
    int restart_val, restart_time = -1;
    for(int i = 0; i < events; ++i)
    {
        string event;
        cin >> event;
        if(event[0] == 'S'){
            int p;
            cin >> p;
            cin >> persons[p].wealth;
            persons[p].time = i;
        }
        else if(event[0] == 'R'){
            restart_time = i;
            cin >> restart_val;
        }
        else{
            int p;
            cin >> p;
            if(persons[p].time > restart_time){
                cout << persons[p].wealth << '\n';
            }
            else{
                cout << restart_val << '\n';
            }
        }
    }
}
