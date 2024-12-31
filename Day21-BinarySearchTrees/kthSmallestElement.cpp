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

void inorder(TreeNode *root, int &pos, int k, int &res) {
  if (root == nullptr) {
    return;
  }

  inorder(root->left, pos, k, res);

  pos++;
  if (pos == k) {
    res = root->val;
    return;
  }

  inorder(root->right, pos, k, res);
}

int kthSmallest(TreeNode *root, int k) {
  int pos = 0, res;
  inorder(root, pos, k, res);

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}