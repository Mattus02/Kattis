// Problem: https://open.kattis.com/problems/10kindsofpeople

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int rows, columns, indices;
    cin >> rows >> columns;
    indices = rows*columns;

    vector<int> map (indices);

    char c;
    int index;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            cin >> c;
            map[i*columns + j] = c - '0';
        }
    }

    vector<int> groups (indices);
    int num, left, right, up, down;
    int groupNumber = 1;

    for (int i = 0; i < indices; ++i)
    {
        if (!groups[i])
        {
            queue<int> q;
            q.push(i);

            while (!q.empty())
            {
                index = q.front();
                q.pop();
                if (!groups[index])
                {
                    num = map[index];
                    left = index-1;
                    right = index+1;
                    up = index-columns;
                    down = index+columns;

                    if (left > 0 and !groups[left] and map[left] == num and (left % columns != columns-1))
                        q.push(left);
                    if (right < indices and !groups[right] and map[right] == num and (right % columns != 0))
                        q.push(right);
                    if (up > 0 and !groups[up] and map[up] == num)
                        q.push(up);
                    if (down < indices and !groups[down] and map[down] == num)
                        q.push(down);

                    groups[index] = groupNumber;
                }
            }
            ++groupNumber;
        }
    }

    int queries;
    cin >> queries;
    int r1, c1, r2, c2;
    int index1, index2;

    while (queries--)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        index1 = (r1-1)*columns+c1-1;
        index2 = (r2-1)*columns+c2-1;

        if (groups[index1] == groups[index2])
        {
            if (map[index1] == 1)
            {
                cout << "decimal\n";
            }
            else
            {
                cout << "binary\n";
            }
        }
        else
        {
            cout << "neither\n";
        }
    }
}