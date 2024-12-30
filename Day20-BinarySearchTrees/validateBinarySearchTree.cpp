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

bool isValidHelper(TreeNode *node, long long lowerBound, long long upperBound) {
  if (node == nullptr) {
    return true;
  }

  if (node->val > lowerBound && node->val < upperBound) {
    return isValidHelper(node->left, lowerBound, node->val) &&
           isValidHelper(node->right, node->val, upperBound);
  }

  return false;
}

bool isValidBST(TreeNode *root) {
  return isValidHelper(root, LLONG_MIN, LLONG_MAX);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}