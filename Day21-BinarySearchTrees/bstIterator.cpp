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

class BSTIterator {
  stack<TreeNode *> nodes;

 public:
  BSTIterator(TreeNode *root) {
    while (root != nullptr) {
      nodes.push(root);
      root = root->left;
    }
  }

  int next() {
    TreeNode *top = nodes.top();
    nodes.pop();

    int res = top->val;

    top = top->right;
    while (top != nullptr) {
      nodes.push(top);
      top = top->left;
    }

    return res;
  }

  bool hasNext() { return !nodes.empty(); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}