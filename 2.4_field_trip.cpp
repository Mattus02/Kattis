// Problem: https://open.kattis.com/problems/fieldtrip

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> sections(n);
    int student_sum = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> sections[i];
        student_sum += sections[i];
    }
    if(student_sum % 3 != 0)
    {
        cout << -1;
        return 0;
    }
    else
    {
        int target = student_sum / 3;
        int count = 0;
        int answer[2];
        int a_idx = 0;
        for(int i = 0; i < n; ++i)
        {
            count += sections[i];
            if(count == target)
            {
                answer[a_idx] = i+1;
                if(a_idx == 1)
                {
                    break;
                }
                ++a_idx;
                count = 0;
            }
            else if(count > target)
            {
                cout << -1;
                return 0;
            }
        }
        cout << answer[0] << ' ' << answer[1];
    }
}
