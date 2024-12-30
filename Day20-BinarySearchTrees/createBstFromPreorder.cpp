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

TreeNode *bstHelper(int &idx, vector<int> &preorder, int ub) {
  if (idx == preorder.size() || preorder[idx] > ub) {
    return nullptr;
  }

  TreeNode *root = new TreeNode(preorder[idx]);
  idx++;

  root->left = bstHelper(idx, preorder, root->val);
  root->right = bstHelper(idx, preorder, ub);

  return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder) {
  int idx = 0;
  return bstHelper(idx, preorder, INT_MAX);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}