// Problem: https://open.kattis.com/problems/tight

#include <bits/stdc++.h>

using namespace std;

int K, N;
vector<vector<double>> mem;

double count(int n, int i)
{
    if(i < 0 or i > K)
        return 0;
    if(n == N-1)
        return 1;
    if(mem[n][i] == -1)
        mem[n][i] = count(n+1, i-1) + count(n+1, i) + count(n+1, i+1);
    return mem[n][i];
}

double first()
{
    double sum = 0;
    for(int i = 0; i <= K; ++i)
        sum += count(0, i);
    return sum;
}

int main()
{
    while(cin >> K >> N){
        mem = vector<vector<double>>(N, vector<double>(K+1,-1));
        cout << fixed << setprecision(9) << 100*first()/pow(K+1,N) << '\n';
    }
}
