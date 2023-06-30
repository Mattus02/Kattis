// Problem: https://open.kattis.com/problems/simplearithmetic

#include <iostream>

using namespace std;
typedef unsigned long long ull;

int main()
{
    ull a,b,c;
    cin >> a >> b >> c;
    if(b%c == 0){
        cout << a*b/c;
    }
    else{
        ull x = b/c;
        ull y = b%c;
        ull res1 = a*x;
        double res2 = (double)(a*y)/c;
        double decimal = res2 - (int)res2;
        cout << res1 + (ull)res2 << '.' << to_string(decimal).substr(2) <<  endl;
    }
}
