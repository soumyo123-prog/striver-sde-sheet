#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* left;
  struct Node* right;

  Node(int x) {
    data = x;
    left = right = NULL;
  }
};

vector<int> leftView(Node* root) {
  vector<int> lv;

  if (root == nullptr) {
    return lv;
  }

  queue<Node*> level;
  level.push(root);

  while (!level.empty()) {
    Node* node = level.front();
    lv.push_back(node->data);

    int size = level.size();
    for (int i = 0; i < size; i++) {
      node = level.front();
      level.pop();
      if (node->left != nullptr) {
        level.push(node->left);
      }
      if (node->right != nullptr) {
        level.push(node->right);
      }
    }
  }

  return lv;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}