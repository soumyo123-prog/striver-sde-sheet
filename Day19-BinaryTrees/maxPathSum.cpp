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

int findMax(TreeNode *node, int &mps) {
  if (node == nullptr) {
    return 0;
  }

  int leftSum = findMax(node->left, mps);
  int rightSum = findMax(node->right, mps);

  mps = max(mps, node->val + leftSum + rightSum);

  return max(0, node->val + max(leftSum, rightSum));
}

int maxPathSum(TreeNode *root) {
  int mps = root->val;
  findMax(root, mps);

  return mps;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}