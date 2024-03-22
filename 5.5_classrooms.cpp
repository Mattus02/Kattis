// Problem: https://open.kattis.com/problems/classrooms

#include <iostream> 
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Activity
{
    int start;
    int end;

    bool operator<(Activity const& other)
    {
        return this->end < other.end;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;

    vector<Activity> activities(n);
    for (Activity& a : activities)
        cin >> a.start >> a.end;

    sort(activities.begin(), activities.end()); 

    multiset<int, greater<int>> classrooms;

    int answer = 0;
    for (Activity const& a : activities)
    {
        auto it = classrooms.upper_bound(a.start);
        if (it != classrooms.end())
        {
            classrooms.erase(it);
            classrooms.insert(a.end);
            answer += 1;
        }
        else if (classrooms.size() < k)
        {
            classrooms.insert(a.end);
            answer += 1;
        }
    }

    cout << answer << endl;
}