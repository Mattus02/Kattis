// Problem: https://open.kattis.com/problems/fruitbaskets

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> fruits;

long long GetInvalidBaskets(int idx, int weight)
{
    if (idx >= fruits.size() || weight + fruits[idx] >= 200)
        return 0;

    return weight + fruits[idx] + GetInvalidBaskets(idx + 1, weight) + GetInvalidBaskets(idx + 1, weight + fruits[idx]);
}

long long TwoPow(int pow)
{
    long long result = 1;
    while (pow--)
        result *= 2;

    return result;
}

int main()
{
    int N;
    cin >> N;
    fruits.resize(N);
    for (int& fruit : fruits)
        cin >> fruit;

    sort(fruits.begin(), fruits.end());

    long long totalWeight = 0;

    totalWeight -= GetInvalidBaskets(0, 0);

    long long combinations = TwoPow(N - 1);

    for (int fruit : fruits)
        totalWeight += fruit * combinations;

    cout << totalWeight << endl;
}