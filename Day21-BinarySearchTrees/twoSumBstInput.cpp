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

void inorder(TreeNode *root, vector<int> &nums) {
  if (root == nullptr) {
    return;
  }

  inorder(root->left, nums);
  nums.push_back(root->val);
  inorder(root->right, nums);
}

bool findTarget(TreeNode *root, int k) {
  vector<int> nums;
  inorder(root, nums);

  int x = 0, y = nums.size() - 1;

  if (nums.size() < 2) {
    return false;
  }

  while (x < y && x < nums.size()) {
    while (nums[x] + nums[y] > k && y > x) {
      y--;
    }

    if (y > x && nums[x] + nums[y] == k) {
      return true;
    }

    x++;
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}