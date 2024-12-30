#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (root->val < p->val) {
    return lca(root->right, p, q);
  }

  if (root->val > q->val) {
    return lca(root->left, p, q);
  }

  return root;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (p->val > q->val) {
    swap(p, q);
  }

  return lca(root, p, q);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}