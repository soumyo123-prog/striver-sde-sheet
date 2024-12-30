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

TreeNode *makeBst(int start, int end, vector<int> &nums) {
  if (start > end) {
    return nullptr;
  }

  int mid = start + (end - start) / 2;

  TreeNode *root = new TreeNode(nums[mid]);
  root->left = makeBst(start, mid - 1, nums);
  root->right = makeBst(mid + 1, end, nums);

  return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums) {
  return makeBst(0, nums.size() - 1, nums);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}