// Problem: https://open.kattis.com/problems/cuttingcorners

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct corner {
    int id;
    int x;
    int y;
    int dead;
    float angle;
    corner() : dead{0} {}
};

bool operator<(corner const& a, corner const& b) { return a.angle > b.angle; }

struct ivec2 {
    int x;
    int y;
};

float len(ivec2 v) { return sqrtf(v.x*v.x + v.y*v.y); }

void GetNeighbours(vector<corner>& corners, int idx, corner* n)
{
    int r = idx-1;
    int l = idx+1;

    for (;;)
    {
        if (l == corners.size())
            l = 0;
        if (corners[l].dead)
            l += 1;
        else
            break;
    }

    for (;;)
    {
        if (r == -1)
            r = corners.size()-1;
        if (corners[r].dead)
            r -= 1;
        else
            break;
    }

    n[0] = corners[l];
    n[1] = corners[r];
}

float angle(corner& left, corner& mid, corner& right)
{
    ivec2 v0 = {left.x - mid.x, left.y - mid.y};
    ivec2 v1 = {right.x - mid.x, right.y - mid.y};

    return acosf((float)(v0.x*v1.x + v0.y*v1.y)/(len(v0)*len(v1)));
}

float CalcAngle(vector<corner>& corners, int idx)
{
    corner& c = corners[idx];
    corner n[2];
    GetNeighbours(corners, idx, n);

    return angle(n[0], c, n[1]);
}

bool RemoveCorner(vector<corner>& corners, priority_queue<corner>& pq)
{
    corner c = pq.top();
    float currAngle = c.angle;

    corner n[2];
    GetNeighbours(corners, c.id, n);

    float neighbourAngles[2] = {corners[n[0].id].angle, corners[n[1].id].angle};

    float newAngles[2] = {neighbourAngles[0] - angle(n[1], n[0], c), 
                          neighbourAngles[1] - angle(c, n[1], n[0])};
    
    if (newAngles[0] < currAngle || newAngles[1] < currAngle)
        return false;

    corners[c.id].dead = 1;
    corners[n[0].id].angle = newAngles[0];
    corners[n[1].id].angle = newAngles[1];
    pq.pop();
    pq.push(corners[n[0].id]);
    pq.push(corners[n[1].id]);
    return true;
}

int main()
{
    for (;;)
    {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<corner> corners(n);
        for (int i = 0; i < n; ++i)
        {
            corner& c = corners[i];
            c.id = i;
            cin >> c.x >> c.y;
        } 

        priority_queue<corner> pq;
        for (int i = 0; i < n; ++i)
        {
            corners[i].angle = CalcAngle(corners, i);
            pq.push(corners[i]);
        }

        int cornerCount = n;
        while (cornerCount > 3 && RemoveCorner(corners, pq))
            cornerCount -= 1;

        cout << cornerCount << ' ';
        for (corner& c : corners)
            if (!c.dead)
                cout << c.x << ' ' << c.y << ' ';
        cout << endl;
    }
    
}