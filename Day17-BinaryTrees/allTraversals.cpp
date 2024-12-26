#include <bits/stdc++.h>
using namespace std;

class TreeNode {
 public:
  int data;
  TreeNode *left, *right;
  TreeNode() : data(0), left(NULL), right(NULL) {}
  TreeNode(int x) : data(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : data(x), left(left), right(right) {}
};

vector<vector<int>> getTreeTraversal(TreeNode *root) {
  vector<int> preorder, inorder, postorder;

  stack<pair<TreeNode *, int>> st;
  st.push({root, 1});

  while (!st.empty()) {
    TreeNode *node = st.top().first;
    int num = st.top().second;
    st.pop();

    if (num == 1) {
      preorder.push_back(node->data);
      num++;
      st.push({node, num});

      if (node->left != nullptr) {
        st.push({node->left, 1});
      }
    } else if (num == 2) {
      inorder.push_back(node->data);
      num++;
      st.push({node, num});

      if (node->right != nullptr) {
        st.push({node->right, 1});
      }
    } else {
      postorder.push_back(node->data);
    }
  }

  return {inorder, preorder, postorder};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}