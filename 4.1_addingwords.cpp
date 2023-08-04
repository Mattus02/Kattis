// Problem: https://open.kattis.com/problems/addingwords

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

void ReadDefinition(istringstream& iss, unordered_map<string,int>& definitions, unordered_map<int,string>& words);
void Calculate(istringstream& iss, unordered_map<string,int>& definitions, unordered_map<int,string>& words);

int main()
{
    unordered_map<string,int> definitions;
    unordered_map<int,string> words;
    
    string command;
    while (cin >> command)
    {
        if (command[1] == 'l')
        {
            definitions.clear();
            words.clear();
            continue;
        }

        string line;
        getline(cin, line);
        istringstream iss(line);
        
        if (command[0] == 'd') ReadDefinition(iss, definitions, words);
        else                   Calculate(iss, definitions, words);
    }
}


void ReadDefinition(istringstream& iss, unordered_map<string,int>& definitions, unordered_map<int,string>& words)
{
    string word;
    int value;
    iss >> word >> value;
    if (definitions.find(word) != definitions.end())
    {
        int oldValue = definitions[word];
        words.erase(oldValue);
    }
    definitions[word] = value;
    words[value] = word;
}


void Calculate(istringstream& iss, unordered_map<string,int>& definitions, unordered_map<int,string>& words)
{
    vector<string> tokens;
    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));

    int sum = 0;
    bool add = true;
    bool error = false;
    for (int i = 0; i < tokens.size(); i += 2)
    {
        if (definitions.find(tokens[i]) == definitions.end())
        {
            error = true;
            break;
        }
        int value = definitions[tokens[i]];
        if (!add) value *= -1;
        sum += value;

        if (tokens[i+1] == "+") add = true;
        else                    add = false;
    }

    if (words.find(sum) == words.end()) error = true;

    for (string& token : tokens) cout << token << ' ';
    if (error) cout << "unknown\n";
    else       cout << words[sum] << '\n';
}