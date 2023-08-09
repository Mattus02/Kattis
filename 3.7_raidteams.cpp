// Problem: https://open.kattis.com/problems/raidteams

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> names;

struct Player {
    int id;
    int skill;
};

bool operator<(Player a, Player b)
{
    if (a.skill < b.skill) return true;
    if (a.skill > b.skill) return false;

    return !lexicographical_compare(names[a.id].begin(), names[a.id].end(), names[b.id].begin(), names[b.id].end());
}

int main()
{
    int N;
    cin >> N;

    names.resize(N);
    vector<bool> picked(N, false);

    vector<Player> pq_s1(N);
    vector<Player> pq_s2(N);
    vector<Player> pq_s3(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> names[i];

        int s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        cin.ignore();

        pq_s1[i] = {i, s1};
        pq_s2[i] = {i, s2};
        pq_s3[i] = {i, s3};
    }

    sort(begin(pq_s1), end(pq_s1));
    sort(begin(pq_s2), end(pq_s2));
    sort(begin(pq_s3), end(pq_s3));

    int loops = N / 3;
    while (loops--)
    {
        vector<string> output(3);

        while (picked[pq_s1.back().id]) pq_s1.pop_back();
        output[0] = names[pq_s1.back().id];
        picked[pq_s1.back().id] = true;

        while (picked[pq_s2.back().id]) pq_s2.pop_back();
        output[1] = names[pq_s2.back().id];
        picked[pq_s2.back().id] = true;

        while (picked[pq_s3.back().id]) pq_s3.pop_back();
        output[2] = names[pq_s3.back().id];
        picked[pq_s3.back().id] = true;

        sort(output.begin(), output.end());
        for (string& s : output) cout << s << ' ';
        cout << '\n';
    }
}
