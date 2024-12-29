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

TreeNode *btHelper(vector<int> &preorder, int &idx, vector<int> &inorder,
                   int left, int right, unordered_map<int, int> &mp) {
  if (idx >= preorder.size()) {
    return nullptr;
  }

  if (left > right) {
    return nullptr;
  }

  int rootVal = preorder[idx];
  idx++;

  TreeNode *root = new TreeNode(rootVal);
  root->left = btHelper(preorder, idx, inorder, left, mp[rootVal] - 1, mp);
  root->right = btHelper(preorder, idx, inorder, mp[rootVal] + 1, right, mp);

  return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
  unordered_map<int, int> mp;
  for (int i = 0; i < inorder.size(); i++) {
    mp[inorder[i]] = i;
  }

  int idx = 0;
  return btHelper(preorder, idx, inorder, 0, inorder.size() - 1, mp);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}