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

int findHeight(TreeNode *node, bool &hb) {
  if (!hb) {
    return 0;
  }

  if (node == nullptr) {
    return 0;
  }

  int lh = findHeight(node->left, hb);
  int rh = findHeight(node->right, hb);

  if (abs(lh - rh) >= 2) {
    hb = false;
    return 0;
  }

  return 1 + max(lh, rh);
}

bool isBalanced(TreeNode *root) {
  bool hb = true;
  findHeight(root, hb);

  return hb;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}