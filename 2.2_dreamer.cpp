// Problem: https://open.kattis.com/problems/dreamer

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int daysIn[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool IsLeapYear(int year)
{
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

bool IsValidDate(string& date)
{
    int year  = stoi(date.substr(0, 4));
    int month = stoi(date.substr(4, 2));
    int day   = stoi(date.substr(6, 2));

    if (year < 2000)                    return false;
    if (month > 12 || month < 1)        return false;
    if (IsLeapYear(year))               daysIn[2] = 29;
    if (day > daysIn[month] || day < 1) return false;

    return true;
}

void solve()
{
    string line;
    getline(cin, line);
    line.erase(remove(line.begin(), line.end(), ' '), line.end());
    sort(line.begin(), line.end());
    int count = 0;
    string bestDate = "99999999";
    do {
        if (IsValidDate(line)) {
            count += 1;
            if (stoi(line) < stoi(bestDate)) bestDate = line;
        }
        daysIn[2] = 28;
    } while (next_permutation(line.begin(), line.end()));
    
    if (count == 0) {
        cout << 0 << endl;
        return;
    }

    cout << count << ' ' << bestDate.substr(6, 2)
         << ' ' <<  bestDate.substr(4, 2) << ' ' 
         << bestDate.substr(0, 4) << endl;
}


int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--) solve();
}