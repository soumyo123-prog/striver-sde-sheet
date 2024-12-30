#include <bits/stdc++.h>
using namespace std;

struct Node {
  int key;
  struct Node* left;
  struct Node* right;

  Node(int x) {
    key = x;
    left = NULL;
    right = NULL;
  }
};

void findPre(Node* root, Node*& pre, int key) {
  if (root == nullptr) {
    return;
  }

  if (root->key < key) {
    pre = root;
    findPre(root->right, pre, key);
    return;
  }

  findPre(root->left, pre, key);
}

void findSuc(Node* root, Node*& suc, int key) {
  if (root == nullptr) {
    return;
  }

  if (root->key > key) {
    suc = root;
    findSuc(root->left, suc, key);
    return;
  }

  findSuc(root->right, suc, key);
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
  Node* origRoot = root;

  pre = nullptr;
  findPre(root, pre, key);

  suc = nullptr;
  findSuc(origRoot, suc, key);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}