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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (root == nullptr) {
    return nullptr;
  }

  if (root == p || root == q) {
    return root;
  }

  TreeNode* l = lowestCommonAncestor(root->left, p, q);
  TreeNode* r = lowestCommonAncestor(root->right, p, q);

  if (l == nullptr && r == nullptr) {
    return nullptr;
  }

  if (l == nullptr && r != nullptr) {
    return r;
  }

  if (l != nullptr && r == nullptr) {
    return l;
  }

  return root;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}