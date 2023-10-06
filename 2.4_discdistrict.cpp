// Problem: https://open.kattis.com/problems/discdistrict

#include <iostream>

typedef unsigned long long u64;

int main()
{
    u64 r;
    std::cin >> r;
    u64 rs = r*r;

    u64 x{r}, y{1};
    u64 sol_x, sol_y;

    u64 bestDist = UINT64_MAX;
    while (x != 0)
    {
        if ((x-1)*(x-1) + y*y > rs)
        {
            x -= 1;
        }
        if (x*x + y*y < bestDist)
        {
            sol_x = x;
            sol_y = y;
            bestDist = x*x + y*y;
        }
        y += 1;
    }

    std::cout << sol_x << ' ' << sol_y << std::endl;
}