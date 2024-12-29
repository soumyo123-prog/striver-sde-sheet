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

TreeNode *btHelper(vector<int> &postorder, vector<int> &inorder, int &postIdx,
                   int inStart, int inEnd, unordered_map<int, int> &inMap) {
  if (postIdx < 0) {
    return nullptr;
  }

  if (inStart > inEnd) {
    return nullptr;
  }

  int rootVal = postorder[postIdx];
  postIdx--;

  TreeNode *root = new TreeNode(rootVal);
  root->right =
      btHelper(postorder, inorder, postIdx, inMap[rootVal] + 1, inEnd, inMap);
  root->left =
      btHelper(postorder, inorder, postIdx, inStart, inMap[rootVal] - 1, inMap);

  return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
  unordered_map<int, int> inMap;
  for (int i = 0; i < inorder.size(); i++) {
    inMap[inorder[i]] = i;
  }

  int postIdx = postorder.size() - 1;
  return btHelper(postorder, inorder, postIdx, 0, inorder.size() - 1, inMap);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}