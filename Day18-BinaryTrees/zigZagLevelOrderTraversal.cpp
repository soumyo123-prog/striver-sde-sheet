#include <bits/stdc++.h>
using namespace std;

// 3
// 9 20
// 15 7

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
  vector<vector<int>> res;

  if (root == nullptr) {
    return res;
  }

  deque<TreeNode*> q;
  q.push_back(root);

  bool lr = false;

  while (!q.empty()) {
    int size = q.size();
    vector<int> curr;
    TreeNode* node;

    if (lr) {
      for (int i = 0; i < size; i++) {
        node = q.front();
        q.pop_front();
        curr.push_back(node->val);

        if (node->left != nullptr) {
          q.push_back(node->left);
        }
        if (node->right != nullptr) {
          q.push_back(node->right);
        }
      }
    } else {
      for (int i = 0; i < size; i++) {
        node = q.back();
        q.pop_back();
        curr.push_back(node->val);

        if (node->right != nullptr) {
          q.push_front(node->right);
        }
        if (node->left != nullptr) {
          q.push_front(node->left);
        }
      }
    }

    res.push_back(curr);
    lr = !lr;
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}