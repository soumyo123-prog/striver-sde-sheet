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

  stack<TreeNode *> st;
  st.push(root);

  while (!st.empty()) {
    TreeNode *node = st.top();
    st.pop();
    nodes.push_back(node->val);
    if (node->right != nullptr) st.push(node->right);
    if (node->left != nullptr) st.push(node->left);
  }

  return nodes;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}