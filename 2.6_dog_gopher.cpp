// Problem: https://open.kattis.com/problems/doggopher

#include <bits/stdc++.h>

using namespace std;

int main()
{
    double gx,gy,dx,dy,x,y;
    cin >> gx >> gy >> dx >> dy;
    while(cin >> x >> y){
        if(sqrt((x-dx)*(x-dx)+(y-dy)*(y-dy)) >= 2*sqrt((x-gx)*(x-gx)+(y-gy)*(y-gy))){
            cout << "The gopher can escape through the hole at ("
                 << fixed << setprecision(3) << x << ',' << y << ").";
            return 0;
        }
    }
    cout << "The gopher cannot escape.";
}
