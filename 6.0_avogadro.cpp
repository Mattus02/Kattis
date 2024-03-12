// Problem: https://open.kattis.com/problems/avogadro

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> counts;
vector<vector<int>> rows;
int N;
int deleteCount = 0;

void DeleteColumn(int column)
{
    for (int i = 0; i < 3; ++i)
    {
        int val = rows[i][column];
        counts[i][val] -= 1;
    }
    ++deleteCount;
}

void DeleteColumns()
{
    vector<int> columnOf(N+1);
    for (int i = 0; i < N; ++i)
        columnOf[rows[0][i]] = i;

    vector<int> deletedFromFirst;
    vector<int> deletedFromSecond;

    for (int i = 0; i < N; ++i)
    {
        int val = rows[0][i];
        if (counts[1][val] == 0 || counts[2][val] == 0)
        {
            DeleteColumn(i);
            deletedFromFirst.push_back(rows[1][i]);
            deletedFromSecond.push_back(rows[2][i]);
        }
    }

    while (!deletedFromFirst.empty() || !deletedFromSecond.empty())
    {
        int val;
        if (!deletedFromFirst.empty())
        {
            val = deletedFromFirst.back();
            deletedFromFirst.pop_back();
        }
        else
        {
            val = deletedFromSecond.back();
            deletedFromSecond.pop_back();
        }
        if (counts[0][val] == 1 && (counts[1][val] == 0 || counts[2][val] == 0))
        {
            int col = columnOf[val];
            DeleteColumn(col);
            deletedFromFirst.push_back(rows[1][col]);
            deletedFromSecond.push_back(rows[2][col]);
        }
    }
}

int main()
{
    cin >> N;

    counts = vector<vector<int>>(3, vector<int>(N + 1, 0));
    rows = vector<vector<int>>(3, vector<int>(N));

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int val;
            cin >> val;
            rows[i][j] = val;
            counts[i][val] += 1;
        }
    }

    DeleteColumns();

    cout << deleteCount << endl;
}