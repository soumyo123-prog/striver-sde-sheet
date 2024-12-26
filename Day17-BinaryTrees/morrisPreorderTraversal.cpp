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

vector<int> preorderTraversal(TreeNode *root) {
  vector<int> nodes;
  if (root == nullptr) {
    return nodes;
  }

  TreeNode *curr = root;
  while (curr != nullptr) {
    if (curr->left == nullptr) {
      nodes.push_back(curr->val);
      curr = curr->right;
      continue;
    }

    TreeNode *tmp = curr->left;
    while (tmp->right != nullptr && tmp->right != curr) {
      tmp = tmp->right;
    }

    if (tmp->right == nullptr) {
      nodes.push_back(curr->val);
      tmp->right = curr;
      curr = curr->left;
    } else {
      tmp->right = nullptr;
      curr = curr->right;
    }
  }

  return nodes;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}