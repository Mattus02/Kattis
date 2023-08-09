// Problem: https://open.kattis.com/problems/walls

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct crane {
    int x;
    int y;
    string reach;
    crane() : reach{"0000"} {}
};

struct wall {
    double x;
    double y;
};

bool CanReach(crane& c, wall p, int r)
{
    double dx = p.x - (double)c.x;
    double dy = p.y - (double)c.y;
    return (dx*dx + dy*dy <= r*r);
}

void GenerateCombinations(string& s, int idx, string curr, vector<string>& combinations)
{
    if (idx == s.size()) {
        combinations.push_back(curr);
        return;
    }

    GenerateCombinations(s, idx+1, curr+'0', combinations);
    if (s[idx] == '1') GenerateCombinations(s, idx+1, curr+'1', combinations);
}

void InsertKeys(unordered_map<string, bool>& m, string& s)
{
    vector<string> combinations;
    GenerateCombinations(s, 0, "", combinations);
    for (string& c : combinations) m[c] = true;
}

void Next(string& s)
{
    for (int i = 3; i >= 0; --i)
    {
        if (s[i] == '1') s[i] = '0';
        else { 
            s[i] = '1';
            return;
        }
    }
}

string AND(string a, string b)
{
    for (int i = 0; i < 4; ++i)
        if (b[i] == '1')
            a[i] = '1';
    return a;
}

int main()
{
    int l, w, n, r;
    cin >> l >> w >> n >> r;

    wall centers[4] = {{(double)-l/2, 0}, {(double)l/2, 0}, {0, (double)-w/2}, {0, (double)w/2}};

    vector<crane> cranes(n);
    for (crane& c : cranes) cin >> c.x >> c.y;

    unordered_map<string, bool> m;

    for (crane& c : cranes) {
        for (int i = 0; i < 4; ++i)
            if (CanReach(c, centers[i], r))
                c.reach[i] = '1';
        InsertKeys(m, c.reach);
    }

    if (m["1111"]) {
        cout << 1 << endl;
        return 0;
    }

    int best = 5;

    for (string s1 = "0001"; s1 != "1111"; Next(s1))
    {
        if (!m[s1]) continue;

        for (string s2 = "0001"; s2 != "1111"; Next(s2))
        {
            if (!m[s2]) continue;

            string r2 = AND(s1, s2);
            if (r2 == "1111") {
                cout << 2 << endl;
                return 0;
            }

            for (string s3 = "0001"; s3 != "1111"; Next(s3))
            {
                if (!m[s3]) continue;

                string r3 = AND(r2, s3);
                if (r3 == "1111") best = min(best, 3);

                for (string s4 = "0001"; s4 != "1111"; Next(s4))
                {
                    if (!m[s4]) continue;

                    string r4 = AND(r3, s4);
                    if (r4 == "1111") best = min(best, 4);
                }
            }
        }
    }

    if (best > 4) cout << "Impossible" << endl;
    else cout << best << endl;
}