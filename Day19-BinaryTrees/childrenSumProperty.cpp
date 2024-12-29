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

int isSumProperty(Node* root) {
  if (root->left == nullptr && root->right == nullptr) {
    return 1;
  }

  int lv = root->left == nullptr ? 0 : root->left->data;
  int rv = root->right == nullptr ? 0 : root->right->data;

  if (root->data != lv + rv) {
    return 0;
  }

  int right = 1, left = 1;
  if (root->left != nullptr) {
    left = isSumProperty(root->left);
  }
  if (root->right != nullptr) {
    right = isSumProperty(root->right);
  }

  return right & left;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}