// Problem: https://open.kattis.com/problems/phonelist

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    vector<Node*> children;
    bool hasChildren;
    Node() : children(10, nullptr), hasChildren{false} {}
};

void DestroyTree(Node* rootNode) {

    for (Node* child : rootNode->children) if (child) DestroyTree(child);
    delete rootNode;
}

void Solve(vector<string>& allNumbers) {

    Node* rootNode = new Node;

    for (string& telNr : allNumbers) {
        Node* currNode = rootNode;
        for (char c : telNr) {
            int digit = c - '0';
            if (currNode->children[digit] == nullptr) {
                currNode->children[digit] = new Node;
                currNode->hasChildren = true;
            }
            currNode = currNode->children[digit];
        }
        if (currNode->hasChildren) {
            cout << "NO" << endl;
            DestroyTree(rootNode);
            return;
        }
    }
    cout << "YES" << endl;
    DestroyTree(rootNode);
}

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        cin.ignore();

        string Nr;
        vector<string> allNumbers;

        while (n--) {
            getline(cin, Nr);
            allNumbers.push_back(Nr);           
        }

        sort(begin(allNumbers), end(allNumbers), [](string& a, string& b) { return a.size() > b.size(); });
        Solve(allNumbers);
    }
}