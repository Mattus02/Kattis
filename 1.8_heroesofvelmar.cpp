// Problem: https://open.kattis.com/problems/heroesofvelmar

#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> card_power = {{"Shadow",6}, {"Gale",5}, {"Ranger",4}, {"Anvil",7}, {"Vexia",3},
                                         {"Guardian",8}, {"Thunderheart",6}, {"Frostwhisper",2},
                                         {"Voidclaw",3}, {"Ironwood",3}, {"Zenith",4}, {"Seraphina",1}};

int EvaluateOnePlayer(string& line, bool is_center)
{
    stringstream ss{line};
    int cards;
    ss >> cards;

    int sum = 0;
    string token;
    while (ss >> token)
    {
        if (token == "Thunderheart" && cards >= 4)
        {
            sum += 12;
        }
        else if (token == "Zenith" && is_center)
        {
            sum += 9;
        }
        else
        {
            sum += card_power[token];
        }
        if (token == "Seraphina")
        {
            sum += cards - 1;
        }
    }
    return sum;
}

int main()
{
    int p1_count = 0;
    int p2_count = 0;
    int p1_sum   = 0;
    int p2_sum   = 0;

    for (int i = 0; i < 3; ++i)
    {
        string line1, line2;
        getline(cin, line1);
        getline(cin, line2);
        bool is_center = (i == 1);
        int p1 = EvaluateOnePlayer(line1, is_center);
        int p2 = EvaluateOnePlayer(line2, is_center);
        p1_sum += p1;
        p2_sum += p2;
        if      (p1 > p2) p1_count += 1;
        else if (p1 < p2) p2_count += 1;
    }

    string answer;
    if      (p1_count > p2_count) answer = "Player 1";
    else if (p1_count < p2_count) answer = "Player 2";
    else 
    {
        if      (p1_sum > p2_sum) answer = "Player 1";
        else if (p1_sum < p2_sum) answer = "Player 2";
        else                      answer = "Tie";
    }

    cout << answer << endl;
}