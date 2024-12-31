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

pair<bool, vector<int>> helper(TreeNode *root, int &maxSum) {
  if (root == nullptr) {
    return {true, {0, INT_MIN, INT_MAX}};
  }

  pair<bool, vector<int>> left = helper(root->left, maxSum);
  pair<bool, vector<int>> right = helper(root->right, maxSum);

  if (left.first && right.first && root->val > left.second[1] &&
      root->val < right.second[2]) {
    maxSum = max(maxSum, left.second[0] + right.second[0] + root->val);
    return {true,
            {left.second[0] + right.second[0] + root->val,
             max(root->val, max(left.second[1], right.second[1])),
             min(root->val, min(right.second[2], left.second[2]))}};
  }

  return {false, {-1, INT_MIN, INT_MAX}};
}

int maxSumBST(TreeNode *root) {
  int maxSum = 0;
  helper(root, maxSum);
  return maxSum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}