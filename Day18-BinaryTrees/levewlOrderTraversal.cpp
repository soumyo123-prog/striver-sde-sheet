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

vector<vector<int>> levelOrder(TreeNode *root) {
  vector<vector<int>> result;

  if (root == nullptr) {
    return result;
  }

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    vector<int> curr;
    int size = q.size();
    for (int i = 0; i < size; i++) {
      TreeNode *node = q.front();
      q.pop();
      curr.push_back(node->val);
      if (node->left != nullptr) {
        q.push(node->left);
      }
      if (node->right != nullptr) {
        q.push(node->right);
      }
    }
    result.push_back(curr);
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}