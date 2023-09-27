// Problem: https://open.kattis.com/problems/gcpc

#include <bits/stdc++.h>

using namespace std;

struct Event
{
    int team;
    int penalty;
};

struct Score
{
    int solved;
    int penalty;
};

bool operator<(Score a, Score b)
{
    if (a.solved < b.solved) return true;
    if (b.solved < a.solved) return false;
    return a.penalty > b.penalty;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Event> events(m);

    for (Event& e : events)
    {
        cin >> e.team >> e.penalty;
    }

    vector<Score> teams (n+1, {0,0});
    multiset<Score> betterTeams;

    for (Event e : events)
    {
        if (e.team == 1)
        {
            teams[1].solved += 1;
            teams[1].penalty += e.penalty;
            auto it = betterTeams.begin();
            while (it != betterTeams.end() && ((*it).solved < teams[1].solved || ((*it).solved == teams[1].solved && (*it).penalty >= teams[1].penalty)))
            {
                betterTeams.erase(it);
                it = betterTeams.begin();
            }
        }
        else
        {
            Score& curr = teams[e.team];

            auto it = betterTeams.find(curr);
            if (it != betterTeams.end())
            {
                betterTeams.erase(it);
            }

            curr.solved += 1;
            curr.penalty += e.penalty;

            if (curr.solved > teams[1].solved || (curr.solved == teams[1].solved && curr.penalty < teams[1].penalty))
            {
                betterTeams.insert(curr);
            }
        }

        cout << betterTeams.size()+1 << endl;
    }
}