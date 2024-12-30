#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

void helper(Node* node, int level, vector<Node*>& lev) {
  if (node == nullptr) {
    return;
  }

  if (lev[level] == nullptr) {
    lev[level] = node;
  } else {
    lev[level]->next = node;
    lev[level] = node;
  }

  helper(node->left, level + 1, lev);
  helper(node->right, level + 1, lev);
}

Node* connect(Node* root) {
  if (root == nullptr) {
    return root;
  }

  vector<Node*> lev;

  Node* curr = root;
  while (curr != nullptr) {
    lev.push_back(nullptr);
    curr = curr->left;
  }

  helper(root, 0, lev);

  return root;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}