#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void flatten(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  TreeNode *curr = root;
  while (curr != nullptr) {
    if (curr->left == nullptr) {
      curr = curr->right;
      continue;
    }

    TreeNode *tmp = curr->left;
    while (tmp->right != nullptr) {
      tmp = tmp->right;
    }

    tmp->right = curr->right;
    curr->right = curr->left;
    curr->left = nullptr;

    curr = curr->right;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}