#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
 public:
  T val;
  TreeNode<T> *left;
  TreeNode<T> *right;

  TreeNode(T val) {
    this->val = val;
    left = NULL;
    right = NULL;
  }
};

void findFloor(TreeNode<int> *node, int x, int &floor) {
  if (node == nullptr) {
    return;
  }

  if (node->val == x) {
    floor = x;
    return;
  }

  if (node->val > x) {
    findFloor(node->left, x, floor);
    return;
  }

  floor = node->val;
  findFloor(node->right, x, floor);
}

int floorInBST(TreeNode<int> *root, int x) {
  int floor;
  findFloor(root, x, floor);

  return floor;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}