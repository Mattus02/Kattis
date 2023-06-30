// Problem: https://open.kattis.com/problems/sjecista

#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    int end = N-3;
    int res = 0;
    int mult = 1;
    for(int i = 0; i < N-3; ++i)
    {
        res += mult*end*(end+1)/2;
        ++mult;
        --end;
    }
    std::cout << res;
}
