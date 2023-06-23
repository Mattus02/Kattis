// Problem: https://open.kattis.com/problems/areyoulistening

#include <bits/stdc++.h>

using namespace std;

struct dev {
    int x;
    int y;
    int r;
    float s;
};

float safe_dist(int x, int y, dev& d) {
    return max(0.0f, sqrtf((d.x-x)*(d.x-x)+(d.y-y)*(d.y-y)) - d.r);
}

bool operator<(dev& lhs, dev& rhs) { return lhs.s < rhs.s; }

int main()
{
    int x, y, d;
    cin >> x >> y >> d;
    vector<dev> devs(d);
    
    while(d--) {
        cin >> devs[d].x >> devs[d].y >> devs[d].r;
    }
    for(dev& d : devs) {
        d.s = safe_dist(x, y, d);
    }
    sort(devs.begin(), devs.end());
    cout << (int)devs[2].s;
}
