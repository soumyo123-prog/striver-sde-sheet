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

void maxDepthHelper(TreeNode *root, int level, int &maxLevel) {
  if (root->left == nullptr && root->right == nullptr) {
    maxLevel = max(level, maxLevel);
    return;
  }

  if (root->left != nullptr) {
    maxDepthHelper(root->left, level + 1, maxLevel);
  }

  if (root->right != nullptr) {
    maxDepthHelper(root->right, level + 1, maxLevel);
  }
}

int maxDepth(TreeNode *root) {
  int res = 0;

  if (root == nullptr) {
    return res;
  }

  maxDepthHelper(root, 1, res);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}