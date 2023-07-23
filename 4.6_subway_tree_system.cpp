// Problem: https://open.kattis.com/problems/subway

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

struct Node {
  Node* parent;
  vector<Node*> children;
};

void ConstructTree(Node*& subwayTree, string& input) {

  subwayTree = new Node {nullptr, {}};
  Node* currentNode = subwayTree;

  for (char c : input) {
    if (c == '0') {
      currentNode->children.push_back(new Node {currentNode, {}});
      currentNode = currentNode->children.back();
    } else if (c == '1') {
      currentNode = currentNode->parent;
    }
  }
}

bool AreEqual(Node* tree_1, Node* tree_2) {

  if (tree_1->children.size() != tree_2->children.size()) return false;
  else if (tree_1->children.size() == 0 && tree_2->children.size() == 0) return true;

  vector<bool> explored = vector<bool>(tree_2->children.size(), false);

  for (int i = 0; i < tree_1->children.size(); ++i) {
    bool foundOne = false;
    for (int j = 0; j < tree_1->children.size(); ++j) {
      if (!explored[j]) {
        if (AreEqual(tree_1->children[i], tree_2->children[j])) {
          foundOne = true;
          explored[j] = true;
          break;
        }
      }
    }
    if (!foundOne) return false;
  }
  return true;
}

void DestroyTree(Node* subwayTree) {

  for (Node* node : subwayTree->children) DestroyTree(node);
  delete subwayTree;
}

int main() {

  int tests;
  cin >> tests;
  cin.ignore();

  while (tests--) {

    string input_1;
    string input_2;
    getline(cin, input_1);
    getline(cin, input_2);

    Node* subwayTree_1;
    Node* subwayTree_2;
    ConstructTree(subwayTree_1, input_1);
    ConstructTree(subwayTree_2, input_2);

    if (AreEqual(subwayTree_1, subwayTree_2)) cout << "same\n";
    else cout << "different\n";

    DestroyTree(subwayTree_1);
    DestroyTree(subwayTree_2);
  }
}