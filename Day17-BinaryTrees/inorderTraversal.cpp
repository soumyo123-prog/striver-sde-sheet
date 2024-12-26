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

void it(TreeNode *node, vector<int> &nodes) {
  if (node == nullptr) {
    return;
  }

  it(node->left, nodes);
  nodes.push_back(node->val);
  it(node->right, nodes);
}

vector<int> inorderTraversal(TreeNode *root) {
  vector<int> nodes;
  it(root, nodes);
  return nodes;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}
