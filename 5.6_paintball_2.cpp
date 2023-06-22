// Problem: https://open.kattis.com/problems/paintball2

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <math.h>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Enemy
{
    int x;
    int y;
    int r;
    bool investigated;
    bool crossLeft;
    bool crossRight;
    bool crossDown;
    bool crossUp;
};

bool intersection(const Enemy& e1, const Enemy& e2)
{
    double distance = sqrt(pow((e1.x - e2.x),2) + pow((e1.y - e2.y),2));
    return (distance < (double)(e1.r + e2.r));
}

bool outsideBounds(Enemy& enemy)
{
    int x = enemy.x;
    int y = enemy.y;
    int r = enemy.r;
    if ((x - r) < 0)
        enemy.crossLeft = true;
    if ((x + r) > 1000)
        enemy.crossRight = true;
    if ((y - r) < 0)
        enemy.crossDown = true;
    if ((y + r) > 1000)
        enemy.crossUp = true;
    return (enemy.crossLeft or enemy.crossRight or enemy.crossDown or enemy.crossUp);
}

vector<Enemy*> findChain(Enemy& startingEnemy, vector<Enemy>& enemies)
{
    vector<Enemy*> chain;
    chain.push_back(&startingEnemy);
    queue<Enemy*> q;
    q.push(&startingEnemy);

    while (!q.empty())
    {
        Enemy* curr = q.front();
        curr->investigated = true;
        q.pop();

        for (Enemy& enemy : enemies)
        {
            if (!enemy.investigated and intersection(*curr, enemy))
            {
                if (outsideBounds(enemy))
                {
                    chain.push_back(&enemy);
                }
                q.push(&enemy);
                enemy.investigated = true;
            }
        }
    }
    return chain;
}

void calcIntersectLeft(Enemy* enemy, vector<double>& yLeftIntersects)
{
    double expression = sqrt(pow(enemy->r, 2) - pow(enemy->x, 2));
    double y1 = (double)enemy->y - expression;
    double y2 = (double)enemy->y + expression;
    if (abs(y1) <= 1000.0)
        yLeftIntersects.push_back(y1);
    if (abs(y2) <= 1000.0)
        yLeftIntersects.push_back(y2);
}

void calcIntersectRight(Enemy* enemy, vector<double>& yRightIntersects)
{
    double expression = sqrt(pow(enemy->r, 2) - pow((1000 - enemy->x), 2));
    double y1 = (double)enemy->y - expression;
    double y2 = (double)enemy->y + expression;
    if (abs(y1) <= 1000.0)
        yRightIntersects.push_back(y1);
    if (abs(y2) <= 1000.0)
        yRightIntersects.push_back(y2);
}

pair<double, double> checkPossibilities(const vector<Enemy*>& chain)
{
    double startPoint = 1000.0;
    double endPoint = 1000.0;
    vector<double> yLeftIntersects;
    vector<double> yRightIntersects;
    bool leftIntersect = false;
    bool rightIntersect = false;
    bool downIntersect = false;
    bool upIntersect = false;

    for (Enemy* enemy : chain)
    {
        if (enemy->crossLeft)
        {
            calcIntersectLeft(enemy, yLeftIntersects);
            leftIntersect = true;
        }
        if (enemy->crossRight)
        {
            calcIntersectRight(enemy, yRightIntersects);
            rightIntersect = true;
        }
        if (enemy->crossDown)
        {
            downIntersect = true;
        }
        if (enemy->crossUp)
        {
            upIntersect = true;
        }
    }

    if (upIntersect and downIntersect)
    {
        startPoint = -1.0;
        endPoint = -1.0;
    }
    else
    {
        if (leftIntersect)
        {
            if (upIntersect)
                startPoint = *min_element(yLeftIntersects.begin(), yLeftIntersects.end());
        }
        if (rightIntersect)
        {
            if (upIntersect)
                endPoint = *min_element(yRightIntersects.begin(), yRightIntersects.end());
        }
    }

    return pair<double, double> {startPoint, endPoint};
}

int main()
{
    int numOfEnemies;
    cin >> numOfEnemies;

    vector<Enemy> enemies (numOfEnemies);

    for (auto& enemy : enemies)
    {
        cin >> enemy.x
            >> enemy.y
            >> enemy.r;
        enemy.investigated = false;
        enemy.crossLeft = false;
        enemy.crossRight = false;
        enemy.crossDown = false;
        enemy.crossUp = false;
    }

    bool possible = true;
    vector<vector<Enemy*>> allChains;

    // Register all boundary-crossing enemies that are connected somehow
    for (Enemy& enemy : enemies)
    {
        if (outsideBounds(enemy) and !enemy.investigated)
        {
            allChains.push_back(findChain(enemy, enemies));
        }
    }

    pair<double, double> possibilities {1000.0, 1000.0};
    pair<double, double> tmpPossibilities;
    for (vector<Enemy*>& chain : allChains)
    {
        tmpPossibilities = checkPossibilities(chain);
        if (tmpPossibilities.first < possibilities.first)
            possibilities.first = tmpPossibilities.first;
        if (tmpPossibilities.second < possibilities.second)
            possibilities.second = tmpPossibilities.second;
    }

    if (possibilities.first == -1.0)
        cout << "IMPOSSIBLE";
    else
        cout << fixed << setprecision(2) << "0.00 " << possibilities.first << " 1000.00 " << possibilities.second << endl;

}